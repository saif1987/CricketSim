

# My Cricket Simulation Game

**Version:** 0.1.0 (Alpha)
**Date:** May 21, 2025

## Table of Contents

- [My Cricket Simulation Game](#my-cricket-simulation-game)
  - [Table of Contents](#table-of-contents)
  - [Project Description](#project-description)
  - [Features](#features)
  - [Project Structure](#project-structure)
  - [Possible File Tree](#possible-file-tree)
  - [Prerequisites](#prerequisites)
  - [Building the Project](#building-the-project)
  - [Running the Application (CLI)](#running-the-application-cli)
    - [CLI Crate (`cli`)](#cli-crate-cli)
      - [Startup Modes and Configuration](#startup-modes-and-configuration)
        - [1. Interactive Mode (Default)](#1-interactive-mode-default)
- [Assuming 'my\_project\_cli' is the name of your CLI executable defined in cli/Cargo.toml](#assuming-my_project_cli-is-the-name-of-your-cli-executable-defined-in-clicargotoml)
        - [2. Configuration File Mode](#2-configuration-file-mode)
- [Example config.txt content](#example-configtxt-content)
      - [Game Flow](#game-flow)
        - [I. Game Initialization and Setup Sequence](#i-game-initialization-and-setup-sequence)
        - [II. Gameplay Configuration](#ii-gameplay-configuration)
        - [III. Gameplay Loop and Interaction](#iii-gameplay-loop-and-interaction)
      - [Future CLI Enhancements](#future-cli-enhancements)
      - [Interactions with Other Crates (CLI Context)](#interactions-with-other-crates-cli-context)
  - [Contributing](#contributing)
  - [License](#license)

## Project Description

My Cricket Simulation Game is a text-based (and future GUI) application that allows users to simulate cricket matches. Users can set up games between two teams, watch the simulation unfold ball-by-ball or over-by-over, and see detailed scorecards and game statistics. The project aims to provide a fun and engaging cricket experience with options for tactical input.

This project is built in Rust and organized into a workspace with several crates, including a core logic library, a simulation engine, a display/dashboard library, a command-line interface (CLI), and a planned graphical user interface (GUI).

## Features

* Simulate different cricket formats (e.g., ODI, Test).
* User-defined team names.
* Randomly generated player rosters.
* Interactive toss and decision-making.
* Configurable simulation pause points (Next Over, Next Wicket, End of Innings).
* Detailed terminal-based display of scores, stats, and game progress.
* Flexible game setup via:
    * Interactive prompts.
    * Configuration files.
    * Direct command-line arguments.
* (Planned) Tactical aggressiveness input to influence simulation outcomes.
* (Planned) Graphical User Interface (GUI).

## Project Structure

The project is organized as a Rust workspace with the following main crates:

* **`core`**: Contains the fundamental game logic, rules, data structures, and state management.
* **`sim`**: The simulation engine responsible for generating game events and outcomes ball-by-ball.
* **`dash`**: Handles the formatting and preparation of game data for display on various frontends.
* **`cli`**: The command-line interface for interacting with the game (detailed below).
* **`gui`**: (Planned) A graphical user interface for a more visual experience.
* **(Other utility crates as needed)**

## Possible File Tree

my_project_workspace/
├── .git/                     # Git version control (if used)
├── .gitignore                # Specifies intentionally untracked files
├── Cargo.toml                # << Root WORKSPACE manifest file
├── README.md                 # Project overview, build instructions, etc.
│
├── crates/                   # Optional: A common way to group all local crates
│   │
│   ├── cli/                  # Your main CLI executable crate
│   │   ├── Cargo.toml        # Manifest for the CLI
│   │   └── src/
│   │       ├── main.rs       # Entry point for your CLI
│   │       └── commands/     # Optional: Module for CLI subcommands
│   │           ├── mod.rs
│   │           └── some_command.rs
│   │
│   ├── gui/                  # Your GUI application crate
│   │   ├── Cargo.toml        # Manifest for the GUI
│   │   ├── build.rs          # Optional: For build-time tasks (e.g., GUI resources)
│   │   └── src/
│   │       ├── main.rs       # Entry point for your GUI application
│   │       └── app/          # Optional: Module for GUI components/logic
│   │       │   ├── mod.rs
│   │       │   └── main_window.rs
│   │       └── assets/       # Optional: For GUI assets like icons, images
│   │           └── icon.png
│   │
│   ├── core/                 # Your 'core' library crate (shared logic)
│   │   ├── Cargo.toml
│   │   └── src/
│   │       └── lib.rs        # Public API of your core library
│   │       └── models/       # Example internal module
│   │           ├── mod.rs
│   │           └── data_structures.rs
│   │
│   ├── sim/                  # Your 'sim' library crate (simulation logic)
│   │   ├── Cargo.toml
│   │   └── src/
│   │       └── lib.rs        # Public API of your sim library
│   │       └── engine/       # Example internal module
│   │           ├── mod.rs
│   │           └── physics.rs
│   │
│   ├── dash/                 # Your 'dash' library crate (dashboard/reporting logic)
│   │   ├── Cargo.toml
│   │   └── src/
│   │       └── lib.rs        # Public API of your dash library
│   │       └── widgets/      # Example internal module
│   │           ├── mod.rs
│   │           └── chart_generator.rs
│   │
│   └── shared_utils/         # Optional: Another library for utilities shared across all crates
│       ├── Cargo.toml
│       └── src/
│           └── lib.rs
│
├── target/                   # Shared build directory for the entire workspace (created by Cargo)
│   ├── debug/
│   └── release/
│
└── tests/                    # Workspace-level integration tests (less common, usually per-crate)
    └── some_workspace_test.rs



## Prerequisites

* **Rust:** Ensure you have Rust installed. You can get it from [rustup.rs](https://rustup.rs/). This project is developed with Rust 2021 edition or later.
    ```bash
    curl --proto '=https' --tlsv1.2 -sSf [https://sh.rustup.rs](https://sh.rustup.rs) | sh
    ```
* **Cargo:** Rust's build system and package manager (comes with Rust).

## Building the Project

1.  **Clone the repository (if applicable):**
    ```bash
    # git clone <repository-url>
    # cd <project-directory>
    ```

2.  **Build the project:**
    Navigate to the root directory of the workspace (where the main `Cargo.toml` for the workspace is located).
    * For a development build:
        ```bash
        cargo build
        ```
    * For a release (optimized) build:
        ```bash
        cargo build --release
        ```
    The executables will be placed in the `target/debug/` or `target/release/` directory.

## Running the Application (CLI)

The primary way to interact with the game currently is through the `cli` (Command-Line Interface) crate.

### CLI Crate (`cli`)

The `cli` crate serves as the terminal-based frontend. It is responsible for all user interaction, including game setup, managing gameplay progression, and displaying game status and results.

#### Startup Modes and Configuration

The `cli` supports multiple ways to initiate and configure a game session:

##### 1. Interactive Mode (Default)

If the application is run without specific configuration arguments, it will default to a fully interactive mode, guiding the user through setup via prompts.

**Example:**
```bash
./target/debug/my_project_cli # (or ./target/release/my_project_cli)
# Assuming 'my_project_cli' is the name of your CLI executable defined in cli/Cargo.toml


**Part 2: "2. Configuration File Mode" up to just BEFORE "Game Flow"**

```markdown
##### 2. Configuration File Mode

The `cli` can accept a command-line argument (e.g., `--config <filepath>` or `--load-config <filepath>`) specifying a path to a configuration file containing predefined answers to setup prompts.

**Example:**
```bash
./target/debug/my_project_cli --config game_setup.txt


# Example config.txt content
An example game_setup.txt might look like:

Ini, TOML

format=ODI
home_team=Warriors
away_team=Titans
toss_choice=bat # if home_team wins toss
pause_at=wicket
initial_aggression=3

Behavior on Incomplete/Malformed Config: If the file is missing values, the cli may prompt for them. Critical errors might cause an exit.
3. Direct Command-Line Arguments Mode
Specify game parameters directly when launching the executable.

Example:

./target/debug/my_project_cli --format Test --home-team "Kings XI" --away-team "Knights" --toss-choice bowl --pause-at over

4. Help Argument (--help, -h)
Displays a help message listing all available command-line arguments and their descriptions, then exits.

Example:

Bash

./target/debug/my_project_cli --help
Bash

./target/debug/my_project_cli -h
5. Order of Precedence for Configuration
Direct Command-Line Arguments: Override all other settings.
Configuration File Values: Used if not overridden by direct CLI arguments.
Interactive Prompts/Defaults: Fallback if not set by the above methods.

---

**Part 3: "Game Flow" to the end of the README**

```markdown
#### Game Flow

##### I. Game Initialization and Setup Sequence

(Adapts based on startup mode and provided configurations.)

1.  **Welcome and Format Selection:**
    * Determines game format (e.g., "ODI," "Test") from CLI args, config, or interactive prompt. Passed to `core`.

2.  **Team Configuration:**
    * **Team Names:** Obtained from CLI args, config, or prompts. Managed by `core`.
    * **Player Roster Generation:** Triggered after names are set. Players randomly generated (by `core`/`sim`).
    * **Roster Display:** Team rosters are displayed.

3.  **Toss and Decision:**
    * Coin toss simulated.
    * Decision to bat/bowl determined from CLI args, config, or prompt. Relayed to `core`.

##### II. Gameplay Configuration

4.  **Simulation Pause Point Definition:**
    * User defines (or it's pre-configured) simulation pause points:
        * `Next Over`
        * `Next Wicket`
        * `End of Innings`

##### III. Gameplay Loop and Interaction

5.  **Initiate Simulation Segment:**
    * `cli` prompts to "Start Game" or "Continue to Next Pause Point" (unless fully automated).

6.  **Simulation and Status Update Cycle:**
    * **Simulation Execution:** `cli` instructs `core`, which invokes `sim` up to the pause point.
    * **State Management:** `sim` generates outcomes; `core` updates game state.
    * **Data Preparation:** `dash` formats game status from `core`.
    * **Terminal Display:** `cli` renders data in a cricket scorecard style.
    * **Loop Continuation:** Returns to step 5.

#### Future CLI Enhancements

* **Aggressiveness Score Input:**
    * At each pause point (or configurable at startup), the `cli` will prompt for a batting/bowling aggressiveness score (e.g., 1-5).
    * This score will influence the `sim` crate's logic via `core`.

#### Interactions with Other Crates (CLI Context)

* **`core` Crate:** Provides game state and responds to simulation requests.
* **`sim` Crate:** Called by `core` to simulate game events.
* **`dash` Crate:** Provides formatted data to `cli` for display.

## Contributing

Contributions are welcome! If you'd like to contribute, please follow these steps:
1.  Fork the repository.
2.  Create a new branch (`git checkout -b feature/your-feature-name`).
3.  Make your changes.
4.  Commit your changes (`git commit -am 'Add some feature'`).
5.  Push to the branch (`git push origin feature/your-feature-name`).
6.  Create a new Pull Request.

Please make sure your code adheres to the project's coding standards (e.g., run `cargo fmt` and `cargo clippy`).

## License

This project is licensed under the [MIT License](LICENSE.txt) / [Apache License 2.0](LICENSE-APACHE.txt) (or specify your chosen license). Please see the `LICENSE.txt` (or `LICENSE-MIT` and `LICENSE-APACHE`) file for details.
Please try copying these three parts one after the other into your README.md file. This should hopefully bypass the formatting glitch. I apologize again for the inconvenience.