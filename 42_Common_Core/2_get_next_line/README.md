# get_next_line

![42 School](https://img.shields.io/badge/School-42%20Málaga-blue)
![Language](https://img.shields.io/badge/Language-C-brightgreen)
![Rank](https://img.shields.io/badge/Rank-01-orange)
![Score](https://img.shields.io/badge/Score-100%2F100-success)

## 📋 Project Overview

`get_next_line` is a C function that reads a text file line by line, regardless of the buffer size. This project is part of the 42 Common Core curriculum (Rank 01) and focuses on file manipulation, static variables, and dynamic memory allocation.

## 🎯 Objectives

- Read a file line by line using a configurable buffer size
- Handle multiple file descriptors simultaneously (bonus)
- Manage memory efficiently to avoid leaks
- Use static variables to maintain state between function calls
- Work with file descriptors and system calls
- Follow 42 School's coding standards (Norminette)

## 🔧 Function Prototype

```c
char *get_next_line(int fd);
```

### Parameters
- `fd`: File descriptor to read from

### Return Value
- Returns the next line from the file (including the newline character `\n`)
- Returns `NULL` when the file is completely read or an error occurs

## 📁 Project Structure

```
2_get_next_line/
├── get_next_line.c         # Main function implementation
├── get_next_line.h         # Header file with prototypes
├── get_next_line_utils.c   # Utility functions
├── get_next_line_bonus.c   # Bonus: multiple file descriptors
├── get_next_line_bonus.h   # Header for bonus part
├── get_next_line_utils_bonus.c # Bonus utility functions
└── README.md              # This file
```

## 🚀 Usage

### Compilation

```bash
# Compile with custom buffer size
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 get_next_line.c get_next_line_utils.c

# Compile bonus version
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 get_next_line_bonus.c get_next_line_utils_bonus.c
```

### Basic Usage

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;
    
    fd = open("file.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    
    close(fd);
    return (0);
}
```

### Bonus: Multiple File Descriptors

```c
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd1, fd2;
    char *line1, *line2;
    
    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);
    
    line1 = get_next_line(fd1);
    line2 = get_next_line(fd2);
    
    printf("File 1: %s", line1);
    printf("File 2: %s", line2);
    
    free(line1);
    free(line2);
    close(fd1);
    close(fd2);
    
    return (0);
}
```

## 💡 Key Features

### Core Implementation
- **Buffer Management**: Efficient reading with configurable `BUFFER_SIZE`
- **Static Variables**: Maintains state between function calls
- **Dynamic Memory**: Proper allocation and deallocation
- **Line Parsing**: Correctly handles newlines and end-of-file

### Bonus Features
- **Multiple File Descriptors**: Can handle reading from multiple files simultaneously
- **Independent State**: Each file descriptor maintains its own reading state

### Utility Functions
- `ft_strlen()`: Calculate string length
- `ft_strchr()`: Find character in string
- `ft_strjoin()`: Join two strings with proper memory management

## 🧪 Testing

The function handles various scenarios:
- Empty files
- Files without newlines
- Files with only newlines
- Large files with different buffer sizes
- Multiple file descriptors (bonus)
- Invalid file descriptors
- Memory allocation failures

## 📈 Performance

- **Time Complexity**: O(n) where n is the file size
- **Space Complexity**: O(BUFFER_SIZE + line_length)
- **Memory Efficiency**: Only allocates memory for current line
- **Buffer Optimization**: Configurable buffer size for different use cases

## 🔧 Configuration

The buffer size can be configured at compile time:

```bash
# Small buffer for testing
gcc -D BUFFER_SIZE=1 ...

# Large buffer for performance
gcc -D BUFFER_SIZE=8192 ...

# Default buffer size
gcc -D BUFFER_SIZE=4069 ...
```

## 🚨 Error Handling

- Returns `NULL` for invalid file descriptors
- Handles memory allocation failures gracefully
- Properly manages file reading errors
- Prevents memory leaks in all scenarios

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
