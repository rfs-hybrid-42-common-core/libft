_This project has been created as part of the 42 curriculum by maaugust._

<div align="center">
  <img src="assets/cover-libft-bonus.png" alt="Libft Cover" width="100%" />
</div>

<div align="center">
  <h1>🛠️ Libft: Your Very First Own Library</h1>
  <img src="https://img.shields.io/badge/Language-C-blue" />
  <img src="https://img.shields.io/badge/Grade-125%2F100-success" />
  <img src="https://img.shields.io/badge/Norminette-Passing-success" />
</div>

---

## 💡 Description
**Libft** is the first project of the 42 Common Core curriculum. It involves coding a custom C library (`libft.a`) from scratch to simulate the behavior of standard C library functions (libc).

The goal is to understand the low-level implementation of memory manipulation, string handling, and linked lists—fundamental skills for all future C projects at 42.

---

## 📑 Contents
This library is structured into three distinct parts complying with the project subject.

### 🔹 Part 1: Libc Re-implementation
_Standard C functions recoded with strict adherence to the original `man` descriptions._

| Memory | String Manipulation | Character Checks | Conversion/Output |
| :--- | :--- | :--- | :--- |
| `ft_memset` | `ft_strlen` | `ft_isalpha` | `ft_atoi` |
| `ft_bzero` | `ft_strlcpy` | `ft_isdigit` | `ft_toupper` |
| `ft_memcpy` | `ft_strlcat` | `ft_isalnum` | `ft_tolower` |
| `ft_memmove` | `ft_strchr` | `ft_isascii` | `ft_calloc` |
| `ft_memchr` | `ft_strrchr` | `ft_isprint` | `ft_strdup` |
| `ft_memcmp` | `ft_strncmp` | | |
| | `ft_strnstr` | | |

### 🔸 Part 2: Additional Functions
_Utility functions that are either missing from libc or exist in a different form._

| Function | Description |
| :--- | :--- |
| `ft_substr` | Allocates and returns a substring from the string `s`. |
| `ft_strjoin` | Allocates and returns a new string, result of the concatenation of `s1` and `s2`. |
| `ft_strtrim` | Allocates and returns a copy of `s1` with characters in `set` removed from start/end. |
| `ft_split` | Allocates and returns an array of strings obtained by splitting `s` using `c` as delimiter. |
| `ft_itoa` | Allocates and returns a string representing the integer received as an argument. |
| `ft_strmapi` | Applies function `f` to each char of string `s` to create a new string. |
| `ft_striteri` | Applies function `f` to each char of string `s` by address (modifying in place). |
| `ft_putchar_fd` | Outputs the character `c` to the given file descriptor. |
| `ft_putstr_fd` | Outputs the string `s` to the given file descriptor. |
| `ft_putendl_fd` | Outputs the string `s` to the given file descriptor followed by a newline. |
| `ft_putnbr_fd` | Outputs the integer `n` to the given file descriptor. |

### 🚀 Bonus Part: Linked Lists
_Functions to manipulate memory using the `t_list` structure._

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;
```

| Function | Description |
| :--- | :--- |
| `ft_lstnew` | Creates a new list node. |
| `ft_lstadd_front` | Adds a new node at the beginning of the list. |
| `ft_lstsize` | Counts the number of nodes in a list. |
| `ft_lstlast` | Returns the last node of the list. |
| `ft_lstadd_back` | Adds a new node at the end of the list. |
| `ft_lstdelone` | Deletes and frees a single node. |
| `ft_lstclear` | Deletes and frees a node and all its successors. |
| `ft_lstiter` | Iterates the list and applies a function to the content of each node. |
| `ft_lstmap` | Iterates the list and applies a function to create a new list. |

---

## 🛠️ Instructions

### 📦 Installation
To compile the library, run the following command in the root of the repository:

```bash
make
```

To compile the library **including the bonus functions**:

```bash
make bonus
```

This will generate the `libft.a` archive file.

### 🧹 Cleaning
* `make clean`: Removes object files (`.o`).
* `make fclean`: Removes object files and the `libft.a` library.
* `make re`: Performs a clean re-build.

### 💻 Usage
To use this library in your code, include the header and link the archive during compilation:

**1. Include header:**
```c
#include "libft.h"

int main()
{
    ft_putstr_fd("Hello, 42!", 1);
    return (0);
}
```

**2. Compile:**
```bash
cc main.c -L. -lft -o my_program
```

---

## 📚 Resources & References
* [C Library (libc) Man Pages](https://man7.org/linux/man-pages/dir_section_3.html)
* [Makefile Tutorial](https://makefiletutorial.com/)

### 🤖 AI Usage Guidelines
*Per the subject requirements:*
* **Tasks:** AI tools (e.g., ChatGPT, Copilot) were used strictly for generating documentation templates and explaining complex algorithm logic (e.g., linked list reversal logic).
* **Code:** No AI-generated code was directly copied into the project. All logic was manually implemented to ensure understanding of pointers and memory management.
