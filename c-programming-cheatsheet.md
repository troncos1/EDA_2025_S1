# C Programming Language Cheatsheet

## Basic Program Structure
```c
#include <stdio.h>  // Include header file

int main() {
    // Your code here
    return 0;       // Return value to OS
}
```

## Data Types
| Type | Description | Format Specifier | Example |
|------|-------------|------------------|---------|
| `int` | Integer | `%d` or `%i` | `int x = 10;` |
| `float` | Floating point | `%f` | `float x = 10.5f;` |
| `double` | Double precision float | `%lf` | `double x = 10.5;` |
| `char` | Single character | `%c` | `char c = 'A';` |
| `char[]` | String (array of chars) | `%s` | `char str[] = "Hello";` |
| `_Bool` | Boolean (C99) | `%d` | `_Bool flag = 1;` |
| `long` | Long integer | `%ld` | `long x = 1000000L;` |
| `long long` | Very long integer (C99) | `%lld` | `long long x = 10000000000LL;` |
| `unsigned int` | Unsigned integer | `%u` | `unsigned int x = 10U;` |

## Constants
```c
#define PI 3.14159         // Preprocessor constant
const double pi = 3.14159;  // Constant variable
```

## Operators
### Arithmetic Operators
| Operator | Description | Example |
|----------|-------------|---------|
| `+` | Addition | `a + b` |
| `-` | Subtraction | `a - b` |
| `*` | Multiplication | `a * b` |
| `/` | Division | `a / b` |
| `%` | Modulus (remainder) | `a % b` |
| `++` | Increment | `i++` or `++i` |
| `--` | Decrement | `i--` or `--i` |

### Comparison Operators
| Operator | Description | Example |
|----------|-------------|---------|
| `==` | Equal to | `a == b` |
| `!=` | Not equal to | `a != b` |
| `>` | Greater than | `a > b` |
| `<` | Less than | `a < b` |
| `>=` | Greater than or equal to | `a >= b` |
| `<=` | Less than or equal to | `a <= b` |

### Logical Operators
| Operator | Description | Example |
|----------|-------------|---------|
| `&&` | Logical AND | `a && b` |
| `\|\|` | Logical OR | `a \|\| b` |
| `!` | Logical NOT | `!a` |

### Bitwise Operators
| Operator | Description | Example |
|----------|-------------|---------|
| `&` | Bitwise AND | `a & b` |
| `\|` | Bitwise OR | `a \| b` |
| `^` | Bitwise XOR | `a ^ b` |
| `~` | Bitwise NOT | `~a` |
| `<<` | Left shift | `a << 1` |
| `>>` | Right shift | `a >> 1` |

### Assignment Operators
| Operator | Description | Example |
|----------|-------------|---------|
| `=` | Assign | `a = b` |
| `+=` | Add and assign | `a += b` |
| `-=` | Subtract and assign | `a -= b` |
| `*=` | Multiply and assign | `a *= b` |
| `/=` | Divide and assign | `a /= b` |
| `%=` | Modulus and assign | `a %= b` |
| `&=` | Bitwise AND and assign | `a &= b` |
| `\|=` | Bitwise OR and assign | `a \|= b` |
| `^=` | Bitwise XOR and assign | `a ^= b` |
| `<<=` | Left shift and assign | `a <<= b` |
| `>>=` | Right shift and assign | `a >>= b` |

## Control Structures
### If-Else Statement
```c
if (condition) {
    // Code executed if condition is true
} else if (another_condition) {
    // Code executed if another_condition is true
} else {
    // Code executed if all conditions are false
}
```

### Switch Statement
```c
switch (expression) {
    case value1:
        // Code for value1
        break;
    case value2:
        // Code for value2
        break;
    default:
        // Default code
        break;
}
```

### Loops
#### While Loop
```c
while (condition) {
    // Code executed while condition is true
}
```

#### Do-While Loop
```c
do {
    // Code executed at least once, then while condition is true
} while (condition);
```

#### For Loop
```c
for (initialization; condition; update) {
    // Code executed while condition is true
}

// Example:
for (int i = 0; i < 10; i++) {
    printf("%d ", i);
}
```

### Break and Continue
```c
// Break: exits the loop
for (int i = 0; i < 10; i++) {
    if (i == 5) break;
    printf("%d ", i);  // Prints 0 1 2 3 4
}

// Continue: skips the current iteration
for (int i = 0; i < 10; i++) {
    if (i == 5) continue;
    printf("%d ", i);  // Prints 0 1 2 3 4 6 7 8 9
}
```

## Functions
```c
// Function declaration (prototype)
return_type function_name(parameter_type parameter_name, ...);

// Function definition
return_type function_name(parameter_type parameter_name, ...) {
    // Function body
    return value;  // Return statement (if not void)
}

// Example:
int add(int a, int b) {
    return a + b;
}

// Void function (no return value)
void printMessage(char message[]) {
    printf("%s\n", message);
}
```

## Arrays
```c
// Declaration and initialization
int numbers[5];             // Declare array of 5 integers
int values[5] = {1, 2, 3, 4, 5};  // Declare and initialize
char name[] = "John";       // String (character array)

// Accessing elements (zero-indexed)
numbers[0] = 10;            // Set first element
int x = values[2];          // Get third element (value 3)

// Multidimensional arrays
int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
int value = matrix[1][2];  // Gets the value 6
```

