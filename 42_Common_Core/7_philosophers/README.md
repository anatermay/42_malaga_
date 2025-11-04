# philosophers

![42 School](https://img.shields.io/badge/School-42%20Málaga-blue)
![Language](https://img.shields.io/badge/Language-C-brightgreen)
![Rank](https://img.shields.io/badge/Rank-03-orange)
![Score](https://img.shields.io/badge/Score-100%2F100-success)

## 📋 Project Overview

`philosophers` is a classic computer science problem implementation that explores concurrent programming, threading, and synchronization in C. This project is part of the 42 Common Core curriculum (Rank 03) and is based on the famous "Dining Philosophers Problem" introduced by Edsger Dijkstra.

## 🎯 Objectives

- Understand and implement threading concepts using pthreads
- Learn about race conditions and how to prevent them
- Implement proper synchronization using mutexes
- Handle shared resources between multiple threads
- Manage thread lifecycle and communication
- Prevent deadlocks and handle thread safety
- Follow 42 School's coding standards (Norminette)

## 🧠 The Dining Philosophers Problem

The problem consists of N philosophers sitting at a round table with N forks. Each philosopher alternates between thinking, eating, and sleeping. To eat, a philosopher needs both forks adjacent to them (left and right). The challenge is to design a solution that prevents deadlock and starvation.

### The Rules
- Philosophers alternate between **eating**, **sleeping**, and **thinking**
- A philosopher needs **two forks** to eat (left and right)
- Philosophers cannot communicate with each other
- When a philosopher finishes eating, they put down both forks and start sleeping
- After sleeping, they start thinking
- The simulation stops when a philosopher dies or all have eaten enough times

## 📁 Project Structure

```
7_philosophers/
├── philo.h                          # Main header file
├── 0_main.c                         # Main program entry point
├── 1_argument_parsing.c             # Command line argument validation
├── 2_init_table.c                   # Initialize table and shared data
├── 3_init_philos.c                  # Initialize philosopher structures
├── 4_threads.c                      # Thread creation and management
├── 5_philosophers_routine.c         # Main philosopher behavior
├── 6_guard.c                        # Monitor thread (death detection)
├── ft_printf/                       # Custom printf implementation
├── l_atoi.c                         # String to integer conversion
├── l_atol.c                         # String to long conversion
├── l_isdigit.c                      # Digit validation
├── l_isspace.c                      # Whitespace validation
├── l_strcmp.c                       # String comparison
├── u_destroyandexit.c               # Cleanup and exit functions
├── u_isdeath.c                      # Death detection utilities
├── u_isfinished.c                   # Completion checking
├── u_printstatus.c                  # Thread-safe status printing
├── u_time.c                         # Time management functions
├── ft_print_error.c                 # Error handling
├── Makefile                         # Build configuration
└── README.md                        # This file
```

## 🚀 Usage

### Prerequisites

- Linux or macOS
- GCC compiler with pthread support
- Make utility

### Compilation

```bash
# Clone and compile
git clone [repository]
cd philosophers
make

# Clean object files
make clean

# Clean everything
make fclean

# Recompile everything
make re
```

### Running the Simulation

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Parameters

| Parameter | Description | Required |
|-----------|-------------|----------|
| `number_of_philosophers` | Number of philosophers (1-200) | ✅ |
| `time_to_die` | Time in ms before a philosopher dies | ✅ |
| `time_to_eat` | Time in ms to eat | ✅ |
| `time_to_sleep` | Time in ms to sleep | ✅ |
| `number_of_times_each_philosopher_must_eat` | Stop condition (optional) | ❌ |

### Examples

```bash
# Basic simulation
./philo 5 800 200 200

# With eating limit
./philo 5 800 200 200 7

# Tight timing (should not die)
./philo 4 410 200 200

# Single philosopher (should die)
./philo 1 800 200 200

# Large simulation
./philo 100 800 200 200
```

## 💡 Key Features

### Thread Management
- **Philosopher Threads**: Each philosopher runs in its own thread
- **Monitor Thread**: Dedicated thread to check for death conditions
- **Synchronization**: Proper thread synchronization and communication
- **Lifecycle Management**: Clean thread creation and destruction

### Mutex Implementation
- **Fork Mutexes**: One mutex per fork to prevent shared access
- **Print Mutex**: Ensures atomic printing of status messages
- **Death Mutex**: Protects death state checking
- **Meal Mutex**: Synchronizes meal counting and completion checking

### Deadlock Prevention
- **Ordered Lock Acquisition**: Consistent fork picking order
- **Last Philosopher Strategy**: Special handling for the last philosopher
- **Timeout Management**: Proper timing to prevent indefinite blocking

## 🎨 Implementation Details

### Main Data Structures

```c
typedef struct s_philo
{
    long            id;
    long            meals;
    bool            death;
    bool            finished;
    long            last_meal_time;
    long            start_time;
    t_table         *table;
    pthread_t       thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_mutex_t meal_mutex;
} t_philo;

typedef struct s_table
{
    long            philos_numb;
    long            die_time;
    long            eat_time;
    long            sleep_time;
    long            must_eat;
    bool            argv_5;
    long            died;
    long            finished;
    long            start_time;
    t_philo         philos[MAX];
    pthread_t       moiras;
    pthread_mutex_t forks[MAX];
    pthread_mutex_t death_mtx;
    pthread_mutex_t print_mtx;
    pthread_mutex_t meal_mtx;
} t_table;
```

### Philosopher Routine

```c
void *agora(void *data)
{
    t_philo *philo = (t_philo *)data;
    
    while (!is_dead(philo) && !is_finished(philo))
    {
        take_forks(philo);
        eat(philo);
        sleep_and_think(philo);
    }
    
    return (NULL);
}
```

### Death Detection

The monitor thread continuously checks if any philosopher has exceeded the time to die:

```c
void *guard(void *data)
{
    t_table *table = (t_table *)data;
    
    while (!simulation_finished(table))
    {
        check_all_philosophers(table);
        usleep(CHECK_INTERVAL);
    }
    
    return (NULL);
}
```

## 🧪 Testing Scenarios

### Basic Tests
```bash
# Should not die
./philo 1 800 200 200    # Single philosopher (dies)
./philo 5 800 200 200    # Normal case
./philo 4 410 200 200    # Tight timing

# Should complete
./philo 5 800 200 200 7  # With eating limit
./philo 2 800 200 200 5  # Two philosophers
```

### Stress Tests
```bash
# High philosopher count
./philo 200 800 200 200

# Very tight timing
./philo 4 305 200 100

# Long simulation
./philo 10 800 200 200 100
```

### Edge Cases
```bash
# Invalid arguments
./philo 0 800 200 200     # Zero philosophers
./philo 5 -1 200 200      # Negative time
./philo abc 800 200 200   # Non-numeric input
```

## 🚨 Error Handling

The program handles various error conditions:
- **Invalid Arguments**: Non-numeric or out-of-range values
- **Thread Creation Failures**: Proper cleanup on pthread_create errors
- **Mutex Initialization Failures**: Resource cleanup on mutex errors
- **Memory Management**: Proper cleanup of all allocated resources

## 📈 Performance Considerations

- **Minimal CPU Usage**: Efficient sleep implementation using usleep
- **Memory Efficiency**: Static allocation for philosopher structures
- **Thread Safety**: All shared data access is properly synchronized
- **Scalability**: Supports up to 200 philosophers efficiently

## 🔧 Advanced Features

### Time Management
- **Precise Timing**: Microsecond precision for all time calculations
- **Non-blocking Sleep**: Custom usleep implementation
- **Synchronized Start**: All philosophers start simultaneously

### Status Reporting
```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

### Completion Detection
- Tracks when all philosophers have eaten the required number of times
- Graceful termination when simulation goals are met
- Proper cleanup of all resources

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
