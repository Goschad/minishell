# minishell

A 42 School project implementing a minimal shell in C, inspired by bash.  
Built as a team project with a focus on parsing, process management, and Unix system calls.

---

## About

minishell reproduces the core behavior of a Unix shell. It reads a command line, parses it, and executes commands with support for pipes, redirections, environment variables, and signal handling.

This project is one of the most complex of the 42 curriculum, requiring a deep understanding of how a shell works under the hood — from lexing and parsing to process forking and file descriptor manipulation.

---

## Features

### Parsing
- Lexing and tokenizing of the input line
- Handling of single quotes `'` (no interpretation) and double quotes `"` (variable expansion)
- Expansion of environment variables (`$VAR`, `$?`)
- Proper handling of spaces and special characters

### Pipes
- Chaining commands with `|`
- Each command in a pipeline runs in its own child process
- File descriptors correctly wired between processes via `pipe()`

### Redirections
- `<` — input redirection
- `>` — output redirection (truncate)
- `>>` — output redirection (append)
- `<<` — heredoc (read input until delimiter)

### Signals
- `Ctrl+C` — interrupt current process, display a new prompt
- `Ctrl+D` — exit the shell
- `Ctrl+\` — ignored in interactive mode

### Built-in commands
- `echo` — with `-n` flag
- `cd` — with relative and absolute paths
- `pwd` — print working directory
- `export` — set environment variables
- `unset` — unset environment variables
- `env` — print environment
- `exit` — exit the shell with a status code

### Bonus — Wildcard expansion

- `*` is expanded to match files and directories in the current working directory
- Supports patterns like `*.c`, `*test*`, `main*`, `*_bonus*`
- Expansion happens before command execution, mimicking bash glob behavior

---

## Usage

### Dependencies

minishell requires the **readline** library:

```bash
# On macOS (with Homebrew)
brew install readline

# On Ubuntu/Debian
sudo apt-get install libreadline-dev
```

### Compilation

```bash
cd minishell
make
```

### Execution

```bash
./minishell
```

---

## Makefile Rules

```bash
make        # Compile the project
make clean  # Remove object files
make fclean # Remove object files and binary
make re     # Full recompile
```

---

## Concepts Covered

- Lexing and parsing (tokenizer, AST or command list)
- Process creation with `fork()` and `execve()`
- Inter-process communication with `pipe()`
- File descriptor manipulation with `dup2()`
- Signal handling with `signal()` / `sigaction()`
- Environment variable management
- Memory management with no leaks

---

## Authors

- **Goschad** — [@Goschad](https://github.com/Goschad)
- **jguerin06** — [@jguerin06](https://github.com/jguerin06)