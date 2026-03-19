/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:30:32 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/19 16:00:26 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @fn static int ft_islower(int c)
 * @brief Checks if a character is a lowercase letter.
 * @details Evaluates whether the passed integer corresponds to a lowercase 
 * letter in the ASCII table ('a' through 'z').
 * @param c The character to test.
 * @return  1 if the character is lowercase, 0 otherwise.
 */
static int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

/**
 * @fn int ft_toupper(int c)
 * @brief Converts a lowercase letter to uppercase.
 * @details If the passed character is a lowercase letter, it converts it to 
 * its uppercase equivalent by subtracting the ASCII offset difference.
 * @param c The character to convert.
 * @return  The corresponding uppercase letter if c is lowercase; 
 * otherwise, the argument is returned unchanged.
 */
int	ft_toupper(int c)
{
	if (ft_islower(c))
		c -= 'a' - 'A';
	return (c);
}
