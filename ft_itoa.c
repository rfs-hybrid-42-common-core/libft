/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:34:24 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/13 16:32:48 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/**
 * @fn char *ft_itoa(int n)
 * @brief Converts an integer to a string.
 * @details Allocates and returns a string representing the integer received as
 * an argument. Handles negative numbers.
 * @param n The integer to convert.
 * @return  The string representing the integer, or NULL if allocation fails.
 */
char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	size_t	len;

	nbr = n;
	len = get_len(nbr);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		str[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
