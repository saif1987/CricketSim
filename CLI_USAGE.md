# CLI Usage Guide

The primary way to interact with the game currently is through the `cli` (Command-Line Interface) crate.

## CLI Crate (`cli`)

The `cli` crate serves as the terminal-based frontend. It is responsible for all user interaction, including game setup, managing gameplay progression, and displaying game status and results.

### Startup Modes and Configuration

The `cli` supports multiple ways to initiate and configure a game session:

#### 1. Interactive Mode (Default)

If the application is run without specific configuration arguments, it will default to a fully interactive mode, guiding the user through setup via prompts.

**Example** (assuming `my_project_cli` is your executable name, as defined in `cli/Cargo.toml`):
```bash
./target/debug/my_project_cli
# or for a release build:
# ./target/release/my_project_cli
```

#### 2. Configuration File Mode

The `cli` can accept a command-line argument (e.g., `--config <filepath>` or `--load-config <filepath>`) specifying a path to a configuration file containing predefined answers to setup prompts.

**Example:**
```bash
./target/debug/my_project_cli --config game_setup.txt
```

An example configuration file, say `game_setup.txt` (e.g., in INI format), might look like:
```ini
format=ODI
home_team=Warriors
away_team=Titans
toss_choice=bat # if home_team wins toss
pause_at=wicket
initial_aggression=3
```
*Behavior on Incomplete/Malformed Config:* If the file is missing values, the CLI may prompt for the missing information. Critical errors in the configuration file might cause the application to exit.

#### 3. Direct Command-Line Arguments Mode

Specify game parameters directly when launching the executable.

**Example:**
```bash
./target/debug/my_project_cli --format Test --home-team "Kings XI" --away-team "Knights" --toss-choice bowl --pause-at over
```

#### 4. Help Argument (`--help`, -h)

Displays a help message listing all available command-line arguments and their descriptions, then exits.

**Example:**
```bash
./target/debug/my_project_cli --help
```
```bash
./target/debug/my_project_cli -h
```

#### 5. Order of Precedence for Configuration

1.  **Direct Command-Line Arguments:** Override all other settings.
2.  **Configuration File Values:** Used if not overridden by direct CLI arguments.
3.  **Interactive Prompts/Defaults:** Fallback if not set by the above methods.

### Game Flow

The game flow adapts based on the startup mode and provided configurations.

#### I. Game Initialization and Setup Sequence

1.  **Welcome and Format Selection:**
    *   Determines game format (e.g., "ODI," "Test") from CLI args, config, or interactive prompt. Passed to `core`.

2.  **Team Configuration:**
    *   **Team Names:** Obtained from CLI args, config, or prompts. Managed by `core`.
    *   **Player Roster Generation:** Triggered after names are set. Players randomly generated (by `core`/`sim`).
    *   **Roster Display:** Team rosters are displayed.

3.  **Toss and Decision:**
    *   Coin toss simulated.
    *   Decision to bat/bowl determined from CLI args, config, or prompt. Relayed to `core`.

#### II. Gameplay Configuration

4.  **Simulation Pause Point Definition:**
    *   User defines (or it's pre-configured) simulation pause points:
        *   `Next Over`
        *   `Next Wicket`
        *   `End of Innings`

#### III. Gameplay Loop and Interaction

5.  **Initiate Simulation Segment:**
    *   `cli` prompts to "Start Game" or "Continue to Next Pause Point" (unless fully automated).

6.  **Simulation and Status Update Cycle:**
    *   **Simulation Execution:** `cli` instructs `core`, which invokes `sim` up to the pause point.
    *   **State Management:** `sim` generates outcomes; `core` updates game state.
    *   **Data Preparation:** `dash` formats game status from `core`.
    *   **Terminal Display:** `cli` renders data in a cricket scorecard style.
    *   **Loop Continuation:** Returns to step 5.

### Future CLI Enhancements

*   **Aggressiveness Score Input:**
    *   At each pause point (or configurable at startup), the `cli` will prompt for a batting/bowling aggressiveness score (e.g., 1-5).
    *   This score will influence the `sim` crate's logic via `core`.

### Interactions with Other Crates (CLI Context)

*   **`core` Crate:** Provides game state and responds to simulation requests.
*   **`sim` Crate:** Called by `core` to simulate game events.
*   **`dash` Crate:** Provides formatted data to `cli` for display.