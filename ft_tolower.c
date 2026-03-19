/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:30:43 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/19 16:00:11 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @fn static int ft_isupper(int c)
 * @brief Checks if a character is an uppercase letter.
 * @details Evaluates whether the passed integer corresponds to an uppercase 
 * letter in the ASCII table ('A' through 'Z').
 * @param c The character to test.
 * @return  1 if the character is uppercase, 0 otherwise.
 */
static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

/**
 * @fn int ft_tolower(int c)
 * @brief Converts an uppercase letter to lowercase.
 * @details If the passed character is an uppercase letter, it converts it to 
 * its lowercase equivalent by adding the ASCII offset difference.
 * @param c The character to convert.
 * @return  The corresponding lowercase letter if c is uppercase; 
 * otherwise, the argument is returned unchanged.
 */
int	ft_tolower(int c)
{
	if (ft_isupper(c))
		c += 'a' - 'A';
	return (c);
}
