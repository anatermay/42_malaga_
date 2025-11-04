# 42 School Projects Repository

<div align="center">
  <img src="https://img.shields.io/badge/42-School-black?style=for-the-badge&logo=42&logoColor=white" alt="42 School Badge"/>
  <img src="https://img.shields.io/badge/Made%20with-C-blue?style=for-the-badge&logo=c&logoColor=white" alt="Made with C"/>
  <img src="https://img.shields.io/badge/Current%20Rank-04-green?style=for-the-badge" alt="Current Rank"/>
  <img src="https://img.shields.io/badge/Status-Active-brightgreen?style=for-the-badge" alt="Status"/>
</div>

<div align="center">
  <h3>🚀 My Journey Through 42 School</h3>
  <p><strong>Student:</strong> Ana Ternero Mayorga (@aternero)</p>
  <p><strong>Campus:</strong> 42 Málaga</p>
  <p><strong>GitHub:</strong> <a href="https://github.com/anatermay/42_malaga_">github.com/anatermay/</a></p>
  <p><strong>42 Profile:</strong> <a href="https://profile.intra.42.fr/users/aternero">profile.intra.42.fr/users/aternero</a></p>
  
  <a href="README_es.md">🇪🇸 Versión en Español</a>
</div>

---

## 📋 Table of Contents

