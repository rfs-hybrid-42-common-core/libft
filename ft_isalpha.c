/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:24:04 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/19 15:39:43 by maaugust         ###   ########.fr       */
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
 * @fn int ft_isalpha(int c)
 * @brief Checks for an alphabetic character.
 * @details Tests if the character is either an uppercase or lowercase letter 
 * by utilizing internal static helper functions.
 * @param c The character to test.
 * @return  1 if the character is alphabetic, 0 otherwise.
 */
int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
