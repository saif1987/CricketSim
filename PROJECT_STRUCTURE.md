# Project Structure Details

This document provides details on the organization of the My Cricket Simulation Game project.

## Crate Organization

The project is organized as a Rust workspace with the following main crates:

* **`core`**: Contains the fundamental game logic, rules, data structures, and state management.
* **`sim`**: The simulation engine responsible for generating game events and outcomes ball-by-ball.
* **`dash`**: Handles the formatting and preparation of game data for display on various frontends.
* **`cli`**: The command-line interface for interacting with the game.
* **`gui`**: (Planned) A graphical user interface for a more visual experience.
* **(Other utility crates as needed)**

## Possible File Tree

Below is an example of the project's directory structure:

```
my_project_workspace/
├── .git/                     # Git version control (if used)
├── .gitignore                # Specifies intentionally untracked files
├── Cargo.toml                # Root WORKSPACE manifest file
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
```