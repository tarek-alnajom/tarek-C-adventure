# Day 1: Introduction to C Programming

## Theory
### What is C? Why is it Important?
- **C** is a general-purpose, procedural programming language developed by Dennis Ritchie in 1972 at Bell Labs.
- **Importance**:
  - Foundation for many modern languages (C++, Java, Python).
  - Used in operating systems (e.g., Linux kernel), embedded systems, and performance-critical applications.
  - Teaches low-level memory management and program structure.
  - Fast and efficient due to its close-to-hardware nature.

### Structure of a C Program
- A C program typically includes:
  - **Preprocessor Directives**: `#include <stdio.h>` to include standard input/output library.
  - **Main Function**: `int main() { ... }` is the entry point where execution begins.
  - **Curly Braces `{}`**: Define the scope of code blocks.
  - Example:
    ```c
    #include <stdio.h>
    int main() {
        printf("Hello, World!\n");
        return 0;
    }
    ```
  - **Explanation**:
    - `#include <stdio.h>`: Allows use of `printf` and `scanf`.
    - `int main()`: Returns an integer (0 for success).
    - `printf()`: Outputs text to the console.
    - `return 0`: Signals successful program execution.

### How to Compile and Run Programs
- **Steps**:
  1. Write code in a `.c` file (e.g., `program.c`) using a text editor (VS Code, Notepad++).
  2. Compile using a compiler like GCC: `gcc program.c -o program`.
  3. Run the executable: `./program` (Linux/Mac) or `program.exe` (Windows).
- **Tools**:
  - Install GCC (MinGW for Windows, or use Linux/Mac terminal).
  - Online compilers: Replit, OnlineGDB for quick testing.

## Practical
### Advanced printf()
- Used to format and display output.
- **Format Specifiers**:
  - `%d`: Integer
  - `%s`: String
  - `%f`: Float (e.g., `%.2f` for 2 decimal places)
  - `%c`: Character
- Example: `printf("Name: %s, Age: %d\n", "Alice", 25);`
- Features: Control alignment, padding, and precision (e.g., `%10s` for right-aligned string).

### Advanced scanf()
- Used to read user input.
- Syntax: `scanf("%d", &variable);` (Note: `&` is used to pass the variable's memory address).
- **Format Specifiers**
  - `%[^.]`: Reads characters until a dot (`.`) is encountered.
  - `%*c`: Skips a single character (used to skip the dot and `@`).
  - `%[^@]`: Reads characters until an `@` symbol is encountered.
  - `%[^\n]`: Reads the remaining characters until a newline is encountered.
- Example:
  - `scanf("%d %s", &num, name);` to read an integer and string.
  - `scanf("%[^@]%*c%[^\n]", username, domain);` Reads characters until @, skips     @, then reads the rest of the line
- Features: Can read multiple inputs in one line, handles different data types.

## Recommended Learning Resources
- **Video**: [The Bro Code - C Programming Tutorial for Beginners (1:45:00)](https://www.youtube.com/watch?v=87SH2Cn0s9A)
  - Covers basics of C, including `printf`, `scanf`, and program structure.
  - Clear, beginner-friendly explanations with examples.
- **Alternative Resource**: [freeCodeCamp - Learn C Programming](https://www.youtube.com/watch?v=87SH2Cn0s9A)
  - Comprehensive, includes setup and I/O basics.
- **Text Resource**: [GeeksforGeeks - C Programming Basics](https://www.geeksforgeeks.org/c-programming-language/)
  - Detailed articles on `printf`, `scanf`, and program structure.
- **Interactive**: [Programiz - C Tutorial](https://www.programiz.com/c-programming)
  - Step-by-step examples with online compiler.

## Notes for Practice
- Experiment with `printf` format specifiers to control output (e.g., `%10d` for spacing).
- Practice `scanf` with multiple inputs and validate user input.
- Set up a local compiler (e.g., GCC) or use an online IDE to test code.
- Focus on understanding error messages during compilation (e.g., missing semicolon).