- [About 42 School](#about-42-school)
- [Repository Structure](#repository-structure)
- [Common Core Projects by Rank](#common-core-projects-by-rank)
- [Piscine Projects](#piscine-projects)
- [Discovery Piscine](#discovery-piscine)
- [Installation & Usage](#installation--usage)
- [Skills Developed](#skills-developed)
- [Current Progress](#current-progress)
- [Contact](#contact)

---

## 🎯 About 42 School

42 is a revolutionary programming school that uses a peer-to-peer learning methodology. There are no teachers, no courses, and no set schedule. Students learn through projects, with each project building upon the previous ones to develop strong programming fundamentals.

The curriculum is designed to:
- Develop algorithmic thinking and problem-solving skills
- Master C programming language and system programming
- Understand computer science fundamentals
- Build collaborative and peer learning abilities
- Foster independence and self-directed learning

---

## 📁 Repository Structure

```
42_malaga_/
├── 42_Common_Core/     # Main curriculum projects (Ranks 00-04+)
├── 42_Piscine/         # Selection process projects
├── 42_Discovery_Web/   # Web development discovery
└── dashes/             # Additional materials and experiments
```

---

## 🎓 Common Core Projects by Rank

### **🏆 Rank 00: Foundation**

#### **🔧 [libft](42_Common_Core/0_libft/)** ✅
- **Description:** Recreation of essential C library functions from scratch
- **Skills:** Memory management, string manipulation, linked lists, Makefile
- **Key Functions:** `ft_strlen`, `ft_strcpy`, `ft_atoi`, `ft_memcpy`, `ft_split`, and 42+ functions
- **Learning Goals:** Understanding C standard library internals
- **Status:** ✅ **Completed**

---

### **🏆 Rank 01: Core Concepts**

#### **📝 [ft_printf](42_Common_Core/1_ft_printf/)** ✅
- **Description:** Custom implementation of the famous `printf` function
- **Skills:** Variadic functions, formatted output, type conversion, parsing
- **Supported Formats:** `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%p`, `%%`
- **Challenges:** Flag handling, precision, width formatting
- **Status:** ✅ **Completed**

#### **🖥️ born2beroot** ✅
- **Description:** System administration project - setting up a virtual machine
- **Skills:** Linux system administration, virtualization, security, networking
- **Technologies:** VirtualBox/VMware, Debian/CentOS, SSH, firewalls, sudo
- **Learning Goals:** Server setup, user management, security policies
- **Status:** ✅ **Completed**

#### **📖 [get_next_line](42_Common_Core/2_get_next_line/)** ✅
- **Description:** Function that reads a file line by line efficiently
- **Skills:** File I/O, static variables, buffer management, memory optimization
- **Challenge:** Handle multiple file descriptors simultaneously (bonus)
- **Edge Cases:** Large files, different line endings, memory constraints
- **Status:** ✅ **Completed**

---

### **🏆 Rank 02: Algorithms & Graphics**

#### **🔄 [push_swap](42_Common_Core/3_push_swap/)** ✅
- **Description:** Efficient sorting algorithm using two stacks with limited operations
- **Skills:** Algorithm optimization, complexity analysis, stack data structures
- **Operations:** `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`
- **Goal:** Sort integers with minimum number of operations
- **Algorithms:** Implemented optimized sorting strategies for different input sizes
- **Status:** ✅ **Completed**

#### **📋 examrank02** ✅
- **Description:** Intermediate programming exam
- **Skills:** C programming under time pressure, problem-solving
- **Format:** Live coding exam with random exercises
- **Status:** ✅ **Completed**

#### **🎮 [so_long](42_Common_Core/5_so_long/)** ✅
- **Description:** 2D game development using MLX42 graphics library
- **Skills:** Graphics programming, event handling, game loop, sprite management
- **Features:** Map validation, collision detection, animation, score tracking
- **Game Mechanics:** Collect all items and reach the exit
- **Graphics:** Custom sprites, smooth animations, window management
- **Status:** ✅ **Completed**

#### **📡 [minitalk](42_Common_Core/4_minitalk/)** ✅
- **Description:** Client-server communication using UNIX signals only
- **Skills:** Inter-process communication, signal handling, bit manipulation
- **Components:** Server receives and displays messages from multiple clients
- **Protocols:** Custom protocol using SIGUSR1 and SIGUSR2
- **Bonus:** Unicode support, acknowledgment system, multiple clients
- **Status:** ✅ **Completed**

---

### **🏆 Rank 03: System Programming**

#### **🍽️ [philosophers](42_Common_Core/7_philosophers/)** ✅
- **Description:** Simulation of the dining philosophers problem
- **Skills:** Threading, mutexes, synchronization, deadlock prevention
- **Concepts:** Race conditions, thread safety, resource sharing
- **Challenge:** Prevent deadlocks while maintaining optimal performance
- **Implementation:** Mutex-based solution with precise timing
- **Status:** ✅ **Completed**

#### **📋 examrank03** ✅
- **Description:** Advanced programming exam
- **Skills:** Advanced C programming, system calls, complex problem-solving
- **Format:** Live coding exam with challenging exercises
- **Status:** ✅ **Completed**

#### **🐚 [minishell](42_Common_Core/6_minishell/)** ✅
- **Description:** Recreation of a UNIX shell similar to bash
- **Skills:** Process management, parsing, system calls, signal handling
- **Features:** Command execution, pipes, redirections, environment variables
- **Built-ins:** `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- **Advanced:** Quote handling, variable expansion, error management
- **Status:** ✅ **Completed**

---

### **🏆 Rank 04: Advanced Topics (Current)**

#### **🌐 [netpractice](42_Common_Core/8_netpractice/)** ✅
- **Description:** Network configuration and TCP/IP understanding
- **Skills:** Networking fundamentals, subnetting, routing, IP addressing
- **Topics:** Subnet masks, network topology, routing tables, CIDR notation
- **Exercises:** 10 network configuration challenges
- **Status:** ✅ **Completed**

#### **🎮 cub3d** 🔄
- **Description:** 3D game engine using raycasting (like Wolfenstein 3D)
- **Skills:** 3D graphics, raycasting algorithms, texture mapping
- **Technologies:** MLX42, mathematical calculations, optimization
- **Status:** 🔄 **In Progress**

---

## 🏊 Piscine Projects

The **Piscine** (French for "swimming pool") is the intensive 4-week selection process for 42 School.

### **C Programming Modules**
- **CPiscineC00:** Basic C programming, first steps with functions
- **CPiscineC01:** Pointers and memory addresses fundamentals
- **CPiscineC02:** String manipulation and character arrays

**Duration:** 4 weeks intensive coding bootcamp (26 days)  
**Schedule:** 24/7 access, peer evaluation system  
**Focus:** C programming fundamentals, resilience building, collaborative learning

---

## 🌐 Discovery Piscine

Introduction to web development covering:
- **HTML/CSS:** Structure, styling, responsive design
- **JavaScript:** Interactive programming, DOM manipulation
- **Web Fundamentals:** HTTP, APIs, modern web development practices

---

## 🛠️ Installation & Usage

### Prerequisites
- **Operating System:** Linux or macOS
- **Compiler:** GCC with flags `-Wall -Wextra -Werror`
- **Build System:** Make
- **Version Control:** Git

### General Compilation
Most projects include a Makefile for standardized compilation:

```bash
# Clone the repository
git clone https://github.com/anatermay/42_malaga_.git
cd 42_malaga_

# Navigate to specific project
cd 42_Common_Core/[project_name]

# Compile
make

# Clean object files
make clean

# Full clean (including executable)
make fclean

# Recompile everything
make re
```

### Project-Specific Instructions

#### **libft**
```bash
cd 42_Common_Core/0_libft/
make
# Creates libft.a static library
# Include in other projects: gcc -L. -lft
```

#### **ft_printf**
```bash
cd 42_Common_Core/1_ft_printf/
make
# Test with: ./test_program
```

#### **so_long**
```bash
cd 42_Common_Core/5_so_long/
# Install MLX42 dependencies first
make
./so_long maps/valid_map.ber
```

#### **minishell**
```bash
cd 42_Common_Core/6_minishell/
make
./minishell
# Interactive shell ready!
```

#### **philosophers**
```bash
cd 42_Common_Core/7_philosophers/
make
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [optional: times_each_must_eat]
# Example: ./philo 5 800 200 200
```

---

## 🧠 Skills Developed

### **Technical Expertise**
- **C Programming:** Advanced proficiency, memory management, debugging
- **System Programming:** Process management, signals, threading, IPC
- **Algorithms:** Sorting, searching, optimization, complexity analysis
- **Data Structures:** Arrays, linked lists, stacks, queues, trees
- **Graphics Programming:** 2D/3D rendering, game development, MLX42
- **Network Programming:** TCP/IP, socket programming, network protocols
- **Shell Programming:** Command parsing, process execution, I/O redirection
- **Object-Oriented Programming:** C++ fundamentals, design patterns

### **Development Practices**
- **Version Control:** Git workflow, branching, collaboration
- **Code Quality:** Norminette compliance, clean code principles
- **Testing:** Unit testing, edge case handling, debugging techniques
- **Documentation:** Technical writing, code documentation
- **Performance:** Optimization, profiling, memory efficiency

### **Soft Skills**
- **Problem Solving:** Algorithmic thinking, systematic debugging
- **Peer Learning:** Code review, knowledge sharing, mentoring
- **Project Management:** Time management, milestone planning
- **Resilience:** Handling failure, continuous improvement
- **Communication:** Technical explanations, collaborative development

---

## 📈 Current Progress

### **Completed Ranks**
| Rank | Projects | Status | Key Skills |
|------|----------|--------|------------|
| **00** | libft | ✅ | C fundamentals, memory management |
| **01** | ft_printf, born2beroot, get_next_line | ✅ | System admin, advanced C |
| **02** | push_swap, examrank02, so_long, minitalk | ✅ | Algorithms, graphics, IPC |
| **03** | philosophers, examrank03, minishell | ✅ | Threading, system programming |

### **Current Rank**
| Rank | Projects | Status | Focus |
|------|----------|--------|-------|
| **04** | netpractice | ✅ | Network fundamentals |
| **04** | examrank04 | 🔄 | Advanced programming |
| **04** | cub3d | 🔄 | 3D graphics, raycasting |
| **04** | CPP 00-04 | 🔄 | Object-oriented programming |

### **Statistics**
- **Total Projects Completed:** 12+
- **Current Rank:** 04
- **Next Milestone:** Complete Rank 04 projects
- **Estimated Graduation:** 2026

---

## 🏅 Academic Achievements

- **Successful Piscine Completion:** Selected from competitive applicant pool
- **Consistent High Performance:** Maintaining quality code standards
- **Peer Recognition:** Active participant in peer evaluation system
- **Project Excellence:** All mandatory requirements met with bonus features
- **Community Contribution:** Helping fellow students in their journey

---

## 📞 Contact & Links

<div align="center">

[![GitHub](https://img.shields.io/badge/GitHub-anatermay-black?style=for-the-badge&logo=github)](https://github.com/anatermay/42_malaga_)
[![42 Profile](https://img.shields.io/badge/42-aternero-black?style=for-the-badge&logo=42&logoColor=white)](https://profile.intra.42.fr/users/aternero)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Ana%20Ternero-blue?style=for-the-badge&logo=linkedin)](https://www.linkedin.com/in/ana-ternero-mayorga/)
[![Instagram](https://img.shields.io/badge/Instagram-@anatermay.git-purple?style=for-the-badge&logo=instagram)](https://www.instagram.com/anatermay.git/)

**📍 Campus:** 42 Málaga, Spain  
**📧 Contact:** Available through 42 intranet or LinkedIn  
**🌐 Portfolio:** [github.com/anatermay](https://github.com/anatermay)

</div>

---

## 📄 License & Academic Integrity

This repository is for **educational purposes** as part of the 42 School curriculum. All projects follow 42's academic integrity policies:

- Code is original work or properly attributed
- Peer learning and collaboration encouraged
- Direct copying discouraged to maintain learning value
- Projects available for reference and learning

**⚠️ Note for 42 Students:** Please use this repository responsibly. The goal is learning, not shortcuts.

---

<div align="center">
  <h3>🚀 "The journey of a thousand programs begins with a single line of code"</h3>
  <p><em>Made with ❤️ and countless hours of debugging at 42 Málaga</em></p>
  
  ![42](https://img.shields.io/badge/42-School-black?style=flat&logo=42&logoColor=white)
  ![C](https://img.shields.io/badge/C-Programming-blue?style=flat&logo=c&logoColor=white)
  ![Linux](https://img.shields.io/badge/Linux-System-orange?style=flat&logo=linux&logoColor=white)
</div>
