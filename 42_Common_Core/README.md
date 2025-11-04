# 🎓 42 Common Core - Systems Programming Journey

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat&logo=42&logoColor=white)](https://42.fr/)
[![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Linux](https://img.shields.io/badge/Linux-FCC624?style=flat&logo=linux&logoColor=black)](https://www.linux.org/)
[![Git](https://img.shields.io/badge/Git-F05032?style=flat&logo=git&logoColor=white)](https://git-scm.com/)
[![Unix](https://img.shields.io/badge/Unix-000000?style=flat&logo=unix&logoColor=white)](https://en.wikipedia.org/wiki/Unix)

## 📖 About

This repository showcases my complete journey through the **42 Common Core** curriculum, a comprehensive systems programming education at 42 School. From fundamental C programming to advanced system concepts, each project builds upon previous knowledge while introducing new challenges in software engineering, algorithms, and system design.

## 🎯 Educational Goals

- Master **C programming** and memory management
- Understand **Unix/Linux** system programming
- Learn **algorithms and data structures** implementation
- Develop **problem-solving** and **debugging** skills
- Explore **concurrent programming** and **process communication**
- Build **network programming** and **system architecture** understanding

## 📁 Projects Overview

### 🔧 **Rank 00: Foundation**
| Project | Description | Technologies | Status |
|---------|-------------|--------------|--------|
| **[libft](./0_libft)** | Custom C library implementation | `C` `Makefile` | ✅ **100%** |

**Key Achievement**: Reimplemented 43 standard C library functions from scratch, establishing a solid foundation for all future projects.

### 🔧 **Rank 01: Core Programming**
| Project | Description | Technologies | Status |
|---------|-------------|--------------|--------|
| **[ft_printf](./1_ft_printf)** | Custom printf function | `C` `Variadic Functions` | ✅ **100%** |
| **[get_next_line](./2_get_next_line)** | File reading function | `C` `File I/O` `Static Variables` | ✅ **100%** |
| **born2beroot** | System administration project | `VirtualBox` `Linux` `System Admin` | ✅ **100%** |

### 🔧 **Rank 02: Algorithms & Graphics**
| Project | Description | Technologies | Status |
|---------|-------------|--------------|--------|
| **[push_swap](./3_push_swap)** | Efficient sorting algorithm | `C` `Algorithms` `Stack Operations` | ✅ **100%** |
| **[so_long](./5_so_long)** | 2D game with graphics library | `C` `MLX42` `Game Development` | ✅ **100%** |
| **[minitalk](./4_minitalk)** | Process communication via signals | `C` `Unix Signals` `IPC` | ✅ **100%** |
| **examrank02** | Exam: Intermediate C programming | `C` `Problem Solving` | ✅ **100%** |

### 🔧 **Rank 03: Advanced Systems**
| Project | Description | Technologies | Status |
|---------|-------------|--------------|--------|
| **[philosophers](./7_philosophers)** | Concurrency and threading | `C` `Pthreads` `Mutexes` `Synchronization` | ✅ **100%** |
| **[minishell](./6_minishell)** | Unix shell implementation | `C` `Bash` `Process Management` | ✅ **100%** |
| **examrank03** | Exam: Advanced C and system programming | `C` `Systems Programming` | ✅ **100%** |

### 🔧 **Rank 04: Networks & Advanced Concepts** (Current)
| Project | Description | Technologies | Status |
|---------|-------------|--------------|--------|
| **[netpractice](./8_netpractice)** | Network configuration and subnetting | `TCP/IP` `Subnetting` `Routing` | ✅ **100%** |
| **examrank04** | Exam: Advanced systems and networking | `C` `Networks` `Systems` | 🔄 **In Progress** |
| **cub3d** | 3D game engine (raycasting) | `C` `MLX42` `3D Graphics` `Raycasting` | 🔄 **In Progress** |
| **CPP 00-04** | C++ programming modules | `C++` `OOP` `STL` | 🔄 **In Progress** |

## 🚀 Project Highlights

### 📚 **libft - The Foundation**
A comprehensive C library containing 43+ functions including:
- **String manipulation**: `ft_strlen`, `ft_strchr`, `ft_strjoin`, `ft_split`
- **Memory management**: `ft_memset`, `ft_memcpy`, `ft_calloc`
- **Linked list operations**: `ft_lstnew`, `ft_lstadd_front`, `ft_lstmap`
- **Character/number utilities**: `ft_isalpha`, `ft_atoi`, `ft_itoa`

### 🖨️ **ft_printf - Formatted Output Mastery**
Recreation of the famous `printf` function supporting:
- **Format specifiers**: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`
- **Variadic functions** and **argument parsing**
- **Memory-efficient** string formatting

### 📖 **get_next_line - File I/O Excellence**
A function that reads files line by line featuring:
- **Buffer management** with customizable `BUFFER_SIZE`
- **Static variables** for persistent state
- **Memory leak prevention** and **multiple file descriptor** support

### 🔄 **push_swap - Algorithm Optimization**
A sorting challenge implementing:
- **Optimized sorting algorithms** for different input sizes
- **Stack operations**: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`
- **Complex cost analysis** and **move optimization**

### 📡 **minitalk - Process Communication**
Inter-process communication using Unix signals:
- **Client-server architecture** using `SIGUSR1` and `SIGUSR2`
- **Bit-level data transmission** and **Unicode support**
- **Error handling** and **acknowledgment system**

### 🎮 **so_long - 2D Game Development**
A complete 2D game featuring:
- **MLX42 graphics library** integration
- **Sprite animation** and **texture management**
- **Map validation** and **collision detection**
- **Player movement** and **objective completion**

### 💻 **minishell - Shell Implementation**
A fully functional Unix shell including:
- **Command parsing** and **execution pipeline**
- **Built-in commands**: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- **Environment variables** and **signal handling**
- **Redirection** and **pipe operations**

### 🍽️ **philosophers - Concurrency Mastery**
The classic dining philosophers problem featuring:
- **Multithreading** with `pthreads`
- **Mutex synchronization** and **deadlock prevention**
- **Resource sharing** and **race condition handling**
- **Precise timing** and **philosopher state management**

### 🌐 **netpractice - Network Fundamentals**
Network configuration exercises covering:
- **TCP/IP protocol** understanding
- **Subnetting** and **CIDR notation**
- **Routing tables** and **network troubleshooting**
- **OSI model** practical application

## 🛠️ Technologies & Skills Mastered

### **Programming Languages**
- **C Programming**: Advanced proficiency with pointers, memory management, and system calls
- **Shell Scripting**: Bash scripting and Unix command-line tools

### **System Programming**
- **Memory Management**: Dynamic allocation, leak prevention, and optimization
- **Process Management**: Fork, exec, wait, and process communication
- **File I/O**: Low-level file operations and descriptor management
- **Signal Handling**: Unix signals and inter-process communication

### **Concurrency & Parallelism**
- **Threading**: POSIX threads (pthreads) and thread management
- **Synchronization**: Mutexes, semaphores, and race condition prevention
- **Deadlock Prevention**: Resource management and timing control

### **Network Programming**
- **TCP/IP Stack**: Understanding of network protocols and architecture
- **Subnetting**: Network design and IP address management
- **Routing**: Network traffic management and configuration

### **Graphics Programming**
- **MLX42 Library**: 2D graphics rendering and event handling
- **Game Development**: Animation, collision detection, and user interaction

### **Development Tools**
- **Makefile**: Build automation and dependency management
- **GDB**: Debugging and program analysis
- **Valgrind**: Memory leak detection and performance analysis
- **Git**: Version control and collaborative development

## 📈 Learning Progression

1. **Rank 00** → C programming fundamentals and library functions
2. **Rank 01** → Advanced string manipulation, variadic functions, and system administration
3. **Rank 02** → Sorting optimization, graphics programming, and inter-process communication
4. **Rank 03** → Shell programming, concurrency, and advanced system concepts
5. **Rank 04** → Network protocols, 3D graphics, and object-oriented programming

## 🎓 Skills Developed

- **Systems Programming**: Deep understanding of Unix/Linux internals
- **Algorithm Design**: Efficient problem-solving and optimization
- **Memory Management**: Leak-free programming and resource optimization
- **Concurrent Programming**: Thread-safe code and synchronization
- **Network Programming**: Protocol understanding and implementation
- **Code Quality**: Clean, maintainable, and well-documented code
- **Debugging**: Advanced troubleshooting and error analysis
- **Project Management**: Large codebase organization and collaboration

## 🌟 Achievement Highlights

- ✅ **9 Projects Completed** with **100% Success Rate**
- ✅ **Currently at Rank 04** - Advanced level student
- ✅ **Zero Memory Leaks** across all projects (Valgrind verified)
- ✅ **Norm Compliance** following 42 coding standards
- ✅ **Peer-to-Peer Learning** through code reviews and collaboration
- ✅ **Advanced Concepts Mastery** in systems, network, and concurrent programming
- ✅ **Minishell Completed** - Full Unix shell implementation
- ✅ **Network Programming** - TCP/IP and routing expertise

## 📊 Overall Statistics

**Current Rank**: 04 🎯  
**Completed Projects**: 9/12 ✅  
**Success Rate**: 100% 🏆  
**Lines of Code**: 15,000+ 💻  
**Technologies Learned**: 20+ 🔧  
**Core Concepts Mastered**: 30+ 🧠

## 🔗 Links

- **GitHub Repository**: [42_malaga_](https://github.com/anatermay/42_malaga_)
- **GitHub Profile**: [anatermay](https://github.com/anatermay/)
- **42 Profile**: [aternero](https://profile.intra.42.fr/users/aternero)
- **42 School**: [42 Málaga - Fundación Telefónica](https://www.42malaga.com/)

## 📝 Next Steps

This comprehensive foundation in systems programming has prepared me for:
- **Advanced C++ Programming** (CPP modules 00-04)
- **3D Graphics Programming** (cub3d raycasting engine)
- **Advanced System Examinations** (examrank04)
- **Backend Development** with modern languages
- **DevOps and System Administration**
- **Embedded Systems Programming**
- **Network Security and Infrastructure**
- **Full-Stack Development** with strong system understanding

---

*This collection represents two years of intensive learning in systems programming, demonstrating progression from basic C programming to advanced system architecture and network programming concepts.*
