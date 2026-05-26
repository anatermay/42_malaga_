# minishell

![42 School](https://img.shields.io/badge/School-42%20Málaga-blue)
![Language](https://img.shields.io/badge/Language-C-brightgreen)
![Rank](https://img.shields.io/badge/Rank-03-orange)
![Score](https://img.shields.io/badge/Score-100%2F100-success)

## 📋 Project Overview

`minishell` is a custom Unix shell implementation built from scratch in C. This project is part of the 42 Common Core curriculum (Rank 03) and focuses on understanding shell behavior, process management, signal handling, and command line parsing.

## 🎯 Objectives

- Create a functional Unix shell similar to bash
- Implement command parsing and execution
- Handle pipes, redirections, and built-in commands
- Manage processes and signal handling
- Support environment variables and expansions
- Implement proper error handling and memory management
- Follow 42 School's coding standards (Norminette)

## 🔧 Supported Features

### Core Shell Features
| Feature | Description | Status |
|---------|-------------|--------|
| **Command Execution** | Execute system commands with PATH resolution | ✅ |
| **Built-in Commands** | `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit` | ✅ |
| **Pipes** | Chain commands with pipe operator `\|` | ✅ |
| **Redirections** | Input/output redirection `<`, `>`, `>>` | ✅ |
| **Heredoc** | Here document implementation `<<` | ✅ |
| **Environment Variables** | Variable expansion and management | ✅ |
| **Signal Handling** | Proper handling of `Ctrl+C`, `Ctrl+D`, `Ctrl+\` | ✅ |
| **Quote Handling** | Single and double quote parsing | ✅ |

### Built-in Commands

| Command | Description | Syntax |
|---------|-------------|--------|
| `echo` | Display text with `-n` option | `echo [-n] [string...]` |
| `cd` | Change directory with relative/absolute paths | `cd [directory]` |
| `pwd` | Print working directory | `pwd` |
| `export` | Set environment variables | `export [name[=value]...]` |
| `unset` | Remove environment variables | `unset [name...]` |
| `env` | Display environment variables | `env` |
| `exit` | Exit shell with optional status code | `exit [status]` |

## 📁 Project Structure

```
6_minishell/
├── src/
│   ├── minishell.h                  # Main header file
│   ├── main.c                       # Main program loop
│   ├── main_utils.c                 # Main utilities
│   ├── buildt-ins/                  # Built-in commands
│   │   ├── cd.c                     # cd command implementation
│   │   ├── echo.c                   # echo command implementation
│   │   ├── env.c                    # env command implementation
│   │   ├── exit.c                   # exit command implementation
│   │   ├── export.c                 # export command implementation
│   │   ├── pwd.c                    # pwd command implementation
│   │   └── unset.c                  # unset command implementation
│   ├── parser/                      # Command parsing and expansion
│   │   ├── 0_parser_and_expander/   # Main parsing logic
│   │   ├── 1_init_shell_line_t/     # Command structure initialization
│   │   ├── 2_redirect/              # Redirection parsing
│   │   ├── 3_parsing/               # Command line parsing
│   │   ├── 4_expand/                # Variable expansion
│   │   └── utils/                   # Parser utilities
│   ├── executer/                    # Command execution
│   │   ├── executer.c               # Main execution logic
│   │   ├── pipeline.c               # Pipeline management
│   │   ├── child_exec.c             # Child process execution
│   │   ├── heredoc.c                # Here document implementation
│   │   └── builtins_handler.c       # Built-in command handling
│   └── utils/                       # General utilities
├── libft/                           # Custom C library
├── Makefile                         # Build configuration
└── README.md                        # This file
```

## 🚀 Usage

### Prerequisites

- Linux or macOS
- GNU Readline library
- GCC compiler
- Make utility

### Installation

```bash
# Clone the repository
git clone [repository]
cd minishell

# Install readline library (Ubuntu/Debian)
sudo apt-get install libreadline-dev

# Install readline library (macOS)
brew install readline

# Compile the project
make
```

### Running the Shell

```bash
# Start the shell
./minishell

# You should see a prompt similar to:
minishell$ 
```

### Basic Usage Examples

```bash
# Execute simple commands
minishell$ ls -la
minishell$ pwd
minishell$ echo "Hello, World!"

# Use pipes
minishell$ ls | grep .c | wc -l

# Use redirections
minishell$ echo "Hello" > output.txt
minishell$ cat < input.txt
minishell$ ls >> log.txt

# Use heredoc
minishell$ cat << EOF
This is a heredoc
Multiple lines supported
EOF

# Environment variables
minishell$ export MY_VAR="Hello"
minishell$ echo $MY_VAR
minishell$ env | grep MY_VAR

# Built-in commands
minishell$ cd /tmp
minishell$ pwd
minishell$ exit 0
```

## 💡 Key Features

### Command Parsing
- **Lexical Analysis**: Tokenizes input into commands, arguments, operators
- **Quote Handling**: Properly handles single (`'`) and double (`"`) quotes
- **Variable Expansion**: Expands environment variables (`$VAR`, `$?`)
- **Wildcard Support**: Basic filename expansion (implementation dependent)

### Process Management
- **Fork/Exec Model**: Creates child processes for command execution
- **Pipeline Implementation**: Connects commands through pipes
- **Signal Handling**: Manages interrupts and process control signals
- **Exit Status Tracking**: Maintains command exit statuses

### Memory Management
- **Dynamic Allocation**: Efficient memory usage for command structures
- **Leak Prevention**: Proper cleanup of all allocated resources
- **Error Handling**: Graceful handling of allocation failures

### Advanced Features
- **Here Documents**: Multi-line input redirection
- **Environment Management**: Complete environment variable support
- **Path Resolution**: Automatic command searching in PATH
- **Error Reporting**: Comprehensive error messages and status codes

## 🧪 Testing

The shell handles various complex scenarios:

### Command Execution
```bash
# Complex pipelines
ls -la | grep "^d" | sort | head -5

# Multiple redirections
echo "test" > file1 && cat file1 >> file2

# Environment variable expansion
export PATH="/bin:/usr/bin" && echo $PATH
```

### Error Handling
```bash
# Invalid commands
nonexistent_command

# Permission errors
./no_execute_permission

# Syntax errors
ls | | grep test
```

### Signal Management
- **Ctrl+C**: Interrupts current command, returns to prompt
- **Ctrl+D**: Sends EOF, exits shell gracefully
- **Ctrl+\\**: Quit signal handling

## 🎨 Implementation Details

### Main Shell Loop
```c
int main(int argc, char **argv, char **envs)
{
    t_data *d;
    
    d = init_data(envs);
    setup_signals();
    
    while (42)
    {
        d->line = readline(d->prompt);
        if (!d->line)
            break;
            
        parser_and_commander(d);
        process_input(d);
    }
    
    cleanup_data(d);
    return (d->exit_status);
}
```

### Command Structure
```c
typedef struct s_shell_line
{
    char                *line;
    char                **cmd;
    t_redirect          *redir;
    int                 empty_quoted_var;
    struct s_shell_line *next;
} t_shell_line;
```

### Pipeline Management
```c
typedef struct s_pipeline
{
    int         pipefd[2];
    int         prev_pipe_read_end;
    int         current_pipe_write_end;
    int         is_last;
    pid_t       *pids;
    int         cmd_count;
    int         cmd_index;
} t_pipeline;
```

## 🚨 Error Handling

The shell provides comprehensive error handling:
- **Syntax Errors**: Invalid pipe usage, unmatched quotes
- **Command Errors**: Command not found, permission denied
- **System Errors**: Fork failures, pipe errors
- **Memory Errors**: Allocation failures, resource cleanup

## 📈 Performance

- **Efficient Parsing**: Optimized tokenization and parsing algorithms
- **Memory Management**: Minimal memory footprint with proper cleanup
- **Process Control**: Efficient fork/exec implementation
- **Signal Handling**: Low-latency signal processing

## 🔗 Links

- **Author**: Ana Ternero
- **GitHub**: [anatermay](https://github.com/anatermay/)
- **42 Profile**: [aternero](https://profile.intra.42.fr/users/aternero)
- **Repository**: [42_malaga_](https://github.com/anatermay/42_malaga_)

## 📊 42 Common Core Progress

This project is part of my journey through the 42 Common Core curriculum:

- **Rank 00**: ✅ libft
- **Rank 01**: ✅ ft_printf, born2beroot, get_next_line
- **Rank 02**: ✅ push_swap, examrank02, so_long, minitalk
- **Rank 03**: ✅ philosophers, examrank03, minishell
- **Rank 04**: 🔄 netpractice (done), examrank04, cub3d, CPP 00-04

## 🏆 Achievement

**Final Score**: 100/100 ✨

---

*This project was completed as part of the 42 School curriculum at 42 Málaga.*
