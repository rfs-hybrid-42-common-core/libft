/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 20:01:08 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/19 20:14:47 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"

/* ========================================================================== */
/* TOGGLE SWITCHES                                                            */
/* (Uncomment these if compiling locally without -D flags in the terminal)    */
/* ========================================================================== */
// #define TEST_PART_1
// #define TEST_PART_2
// #define TEST_BONUS

/* ========================================================================== */
/* HELPER FUNCTIONS                                                           */
/* ========================================================================== */

/* --- Part 2 Helpers --- */
char	map_func(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	iter_func(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

/* --- Bonus Helpers --- */
t_list	*build_test_list(int size, char **strs)
{
	t_list	*head = NULL;
	t_list	*curr = NULL;
	for (int i = 0; i < size; i++)
	{
		t_list *new = malloc(sizeof(t_list));
		new->content = strs[i];
		new->next = NULL;
		if (!head)
			head = new;
		else
			curr->next = new;
		curr = new;
	}
	return (head);
}

void	print_list_str(t_list *list)
{
	while (list)
	{
		printf("[%s] -> ", (char *)list->content);
		list = list->next;
	}
	printf("NULL\n");
}

void	dummy_free(void *content)
{
	printf("(freed: %s) ", (char *)content);
}

void	print_str(void *content)
{
	printf("[%s] ", (char *)content);
}

void	*map_str_toupper(void *content)
{
	char *str = strdup((char *)content);
	int i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return ((void *)str);
}

/* ========================================================================== */
/* MAIN FUNCTION                                                              */
/* ========================================================================== */
int	main(void)
{
	printf("============================================================\n");
	printf("                   LIBFT COMPREHENSIVE TESTER               \n");
	printf("============================================================\n\n");

#ifdef TEST_PART_1
	printf("========================= PART 1 ===========================\n\n");

	printf("--- Character Checks ---\n");
	printf("ft_isalpha('A'): %d | Expected: >0\n", ft_isalpha('A'));
	printf("ft_isdigit('5'): %d | Expected: >0\n", ft_isdigit('5'));
	printf("ft_isalnum('Z'): %d | Expected: >0\n", ft_isalnum('Z'));
	printf("ft_isascii(128): %d | Expected: 0\n", ft_isascii(128));
	printf("ft_isprint(' '): %d | Expected: >0\n", ft_isprint(' '));
	printf("ft_toupper('a'): %c | Expected: A\n", ft_toupper('a'));
	printf("ft_tolower('Z'): %c | Expected: z\n\n", ft_tolower('Z'));

	printf("--- String Operations ---\n");
	printf("ft_strlen(\"42Porto\"): %zu | Expected: 7\n", ft_strlen("42Porto"));
	
	char strchr_test[] = "tripouille";
	printf("ft_strchr(\"tripouille\", 'p'): %s | Expected: pouille\n", ft_strchr(strchr_test, 'p'));
	printf("ft_strrchr(\"tripouille\", 'p'): %s | Expected: pouille\n", ft_strrchr(strchr_test, 'p'));
	printf("ft_strncmp(\"testA\", \"testB\", 4): %d | Expected: 0\n", ft_strncmp("testA", "testB", 4));
	printf("ft_strncmp(\"testA\", \"testB\", 5): %d | Expected: <0\n", ft_strncmp("testA", "testB", 5));
	
	char big[] = "Foo Bar Baz";
	printf("ft_strnstr(\"Foo Bar Baz\", \"Bar\", 11): %s | Expected: Bar Baz\n", ft_strnstr(big, "Bar", 11));

	char dest[20] = "Hello";
	printf("ft_strlcpy(dest, \" 42\", 20): %zu, dest: %s | Expected: 3, Hello 42\n", ft_strlcpy(dest + 5, " 42", 15), dest);
	
	char dest2[20] = "Hello ";
	printf("ft_strlcat(dest2, \"World\", 20): %zu, dest: %s | Expected: 11, Hello World\n\n", ft_strlcat(dest2, "World", 20), dest2);

	printf("--- Memory Operations ---\n");
	char mem1[10] = "abcdefghi";
	printf("ft_memset(mem1, 'z', 3): %s | Expected: zzzdefghi\n", (char *)ft_memset(mem1, 'z', 3));
	
	ft_bzero(mem1, 3);
	printf("ft_bzero(mem1, 3): %d %d %d %c | Expected: 0 0 0 d\n", mem1[0], mem1[1], mem1[2], mem1[3]);

	char mem2[10] = "123456789";
	printf("ft_memcpy(mem2, \"abc\", 3): %s | Expected: abc456789\n", (char *)ft_memcpy(mem2, "abc", 3));

	char mem3[10] = "123456789";
	printf("ft_memmove(mem3+2, mem3, 5): %s | Expected: 121234589\n", (char *)ft_memmove(mem3 + 2, mem3, 5));

	char mem4[] = "test memchr";
	printf("ft_memchr(\"test memchr\", 'm', 10): %s | Expected: memchr\n", (char *)ft_memchr(mem4, 'm', 10));
	printf("ft_memcmp(\"abc\", \"abz\", 3): %d | Expected: <0\n\n", ft_memcmp("abc", "abz", 3));

	printf("--- Conversion & Malloc ---\n");
	printf("ft_atoi(\"  -42\"): %d | Expected: -42\n", ft_atoi("  -42"));
	
	char *dup = ft_strdup("duplicate me");
	printf("ft_strdup(\"duplicate me\"): %s | Expected: duplicate me\n", dup);
	free(dup);

	int *cal = (int *)ft_calloc(3, sizeof(int));
	printf("ft_calloc(3, sizeof(int)): %d %d %d | Expected: 0 0 0\n\n", cal[0], cal[1], cal[2]);
	free(cal);
#endif

#ifdef TEST_PART_2
	printf("========================= PART 2 ===========================\n\n");

	printf("--- String Manipulations ---\n");
	char *sub = ft_substr("Hello World", 6, 5);
	printf("ft_substr(\"Hello World\", 6, 5): %s | Expected: World\n", sub);
	free(sub);

	char *join = ft_strjoin("42", "Porto");
	printf("ft_strjoin(\"42\", \"Porto\"): %s | Expected: 42Porto\n", join);
	free(join);

	char *trim = ft_strtrim("xxHello Worldxxx", "x");
	printf("ft_strtrim(\"xxHello Worldxxx\", \"x\"): %s | Expected: Hello World\n", trim);
	free(trim);

	char **split = ft_split("split  this string", ' ');
	printf("ft_split(\"split  this string\", ' '):\n");
	for (int i = 0; split && split[i]; i++)
	{
		printf("  [%d]: %s\n", i, split[i]);
		free(split[i]);
	}
	free(split);

	char *itoa_res = ft_itoa(-2147483648LL);
	printf("ft_itoa(-2147483648): %s | Expected: -2147483648\n\n", itoa_res);
	free(itoa_res);

	printf("--- Function Applications ---\n");
	char *mapi_res = ft_strmapi("hello", map_func);
	printf("ft_strmapi(\"hello\", map_func): %s | Expected: HELLO\n", mapi_res);
	free(mapi_res);

	char iteri_test[] = "world";
	ft_striteri(iteri_test, iter_func);
	printf("ft_striteri(\"world\", iter_func): %s | Expected: WORLD\n\n", iteri_test);

	printf("--- File Descriptor IO ---\n");
	printf("Outputting to stdout (fd 1):\n");
	printf("ft_putchar_fd('A', 1): "); ft_putchar_fd('A', 1); printf("\n");
	printf("ft_putstr_fd(\"Hello\", 1): "); ft_putstr_fd("Hello", 1); printf("\n");
	printf("ft_putendl_fd(\"Newline Test\", 1): "); ft_putendl_fd("Newline Test", 1);
	printf("ft_putnbr_fd(-42, 1): "); ft_putnbr_fd(-42, 1); printf("\n\n");
#endif

#ifdef TEST_BONUS
	printf("========================== BONUS ===========================\n\n");
	
	t_list *node1 = ft_lstnew("First");
	printf("ft_lstnew: [%s]\n", (char *)node1->content);

	t_list *node2 = ft_lstnew("Second");
	ft_lstadd_front(&node1, node2);
	printf("ft_lstadd_front: "); print_list_str(node1);

	t_list *node3 = ft_lstnew("Third");
	ft_lstadd_back(&node1, node3);
	printf("ft_lstadd_back: "); print_list_str(node1);

	printf("ft_lstsize: %d | Expected: 3\n", ft_lstsize(node1));
	printf("ft_lstlast: %s | Expected: Third\n", (char *)ft_lstlast(node1)->content);

	printf("ft_lstiter (print_str): "); ft_lstiter(node1, print_str); printf("\n");

	t_list *mapped = ft_lstmap(node1, map_str_toupper, free);
	printf("ft_lstmap (toupper): "); print_list_str(mapped);

	printf("ft_lstclear (mapped list): "); ft_lstclear(&mapped, dummy_free); printf("\n");
	printf("ft_lstclear (original list): "); ft_lstclear(&node1, dummy_free); printf("\n");
#endif

	return (0);
}
