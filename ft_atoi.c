/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:31:52 by maaugust          #+#    #+#             */
/*   Updated: 2026/02/16 18:38:30 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @fn static int ft_isspace(int c)
 * @brief Checks for white-space characters.
 * @details Includes: space, form-feed ('\f'), newline ('\n'),
 * carriage return ('\r'), horizontal tab ('\t'), and vertical tab ('\v').
 * @param c The character to test.
 * @return Non-zero if the character is whitespace, 0 otherwise.
 */
static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

/**
 * @fn int ft_atoi(const char *nptr)
 * @brief Converts the initial portion of the string pointed to by nptr to int.
 * @details Skips whitespace, checks for an optional sign, and processes digits.
 * @param nptr The string to convert.
 * @return The converted integer value.
 */
int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign *= -1;
	while (ft_isdigit(*nptr))
		res = res * 10 + (*nptr++ - '0');
	return (res * sign);
}
