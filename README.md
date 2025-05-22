# My Cricket Simulation Game

**Version:** 1.0.0
**Date:** May 21, 2025

## Table of Contents
- [My Cricket Simulation Game](#my-cricket-simulation-game)
  - [Table of Contents](#table-of-contents)
  - [Project Description](#project-description)
  - [Features](#features)
  - [Prerequisites](#prerequisites)
  - [Building the Project](#building-the-project)
  - [Running the Application](#running-the-application)
  - [Project Structure](#project-structure)
  - [Contributing](#contributing)
  - [License](#license)

## Project Description

My Cricket Simulation Game is a text-based (and future GUI) application that allows users to simulate cricket matches. Users can set up games between two teams, watch the simulation unfold ball-by-ball or over-by-over, and see detailed scorecards and game statistics. The project aims to provide a fun and engaging cricket experience with options for tactical input.
This project is built in Rust and organized into a workspace with several crates, including a core logic library, a simulation engine, a display/dashboard library, a command-line interface (CLI), and a planned graphical user interface (GUI).

For more details on the project's architecture, see [PROJECT_STRUCTURE.md](PROJECT_STRUCTURE.md).

## Features

*   Simulate various cricket match formats (e.g., ODI, Test, T20).
*   Interactive game setup (team names, toss, etc.).
*   Ball-by-ball simulation with detailed commentary (text-based).
*   Dynamic scorecard updates.
*   Pause and resume simulation at various points (e.g., end of over, wicket).
*   (Planned) Tactical aggressiveness input to influence simulation outcomes.
*   (Planned) Graphical User Interface (GUI).

## Prerequisites

*   **Rust:** Ensure you have Rust installed. You can get it from [rustup.rs](https://rustup.rs). This project is developed with Rust 2021 edition or later.
    ```bash
    curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
    ```
*   **Cargo:** Rust's build system and package manager (comes with Rust).

## Building the Project

1.  Clone the repository (if you haven't already):
    ```bash
    git clone <repository-url>
    cd my_project_workspace
    ```
2.  Build the project using Cargo:
    *   For a debug build:
        ```bash
        cargo build
        ```
    *   For a release build (optimized):
        ```bash
        cargo build --release
        ```
    The executables will be placed in the `target/debug/` or `target/release/` directory.

## Running the Application

The primary way to interact with the game currently is through the `cli` (Command-Line Interface) crate.
For detailed instructions on CLI usage, startup modes, and game flow, please see CLI_USAGE.md.

A Graphical User Interface (GUI) is planned for future development.

## Project Structure

This project is organized as a Rust workspace. For a detailed breakdown of the crates and the file tree, please refer to PROJECT_STRUCTURE.md.

## Contributing

We welcome contributions! Please read our CONTRIBUTING.md for more information on how to get started.

## License

This project is dual-licensed under the MIT License and the Apache License 2.0.
Please see the `LICENSE-MIT` and `LICENSE-APACHE` files (you should create these in your project root) for the full text of these licenses.