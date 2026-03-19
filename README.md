_This project has been created as part of the 42 curriculum by maaugust._

<div align="center">
  <img src="https://raw.githubusercontent.com/rfs-hybrid/42-Common-Core/main/assets/covers/cover-libft-bonus.png" alt="Libft Cover" width="100%" />
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
typedef struct      s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;
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

## 🧠 Concept & Logic Breakdown

To truly understand C, one must understand how data is manipulated at the byte level. Here is the core logic behind the different function categories:

### 1. Memory Manipulation (`void *` & `unsigned char`)
Functions like `ft_memset`, `ft_memcpy`, and `ft_memcmp` receive `void *` pointers so they can handle any data type (strings, structs, integer arrays). However, you cannot dereference or do math on a `void *`. 
* **The Logic:** We cast these pointers to `unsigned char *`. An `unsigned char` is exactly 1 byte (8 bits). This guarantees that our loops iterate and manipulate the memory address exactly **one byte at a time**, ensuring safe and predictable behavior regardless of the original data type.
* **The `ft_memmove` Safety Net:** Unlike `memcpy`, `memmove` checks if the source and destination memory blocks overlap. If the destination is *ahead* of the source, copying left-to-right would overwrite data before it gets copied. `memmove` solves this by copying backwards (right-to-left).

### 2. String Operations & Pointer Arithmetic
In C, strings are simply arrays of characters terminated by a Null-byte (`\0`). 
* **The Logic:** Functions like `ft_strlen` use pointer arithmetic (subtracting the base pointer from the end pointer) to calculate length instantly without needing an incremental integer counter.
* **Buffer Safety (`strlcpy` / `strlcat`):** Unlike older libc functions (`strcpy`), the `size-bounded` versions demand the total size of the destination buffer. They guarantee that the resulting string will always be null-terminated without overflowing into restricted memory segments, preventing Segmentation Faults.

### 3. Allocation & Dynamic Memory (`malloc` & `free`)
Part 2 introduces functions that create entirely new strings. 
* **The Logic (`ft_split`):** This function requires allocating an array of pointers (a 2D array). The core logic relies on heavily protecting the memory: if any single word fails to `malloc` midway through, a helper function must iterate backward, `free()` every previously allocated word, and finally free the parent array to prevent memory leaks.

### 4. Linked Lists (Non-Contiguous Memory)
Unlike arrays, which demand a single block of continuous memory, linked lists allocate memory dynamically wherever there is space on the heap.
* **The Logic:** Each node (`t_list`) contains two things: the actual data (`content`), and a pointer (`next`) holding the memory address of the subsequent node. Functions like `ft_lstlast` or `ft_lstadd_back` require traversing this chain using a `while (node->next != NULL)` loop to manually find the end before making adjustments.

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

### 🧪 Testing
The 42 subject highly encourages creating test programs to verify your work before peer evaluations. 

**1. Using a Custom Tester**
If you are using a custom `libft_tester.c` file, compile it alongside your library. (Using preprocessor macros like `-D` allows you to target specific tests if your tester is configured for it).
```bash
cc -Wall -Wextra -Werror -D TEST_PART_1 -D TEST_BONUS libft_tester.c libft.a -o tester
./tester
```
> **⚠️ WARNING for 42 Students:** Do not push `libft_tester.c` or any executable files to your final Moulinette repository! They are strictly for local testing purposes. Submitting unauthorized files will result in a 0.

**2. Third-Party Testers (Francinette)**
Francinette is a widely used testing framework within the 42 community that runs strict tests (including memory leak checks and edge cases) against your library.

* **Installation:** Follow the instructions on the [Francinette GitHub Repository](https://github.com/xicodomingues/francinette).
* **Usage:** Inside your repository root, run:
```bash
paco
```
*(Note: To include bonus functions, use `paco -b`. To enforce strict norm and timeout rules, use `paco -s`)*

### 🚨 The Norm
Moulinette relies on a program called `norminette` to check if your files comply with the 42 Norm. Every single `.c` and `.h` file, including bonus files, must pass this check. If there is a norm error, you will receive a 0.

**The 42 Header:**
Before writing any code, every file must start with the standard 42 header. `norminette` will automatically fail any file missing this specific signature.
```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:24:04 by maaugust          #+#    #+#             */
/*   Updated: 2025/04/09 16:21:38 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
```

Run the following command in the root of your repository before pushing to check all your files at once:
```bash
norminette -R CheckForbiddenSourceHeader
```

---

## 📚 Resources & References
* [C Library (libc) Man Pages](https://man7.org/linux/man-pages/dir_section_3.html)
* [Makefile Tutorial](https://makefiletutorial.com/)
* [42 Norm V4](https://cdn.intra.42.fr/pdf/pdf/96987/en.norm.pdf) - The strict coding standard for 42 C projects.
* [Official 42 Norminette Repository](https://github.com/42School/norminette) - The open-source linter enforcing the strict 42 coding standard.

### 🤖 AI Usage Guidelines
*Per the subject requirements:*
* **Tasks:** AI tools (e.g., ChatGPT, Copilot) were used strictly for generating documentation templates and explaining complex algorithm logic (e.g., linked list reversal logic).
* **Code:** No AI-generated code was directly copied into the project. All logic was manually implemented to ensure understanding of pointers and memory management.
