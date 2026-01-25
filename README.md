*This project has been created as part of the 42 curriculum by ysahnoun.*

## Description

**push_swap** is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations and the smallest number of moves possible. The program uses two stacks (a and b) and must sort stack a in ascending order.

The project implements an efficient sorting algorithm based on chunk/range sorting strategy:
- For small sets (2-5 numbers): Hardcoded optimal solutions
- For medium sets (6-100 numbers): 7 chunks of 15 elements each
- For large sets (100+ numbers): 15 chunks of 35 elements each

The algorithm intelligently selects elements from chunks, pushes them to stack b, and then reconstructs stack a in sorted order by pushing back the maximum elements first.

### Available Operations

- `sa` - swap the first two elements of stack a
- `sb` - swap the first two elements of stack b
- `ss` - sa and sb at the same time
- `pa` - push the top element from stack b to stack a
- `pb` - push the top element from stack a to stack b
- `ra` - rotate stack a (shift all elements up by one)
- `rb` - rotate stack b (shift all elements up by one)
- `rr` - ra and rb at the same time
- `rra` - reverse rotate stack a (shift all elements down by one)
- `rrb` - reverse rotate stack b (shift all elements down by one)
- `rrr` - rra and rrb at the same time

## Instructions

### Compilation
```bash
make
```

This will compile the project and create the `push_swap` executable.

### Usage
```bash
./push_swap [list of integers]
```

**Examples:**
```bash
# Simple example with 5 numbers
./push_swap 4 67 3 87 23

# Numbers can be passed as a single quoted string
./push_swap "4 67 3 87 23"

# Mix of both formats
./push_swap 4 67 "3 87" 23

# Large set of random numbers
./push_swap $(shuf -i 1-500 -n 500 | tr '\n' ' ')
```

The program outputs the list of operations needed to sort the stack. Each operation is printed on a new line.

### Error Handling

The program displays `Error\n` on stderr and exits in the following cases:
- Invalid arguments (non-numeric values)
- Integer overflow (numbers outside the int range)
- Duplicate numbers
- Empty input

### Testing

To verify the output is correct, you can use a checker program or pipe the operations:
```bash
# Count the number of operations
./push_swap 4 67 3 87 23 | wc -l

# Verify sorting with ARG (example)
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

## Resources

### Official Documentation
- [push_swap subject PDF] - Official 42 project requirements

### Algorithm & Data Structures
- [Sorting Algorithms Visualization](https://www.toptal.com/developers/sorting-algorithms) - Visual comparison of different sorting approaches
- [Stack Data Structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) - Understanding the core data structure
- [Doubly Linked Lists in C](https://www.geeksforgeeks.org/doubly-linked-list/) - Implementation reference

### AI Usage

AI assistance was used for:

AI was used to improve documentation clarity, check grammar, and provide explanations.
