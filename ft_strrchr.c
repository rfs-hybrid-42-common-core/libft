/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:31:06 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/13 16:06:12 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @fn char *ft_strrchr(const char *s, int c)
 * @brief Locates the last occurrence of c (converted to a char) in the
 * string s.
 * @details The terminating null character is considered to be part of the
 * string.
 * @param s The string to search.
 * @param c The character to find.
 * @return A pointer to the located character, or NULL if the character does
 * not appear in the string.
 */
char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occurrence;

	last_occurrence = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_occurrence = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)last_occurrence);
}
