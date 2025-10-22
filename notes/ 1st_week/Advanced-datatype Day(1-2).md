# Data Types in C

Data types in C define the kind of data a variable can hold, determining its size, range, and valid operations. C provides basic, derived, and user-defined types, with no built-in support for high-level types like strings or objects (handled via libraries or manual implementation).

## Basic (Primitive) Data Types
These are the fundamental building blocks in C, directly supported by the language.

### 1. Character Types
- **Description**: Represent single characters (e.g., ASCII) or small integers. `char` is a distinct integral type, separate from other integer types, but can be used in arithmetic operations like integers.
- **Types**:
  - **`char`**: 1 byte (8 bits), used for ASCII characters or small integers.
    - Range: -128 to 127 (signed) or 0 to 255 (unsigned), depending on implementation (signedness of `char` is platform-dependent unless explicitly `signed char` or `unsigned char`).
    - Example: `char c = 'A';` (ASCII character) or `char x = 65;` (integer value for 'A').
  - **`signed char`**: Explicitly signed, 1 byte.
    - Range: -128 to 127.
    - Example: `signed char sc = -100;`
  - **`unsigned char`**: Explicitly unsigned, 1 byte.
    - Range: 0 to 255.
    - Example: `unsigned char uc = 200;`
- **Use**: Storing characters (e.g., text), small integers, or raw byte data.
- **Note**: `char` is distinct from `int`, but as an integral type, it supports arithmetic (e.g., `c + 1`).

### 2. Integer Types
- **Description**: Represent whole numbers without decimal points. Variants depend on size and signedness.
- **Types**:
  - **`short`**: Typically 2 bytes (16 bits).
    - Range: -32,768 to 32,767 (signed) or 0 to 65,535 (unsigned).
    - Example: `short s = -5000;`
  - **`int`**: Typically 4 bytes (32 bits) on modern systems.
    - Range: -2,147,483,648 to 2,147,483,647 (signed) or 0 to 4,294,967,295 (unsigned).
    - Example: `int i = 1000;`
  - **`long`**: 4 or 8 bytes, depending on the system.
    - Range: Varies (e.g., -2^31 to 2^31-1 for 4 bytes).
    - Example: `long l = 123456789L;`
  - **`long long`** (C99): At least 8 bytes.
    - Range: -2^63 to 2^63-1 (signed).
    - Example: `long long ll = 1234567890123LL;`
- **Use**: Arithmetic, counters, indexing.
- **Modifiers**: `signed`, `unsigned` control range; `short`, `long` adjust size.

### 3. Floating-Point Types
- **Description**: Represent real numbers with decimal points, using IEEE 754 standard.
- **Types**:
  - **`float`**: Single precision, typically 4 bytes.
    - Range: ~1.2E-38 to 3.4E+38 (6-7 decimal digits precision).
    - Example: `float f = 3.14159f;`
  - **`double`**: Double precision, typically 8 bytes.
    - Range: ~2.3E-308 to 1.7E+308 (15-16 decimal digits precision).
    - Example: `double d = 3.141592653589793;`
  - **`long double`**: Extended precision, size varies (e.g., 10 or 16 bytes).
    - Range: Platform-dependent, higher precision than `double`.
    - Example: `long double ld = 3.14159265358979323846L;`
- **Use**: Scientific calculations, measurements, graphics.

### 4. Void
- **Description**: Represents the absence of a type.
- **Use**: Used in functions with no return value or generic pointers.
- **Example**:
  ```c
  void printHello() { printf("Hello\n"); }
  void* ptr;
  ```
### 5. Structure (struct)
- **Description**: Groups variables of different types into a single unit.
- **Example**:
  ```c
  struct Person {
      char name[50];
      int age;
      float height;
  };
  struct Person p = {"Alice", 25, 1.65f};
  ```
- **Size**: Sum of member sizes, possibly padded for alignment.
- **Use**: Modeling complex entities (e.g., records, objects).
- **Note**: Members are accessed via `.` (direct) or `->` (via pointer).

### 6. Union
- **Description**: Stores different types in the same memory location, but only one at a time.
- **Example**:
  ```c
  union Data {
      int i;
      float f;
      char c;
  };
  union Data d; d.i = 10; // Only i is valid now
  ```
- **Size**: Size of the largest member, padded if needed.
- **Use**: Memory-efficient storage, type punning (with caution).

### 7. Enum (Enumerated Type)
- **Description**: Defines a set of named integer constants.
- **Example**:
  ```c
  enum Color { RED, GREEN, BLUE };
  enum Color c = RED; // c = 0
  ```
- **Size**: Typically `int` (4 bytes).
- **Use**: Readable constants, state machines.
- **Note**: Values are assigned automatically (starting from 0) unless specified.

### 8. Typedef
- **Description**: Creates an alias for an existing type, improving readability or portability.
- **Example**:
  ```c
  typedef unsigned long ulong;
  ulong x = 123456;
  typedef struct {
      int x, y;
  } Point;
  Point p = {10, 20};
  ```
- **Use**: Simplifying complex type declarations (e.g., function pointers, structs).

## Special Notes
- **Size and Range Variability**: Sizes (e.g., `int`, `long`) depend on the compiler and architecture (e.g., 32-bit vs. 64-bit). Use `<stdint.h>` for fixed-size types like `int32_t`, `uint8_t`.
- **No Built-in Boolean**: C89/C90 lacks a `bool` type; use `int` (0 for false, non-zero for true). C99 introduces `_Bool` and `<stdbool.h>` for `bool`, `true`, `false`.
- **No String Type**: Strings are implemented as `char` arrays terminated by `'\0'` (e.g., `char str[] = "hello";`).
- **Memory Management**: C requires manual memory management for dynamic data (e.g., using `malloc`/`free` for pointers/arrays).
- **Type Qualifiers**: `const`, `volatile`, `restrict` modify type behavior (e.g., `const int x = 10;` prevents modification).

## Advanced Considerations
- **Bit Fields**: Used in structs to specify exact bit sizes for members.
  - Example: `struct { unsigned int flag : 1; }` (1-bit field).
  - Use: Low-level programming, memory optimization.
- **Complex Numbers** (C99): `<complex.h>` provides `float complex`, `double complex` for complex number arithmetic.
- **Atomic Types** (C11): `<stdatomic.h>` supports thread-safe operations (e.g., `_Atomic int`).
- **Alignment**: Compilers may add padding to structs for efficient memory access; use `alignas` (C11) for control.
- **Type Safety**: C is weakly typed, so type casting (e.g., `(float)i`) is common but error-prone.
