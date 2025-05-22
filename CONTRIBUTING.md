# Contributing Guidelines

Contributions are welcome! We appreciate your help in making My Cricket Simulation Game better.

If you'd like to contribute, please follow these steps:

1.  **Fork the Repository:**
    Click the "Fork" button at the top right of the project's GitHub page.

2.  **Clone Your Fork:**
    ```bash
    git clone <your-fork-repository-url>
    cd <project-directory>
    ```

3.  **Create a New Branch:**
    Create a descriptive branch name for your feature or bug fix.
    ```bash
    git checkout -b feature/your-feature-name  # For a new feature
    # or
    git checkout -b fix/issue-description    # For a bug fix
    ```

4.  **Make Your Changes:**
    Implement your feature or fix the bug. Ensure your code is clean and well-commented where necessary.

5.  **Format and Lint Your Code:**
    Before committing, please format your code and check for linter warnings:
    ```bash
    cargo fmt
    cargo clippy --all-targets --all-features -- -D warnings
    ```

6.  **Commit Your Changes:**
    Write clear and concise commit messages.
    ```bash
    git add .
    git commit -m "feat: Add some amazing feature"
    # or
    git commit -m "fix: Resolve an issue with X"
    # Follow conventional commit guidelines if applicable
    ```

7.  **Push to Your Branch:**
    ```bash
    git push origin feature/your-feature-name
    ```

8.  **Create a New Pull Request (PR):**
    Go to the original repository on GitHub and click the "New pull request" button. Compare your branch with the main branch of the original repository. Provide a clear description of your changes in the PR.

## Coding Standards

*   Follow Rust's idiomatic style.
*   Use `cargo fmt` for code formatting.
*   Address `cargo clippy` warnings.
*   Write tests for new features and bug fixes.

Thank you for contributing!