# 42_printf

<p align="center">
    <img src="https://github.com/alx-sch/42_printf/assets/134595144/f0c52cd6-4282-4a69-9b03-5befc5335003" alt="libft" />
</p>

A custom implementation of a simplied printf() function, employing variadic functions to handle various format specifiers.

## Features

- **Variadic Format Handling:** Supports a variable number of arguments using variadic functions.
- **Format Specifiers:** Accomodates commonly used format specifiers for printf():
    - **%c:**        Character
    - **%s:**        String
    - **%p:**        Pointer
    - **%d, %i:**    Decimal (signed)
    - **%u:** Usigned Decimal
    - **%x, %X:** Hexadecimal
    - **%%:** Percentage Sign
 - **Inclusion of Libft:** Leverages existing Libft functions to enhance code reusability, minimize redundancies, and ensure project coherence.
 - [**Error Handling**](#error-handling)**:** Manages invalid input formats or arguments in a controlled way.

## Variadic Functions
Variadic functions, also known as variable argument functions, allow users to pass different types and numbers of arguments to the function. Let's have a closer look at ft_printf() to understand this better:

- **Prototype:** `int ft_printf(const char *, ...)`
    - `int`: The function's return type, representing the number of characters printed, including newline characters, excluding NULL terminators (or '-1' in case of an error).
    - `const char *`: A pointer to the 'format string', which contains the content to be printed as well as format specifiers, working as placeholders.
    - `...`: The ellipsis (-> intentional omission of text) indicates that further arguments of any type and number can be accepted (also none). In the context of `ft_printf()`, variables replacing the format specifiers in the format string are expected here.
    - **Example Usage:**
      ```c
      int result = ft_printf("Hello, %s! You scored %d points.\n", "Betty", 42);
        // 'result' contains the number of characters printed by ft_printf -> 36
      ```
        - In the printout, variable arguments "Betty" (char *) and 42 (int) will be formatted by and replaced with the format specifiers %s and %d, respectively.
- **Variadic Macros:**
    - `va_list`: Is a data type representing a list of arguments, commonly used as a parameter for variadic functions `va_list args` is ....
    - `va_start(args, format)`:
 
## Error Handling 
It's important to notice that printf() behavior in certain edge cases (like not invalid format or argument input) is not defined and depends on the platform it's executed on. For example, I noticed the following differences, depending on :

| Case | Command | Printout Ubuntu | Printout MacOs |
| --- | --- | --- | --- |
| NULL pointer | `printf("->%p\n", (void*)ptr);`| `->(nil)` Return: 8 | `->0x0` Return: 6 |
| Invalid specifier | `printf("->%k\n", nbr);` | `->%k` Return: 5 | `->k` Return: 4 |
| % at EOF | `printf("->%");` | `->` Return: -1 | `->` Return: 2 |

## Acknowledgements

- XXX
- The project badge used is retrieved from [this repo](https://github.com/ayogun/42-project-badges) by Ali Ogun.