## Strings
```c
// String declaration
char str1[20] = "Hello";
char str2[] = "World";

// String functions (include <string.h>)
strlen(str1);              // String length
strcpy(str1, str2);        // Copy str2 to str1
strcat(str1, str2);        // Concatenate str2 to str1
strcmp(str1, str2);        // Compare strings (0 if equal)
strchr(str1, 'e');         // Find character in string
strstr(str1, "ll");        // Find substring in string
```

## Pointers
```c
// Declaration and initialization
int x = 10;
int *ptr = &x;           // ptr holds the memory address of x

// Dereferencing (accessing the value)
int y = *ptr;           // y is now 10

// Pointer arithmetic
int arr[5] = {1, 2, 3, 4, 5};
int *p = arr;           // p points to the first element
printf("%d", *(p+2));   // Prints 3 (third element)

// Pointers and functions
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Using the swap function
int a = 5, b = 10;
swap(&a, &b);           // a is now 10, b is now 5
```

## Memory Management
```c
#include <stdlib.h>

// Dynamic memory allocation
int *ptr = (int*)malloc(5 * sizeof(int));  // Allocate memory for 5 integers
if (ptr == NULL) {
    // Handle allocation failure
}

// Using calloc (initializes memory to zero)
int *ptr2 = (int*)calloc(5, sizeof(int));

// Resizing allocated memory
ptr = (int*)realloc(ptr, 10 * sizeof(int));  // Resize to 10 integers

// Freeing memory
free(ptr);
free(ptr2);
ptr = NULL;  // Good practice after freeing
ptr2 = NULL;
```

## Structures
```c
// Define a structure
struct Person {
    char name[50];
    int age;
    float height;
};

// Declare and initialize
struct Person person1 = {"John", 30, 1.75};

// Access members
printf("Name: %s\n", person1.name);
person1.age = 31;

// Structure pointer
struct Person *pPerson = &person1;
printf("Age: %d\n", pPerson->age);  // Using arrow operator

// Typedef for cleaner syntax
typedef struct {
    char name[50];
    int age;
} Person;

Person p1 = {"Jane", 25};
```

## File I/O
```c
#include <stdio.h>

// Opening a file
FILE *file = fopen("file.txt", "r");  // Open for reading
if (file == NULL) {
    // Handle error
}

// Reading from a file
char buffer[100];
fgets(buffer, 100, file);  // Read a line

int num;
fscanf(file, "%d", &num);  // Read formatted data

char c = fgetc(file);      // Read a character

// Writing to a file
FILE *outFile = fopen("output.txt", "w");  // Open for writing
fprintf(outFile, "Hello %s\n", "World");  // Write formatted data
fputs("This is a line\n", outFile);       // Write a string
fputc('A', outFile);                      // Write a character

// Closing files
fclose(file);
fclose(outFile);
```

## Preprocessor Directives
```c
#include <stdio.h>     // Include standard library
#include "myheader.h"  // Include user-defined header

#define PI 3.14159     // Define a constant
#define SQUARE(x) ((x)*(x))  // Define a macro

#ifdef DEBUG           // Conditional compilation
    printf("Debug mode\n");
#endif

#ifndef BUFFER_SIZE    // If not defined
    #define BUFFER_SIZE 1024
#endif

#if LEVEL > 5          // If condition
    // Some code
#elif LEVEL > 3
    // Some other code
#else
    // Default code
#endif
```

## Common Standard Library Functions
### Input/Output (stdio.h)
```c
printf("Format string %d %f %s", int_var, float_var, str_var);  // Print to stdout
scanf("%d %f %s", &int_var, &float_var, str_var);              // Read from stdin
puts("String");       // Print string with newline
gets(str);           // Read string (unsafe, use fgets instead)
putchar('A');        // Print character
getchar();           // Read character
```

### Math Functions (math.h)
```c
sqrt(x);             // Square root
pow(x, y);           // x raised to power y
sin(x), cos(x), tan(x);  // Trigonometric functions
log(x), log10(x);    // Natural and base-10 logarithms
exp(x);              // e raised to power x
floor(x), ceil(x);   // Round down/up to nearest integer
fabs(x);             // Absolute value
```

### Character Functions (ctype.h)
```c
isalpha(c);          // Is c a letter
isdigit(c);          // Is c a digit
isalnum(c);          // Is c alphanumeric
islower(c), isupper(c);  // Check case
tolower(c), toupper(c);  // Convert case
```

### Utility Functions (stdlib.h)
```c
atoi(str);           // Convert string to integer
atof(str);           // Convert string to float
itoa(num, str, base);  // Convert integer to string (non-standard)
rand();              // Generate random number
srand(seed);         // Seed random number generator
qsort(arr, n, size, compare);  // Sort array
bsearch(key, arr, n, size, compare);  // Binary search
```

## Error Handling
```c
#include <errno.h>
#include <string.h>

// Check for errors after function calls
FILE *file = fopen("nonexistent.txt", "r");
if (file == NULL) {
    printf("Error: %s\n", strerror(errno));  // Print error message
}

// Use perror for standard error output
if (file == NULL) {
    perror("Error opening file");  // Prints: Error opening file: No such file or directory
}
```
