# 📚 libft - Custom C Library Implementation

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat&logo=42&logoColor=white)](https://42.fr/)
[![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Norm](https://img.shields.io/badge/Norm-v3-blue)](https://github.com/42School/norminette)
[![Grade](https://img.shields.io/badge/Grade-125%2F100-brightgreen)](https://profile.intra.42.fr/users/aternero)

## 📖 About

**libft** is the foundational project of the 42 Common Core curriculum (Rank 00). This project requires implementing a comprehensive C library containing essential functions that replicate the behavior of standard C library functions, plus additional utility functions. It serves as the building block for all subsequent 42 projects.

## 🎯 Project Objectives

- **Reimplement** standard C library functions from scratch
- **Understand** low-level memory management and pointers
- **Master** C programming fundamentals and best practices
- **Create** a reusable library for future 42 projects
- **Learn** proper code organization and documentation

## 📁 Project Structure

```
libft/
├── libft.h                 # Header file with function prototypes
├── Makefile               # Build automation
├── ft_*.c                 # 43 function implementations
└── README.md              # Project documentation
```

## 📋 Function Categories

### 🔤 **Character Classification & Conversion (7 functions)**
| Function | Description | Standard Equivalent |
|----------|-------------|-------------------|
| `ft_isalpha` | Check if character is alphabetic | `isalpha` |
| `ft_isdigit` | Check if character is numeric | `isdigit` |
| `ft_isalnum` | Check if character is alphanumeric | `isalnum` |
| `ft_isascii` | Check if character is ASCII | `isascii` |
| `ft_isprint` | Check if character is printable | `isprint` |
| `ft_toupper` | Convert to uppercase | `toupper` |
| `ft_tolower` | Convert to lowercase | `tolower` |

### 🧵 **String Manipulation (11 functions)**
| Function | Description | Standard Equivalent |
|----------|-------------|-------------------|
| `ft_strlen` | Calculate string length | `strlen` |
| `ft_strchr` | Locate character in string | `strchr` |
| `ft_strrchr` | Locate character in string (reverse) | `strrchr` |
| `ft_strncmp` | Compare strings (n characters) | `strncmp` |
| `ft_strlcpy` | Size-bounded string copy | `strlcpy` |
| `ft_strlcat` | Size-bounded string concatenation | `strlcat` |
| `ft_strnstr` | Locate substring | `strnstr` |
| `ft_strdup` | Duplicate string | `strdup` |

### 🧠 **Memory Management (6 functions)**
| Function | Description | Standard Equivalent |
|----------|-------------|-------------------|
| `ft_memset` | Fill memory with constant byte | `memset` |
| `ft_bzero` | Zero a byte string | `bzero` |
| `ft_memcpy` | Copy memory area | `memcpy` |
| `ft_memmove` | Copy memory area (overlap-safe) | `memmove` |
| `ft_memchr` | Scan memory for character | `memchr` |
| `ft_memcmp` | Compare memory areas | `memcmp` |

### 🔢 **Conversion & I/O (6 functions)**
| Function | Description | Standard Equivalent |
|----------|-------------|-------------------|
| `ft_atoi` | ASCII to integer conversion | `atoi` |
| `ft_itoa` | Integer to ASCII conversion | *Custom* |
| `ft_calloc` | Allocate and zero memory | `calloc` |
| `ft_putchar_fd` | Output character to file descriptor | *Custom* |
| `ft_putstr_fd` | Output string to file descriptor | *Custom* |
| `ft_putendl_fd` | Output string + newline to file descriptor | *Custom* |
| `ft_putnbr_fd` | Output number to file descriptor | *Custom* |

### ✨ **Additional String Functions (6 functions)**
| Function | Description | Purpose |
|----------|-------------|---------|
| `ft_substr` | Extract substring | Create substring from string |
| `ft_strjoin` | Concatenate strings | Join two strings with allocation |
| `ft_strtrim` | Trim characters from string | Remove specified chars from ends |
| `ft_split` | Split string by delimiter | Split string into array |
| `ft_strmapi` | Apply function to string chars | Map function with index |
| `ft_striteri` | Iterate function over string | Apply function to each char |

### 🔗 **Bonus: Linked List Functions (9 functions)**
| Function | Description | Purpose |
|----------|-------------|---------|
| `ft_lstnew` | Create new list element | List creation |
| `ft_lstadd_front` | Add element to list front | List manipulation |
| `ft_lstadd_back` | Add element to list back | List manipulation |
| `ft_lstsize` | Count list elements | List information |
| `ft_lstlast` | Get last list element | List navigation |
| `ft_lstdelone` | Delete one list element | Memory management |
| `ft_lstclear` | Delete entire list | Memory management |
| `ft_lstiter` | Apply function to list | List iteration |
| `ft_lstmap` | Apply function and create new list | Functional programming |

## 🛠️ Technical Implementation

### **Core Features:**
- **Memory Safety**: All functions handle NULL pointers gracefully
- **Buffer Overflow Protection**: Size-bounded operations prevent overflows
- **Norm Compliance**: Follows 42 coding standards strictly
- **No Memory Leaks**: Proper allocation and deallocation
- **Modular Design**: Each function in separate file for clean compilation

### **Advanced Implementations:**

#### `ft_split` - String Tokenization
```c
char **ft_split(char const *s, char c);
```
- Splits string `s` using delimiter `c`
- Returns NULL-terminated array of strings
- Handles multiple consecutive delimiters
- Memory-efficient with proper error handling

#### `ft_itoa` - Integer to String Conversion
```c
char *ft_itoa(int n);
```
- Converts any integer (including `INT_MIN`) to string
- Handles negative numbers and edge cases
- Dynamic memory allocation for exact size needed

#### Linked List Implementation
```c
typedef struct s_list {
    void *content;
    struct s_list *next;
} t_list;
```
- Generic linked list supporting any data type
- Complete set of manipulation functions
- Memory management with custom deletion functions

## 🏗️ Build System

### **Makefile Targets:**
```bash
make all        # Compile main library
make bonus      # Compile with bonus functions
make clean      # Remove object files
make fclean     # Remove all generated files
make re         # Recompile everything
```

### **Compilation:**
```bash
gcc -Wall -Wextra -Werror -c *.c
ar rcs libft.a *.o
```

## 🧪 Testing & Validation

### **Testing Methods:**
- **Unit Testing**: Each function tested individually
- **Memory Testing**: Valgrind for leak detection
- **Edge Cases**: NULL pointers, empty strings, boundary values
- **Norm Compliance**: Norminette validation
- **Comparison Testing**: Results compared with standard library

### **Key Test Cases:**
- Empty strings and NULL pointers
- Maximum/minimum integer values
- Large memory allocations
- Overlapping memory regions (memmove)
- Unicode and special characters

## 🎓 Learning Outcomes

### **Technical Skills Developed:**
- **C Programming Mastery**: Deep understanding of C syntax and semantics
- **Memory Management**: Manual allocation, deallocation, and leak prevention
- **Pointer Arithmetic**: Advanced pointer manipulation and dereferencing
- **Data Structures**: Linked list implementation and manipulation
- **Build Systems**: Makefile creation and dependency management
- **Code Organization**: Modular programming and header file management

### **Problem-Solving Skills:**
- **Algorithm Implementation**: Efficient string and memory algorithms
- **Edge Case Handling**: Robust error checking and input validation
- **Debugging**: Systematic bug identification and resolution
- **Code Optimization**: Performance considerations in low-level operations

## 🌟 Project Highlights

### **Key Achievements:**
- ✅ **43 Functions Implemented** - Complete standard library subset
- ✅ **100% Norm Compliant** - Perfect adherence to 42 coding standards
- ✅ **Zero Memory Leaks** - Valgrind verified memory management
- ✅ **Comprehensive Testing** - Extensive edge case coverage
- ✅ **Bonus Completed** - Full linked list implementation
- ✅ **Reusable Library** - Foundation for all future 42 projects

### **Technical Excellence:**
- **Performance Optimized**: Efficient algorithms for all operations
- **Memory Efficient**: Minimal memory footprint and optimal allocation
- **Error Resilient**: Graceful handling of all error conditions
- **Well Documented**: Clear code structure and comprehensive comments

## 📊 Project Statistics

**Total Functions**: 43 (34 mandatory + 9 bonus) ✅  
**Lines of Code**: 2,000+ 💻  
**Files**: 45 source files + header + Makefile 📄  
**Grade**: **125/100** (Perfect score + bonus) 🏆  
**Completion Time**: 3 weeks ⏱️

## 🔗 Links

- **GitHub Repository**: [42_malaga_](https://github.com/anatermay/42_malaga_)
- **GitHub Profile**: [anatermay](https://github.com/anatermay/)
- **42 Profile**: [aternero](https://profile.intra.42.fr/users/aternero)
- **42 School**: [42 Málaga - Fundación Telefónica](https://www.42malaga.com/)

## 🚀 Usage in Future Projects

This library serves as the foundation for subsequent 42 projects:
- **ft_printf**: Uses string and memory functions
- **get_next_line**: Utilizes string manipulation
- **push_swap**: Employs linked list functions
- **minishell**: Leverages string parsing and memory management
- **All projects**: Benefit from robust utility functions

## 📝 Next Steps

This foundational library enabled progression to:
- **Advanced String Processing** (ft_printf)
- **File I/O Operations** (get_next_line)
- **Algorithm Implementation** (push_swap)
- **System Programming** (minitalk, philosophers)
- **Graphics Programming** (so_long)

---

*libft represents the cornerstone of my 42 education, establishing fundamental programming skills that enabled success in all subsequent projects.*
