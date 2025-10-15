# Email Parser in C

This program is a simple C application that parses an email address provided by the user in the format `firstname.lastname@domain` and extracts the first name, last name, and domain. It demonstrates fundamental concepts of C programming, including input/output operations, string handling, and the use of `scanf` for parsing structured input.

## Table of Contents
1. [Program Overview](#program-overview)
2. [Key Concepts Covered](#key-concepts-covered)
   - [Standard Input/Output](#standard-inputoutput)
   - [String Handling](#string-handling)
   - [scanf Format Specifiers](#scanf-format-specifiers)
   - [Character Arrays](#character-arrays)
   - [Input Parsing](#input-parsing)
3. [How the Program Works](#how-the-program-works)
4. [Code Breakdown](#code-breakdown)
5. [Example Usage](#example-usage)
6. [Limitations](#limitations)
7. [How to Compile and Run](#how-to-compile-and-run)
8. [Potential Improvements](#potential-improvements)

## Program Overview
The program prompts the user to enter an email address in the format `firstname.lastname@domain` (e.g., `john.doe@example.com`). It then uses the `scanf` function to parse the input into three components:
- **First Name**: The portion before the dot (e.g., `john`).
- **Last Name**: The portion between the dot and the `@` symbol (e.g., `doe`).
- **Domain**: The portion after the `@` symbol (e.g., `example.com`).

These components are stored in separate character arrays and printed back to the user.

## Key Concepts Covered

### Standard Input/Output
- The program uses the `stdio.h` library for input/output operations.
- `printf` is used to display the prompt and the parsed results.
- `scanf` is used to read input from the user.

### String Handling
- The program processes strings (sequences of characters) to extract meaningful parts of the email address.
- Strings are stored in character arrays (`char[]`).

### scanf Format Specifiers
- The program uses advanced `scanf` format specifiers to parse the input string:
  - `%[^.]`: Reads characters until a dot (`.`) is encountered.
  - `%*c`: Skips a single character (used to skip the dot and `@`).
  - `%[^@]`: Reads characters until an `@` symbol is encountered.
  - `%[^\n]`: Reads the remaining characters until a newline is encountered.

### Character Arrays
- The program declares three character arrays (`first`, `last`, `domain`) to store the parsed components of the email address.
- Each array is allocated a fixed size (`50` for `first` and `last`, `100` for `domain`) to prevent buffer overflow for typical inputs.

### Input Parsing
- The program demonstrates how to parse structured input (an email address) by using delimiters (`.` and `@`) to split the input into meaningful parts.

## How the Program Works
1. The program declares three character arrays: `first`, `last`, and `domain` to store the parsed components of the email address.
2. It prompts the user to enter an email address using `printf`.
3. The `scanf` function is used with a custom format string to:
   - Read the first name (up to the dot).
   - Skip the dot.
   - Read the last name (up to the `@` symbol).
   - Skip the `@` symbol.
   - Read the domain (up to the newline).
4. The parsed components are printed back to the user using `printf`.
5. The program exits with a return value of `0`, indicating successful execution.

## Code Breakdown
```c
#include <stdio.h>

int main() {
    char first[50], last[50], domain[100];

    printf("Enter your email (format: firstname.lastname@domain): ");
    scanf("%[^.]%*c%[^@]%*c%[^\n]", first, last, domain);
    // %[^.]  → read until '.'  (firstname)
    // %*c    → skip the dot
    // %[^@]  → read until '@'  (lastname)
    // %*c    → skip @
    // %[^\n] → read rest of line (domain)

    printf("\nFirst Name: %s\nLast Name: %s\nDomain: %s\n", first, last, domain);
    return 0;
}
