# push_swap

![42 School](https://img.shields.io/badge/School-42%20Málaga-blue)
![Language](https://img.shields.io/badge/Language-C-brightgreen)
![Rank](https://img.shields.io/badge/Rank-02-orange)
![Score](https://img.shields.io/badge/Score-125%2F100-success)

## 📋 Project Description

`push_swap` is a sorting algorithm project that challenges you to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. This project is part of the 42 School Common Core curriculum (Rank 02) and focuses on understanding algorithms, complexity, and data structures.

## 🎯 Objectives

- Sort a stack of integers using two stacks (A and B) with minimal operations
- Implement efficient sorting algorithms for different input sizes
- Handle edge cases and optimize for performance
- Create a checker program to validate sorting operations
- Follow 42 School coding standards (Norminette)

## 🔧 Available Operations

The program can perform the following operations:

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements at the top of stack A |
| `sb` | Swap the first 2 elements at the top of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push first element of stack B to stack A |
| `pb` | Push first element of stack A to stack B |
| `ra` | Rotate stack A (first element becomes last) |
| `rb` | Rotate stack B (first element becomes last) |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack A (last element becomes first) |
| `rrb` | Reverse rotate stack B (last element becomes first) |
| `rrr` | `rra` and `rrb` at the same time |

## 📁 Project Structure

```
3_push_swap/
├── push_swap.c           # Main program logic
├── push_swap.h           # Header file with prototypes and structures
├── checker.c             # Bonus checker program
├── checker.h             # Checker header file
├── argv_checker.c        # Input validation functions
├── bso.c                 # Optimization functions
├── cost_algorithm_0.c    # Cost calculation algorithms
├── cost_algorithm_1.c    # Advanced cost calculations
├── if_nbr_args.c         # Sorting for small stacks
├── memory_handling.c     # Memory management functions
├── min_handling.c        # Minimum value handling
├── push.c                # Push operations (pa, pb)
├── reverse_rotate.c      # Reverse rotate operations (rra, rrb, rrr)
├── rotate.c              # Rotate operations (ra, rb, rr)
├── stack_handling.c      # Stack utility functions
├── swap.c                # Swap operations (sa, sb, ss)
├── libft.c               # Custom libft functions
├── libft.h               # Libft header
├── libft_continue.c      # Additional libft functions
├── get_next_line.c       # GNL for checker bonus
├── Makefile             # Build configuration
└── README.md            # This file
```

## 🚀 Usage

### Compilation

```bash
# Compile the main program
make

# Compile the checker (bonus)
make bonus

# Clean object files
make clean

# Clean everything
make fclean

# Recompile everything
make re
```

### Running the Program

```bash
# Sort a list of integers
./push_swap 2 1 3 6 5 8

# Using with random numbers
ARG="4 67 3 87 23"; ./push_swap $ARG

# Test with checker
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

### Examples

```bash
# Simple example with 3 numbers
./push_swap 2 1 3
# Output: sa

# Larger example
./push_swap 2 1 0
# Output: 
# sa
# rra

# Check if sorting is correct
./push_swap 2 1 0 | ./checker 2 1 0
# Output: OK
```

## 💡 Algorithm Strategy

The implementation uses different strategies based on stack size:

### Small Stacks (≤ 5 elements)
- **2-3 elements**: Direct sorting with minimal operations
- **4-5 elements**: Move minimum to stack B, sort remaining, then push back

### Large Stacks (> 5 elements)
1. **Indexing**: Assign indices to create a normalized representation
2. **Initial Push**: Push elements to stack B based on index ranges
3. **Cost Analysis**: Calculate the cost of moving each element to its target position
4. **Optimal Moves**: Execute the least costly moves to sort efficiently
5. **Final Positioning**: Position the minimum element at the top

### Key Features
- **Cost Calculator**: Evaluates the number of operations needed for each possible move
- **Target Assignment**: Determines the optimal position for each element
- **Optimization**: Uses combined operations (rr, rrr, ss) when beneficial

## 🧪 Testing

The project handles various edge cases:
- Already sorted arrays
- Reverse sorted arrays
- Duplicate numbers (error handling)
- Invalid input (non-numeric, overflow)
- Empty input
- Single element

### Performance Benchmarks
- **3 elements**: ≤ 3 operations
- **5 elements**: ≤ 12 operations
- **100 elements**: ≤ 700 operations (target: < 700)
- **500 elements**: ≤ 5500 operations (target: < 5500)

## 📈 Complexity Analysis

- **Time Complexity**: O(n²) in worst case, O(n log n) average
- **Space Complexity**: O(n) for stack storage
- **Operations Count**: Optimized to meet 42 School requirements

## 🏆 Bonus Features

The checker program validates if a sequence of operations correctly sorts the stack:
- Reads operations from standard input
- Executes them on the provided stack
- Returns "OK" if sorted, "KO" if not, "Error" for invalid input

## 🔗 Links

- **Author**: Ana Ternero
- **GitHub**: [anatermay](https://github.com/anatermay/)
- **42 Profile**: [aternero](https://profile.intra.42.fr/users/aternero)
- **Repository**: [42_malaga_](https://github.com/anatermay/42_malaga_)

## 🏆 Achievement

**Final Score**: 125/100 ✨

---

*This project was completed as part of the 42 School curriculum at 42 Málaga.*
