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

## Variadic Functions
Variadic functions, also known as variable argument functions, allow users to pass different types and numbers of arguments to the function. Let's have a closer look at ft_printf() to understand this better:

- **Prototype:** `int ft_printf(const char *, ...)`
    - `int`: The function's return type, representing the number of characters printed.
    - `const char *`: A pointer to the 'format string', which contains the content to be printed as well as format specifiers, working as placeholders.
    - `...`: The ellipsis (-> intentional omission of text) indicates that further arguments of any type and number can be accepted (also none). In the context of `ft_printf()`, variables replacing the format specifiers in the format string are expected here.
- **Example Usage:**
  ```c
  int result = ft_printf("Hello, %s! You scored %d points.", "Betty", 42);
  // 'result' contains the number of characters printed by ft_printf -> 35
  ```
    - Variable arugments: "Betty" (char *) and 42 (int).

## Acknowledgements

- XXX
- The project badge used is retrieved from [this repo](https://github.com/ayogun/42-project-badges) by Ali Ogun.
