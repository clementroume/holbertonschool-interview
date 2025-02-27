# **Slide Line**

## **Description**

This project implements a function that **slides and merges** an array of integers, similar to the mechanics of the game **2048**. The function shifts numbers either **left** or **right**, merging adjacent equal values while maintaining the correct order.

## **Implementation Details**

The program processes a **one-dimensional line of integers** and follows these rules:

### **Sliding and Merging Rules**

1. **Numbers shift** in the chosen direction (**left** or **right**) until they meet a non-zero value or the edge of the array.
2. **Adjacent identical numbers** merge into a single value (sum of both).
3. **Each merge happens only once per move** (no chain reactions within the same operation).
4. **After merging, the remaining numbers shift again** to fill any gaps.

## **Files**

### `slide_line.h`

- Defines constants and function prototypes.

### `0-slide_line.c`

- Implements the core logic:
  - `slide_line(line, size, direction)`: Processes the given array, sliding and merging values in the specified direction.
  - `slide_left(line, size)`: Shifts and merges numbers towards the left.
  - `slide_right(line, size)`: Shifts and merges numbers towards the right.
  - `shift_left(line, size)`: Helper function to move numbers left without merging.
  - `shift_right(line, size)`: Helper function to move numbers right without merging.

### `0-main.c`

- Contains a test program that allows command-line execution.

## **Compilation and Execution**

Compile the program using:

```sh
gcc -Wall -Wextra -Werror -pedantic -std=c90 slide_line.c main.c -o slide_line
```

Run the executable with:

```sh
./slide_line <DIRECTION> <N1> <N2> <N3> ...
```

- DIRECTION: 'L' for left, 'R' for right.
- N1 N2 N3 ...: List of integers (up to 32 values).

### **Sliding Left (`L`)**

```sh
$ ./slide_line L 2 2 2 2
Line: 2, 2, 2, 2
Slide to the left
Line: 4, 4, 0, 0
```

### **Sliding Right (`R`)**

```sh
$ ./slide_line R 2 2 2 2
Line: 2, 2, 2, 2
Slide to the right
Line: 0, 0, 4, 4
```