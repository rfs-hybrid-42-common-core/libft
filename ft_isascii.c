/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:24:44 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/13 15:39:59 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @fn int ft_isascii(int c)
 * @brief Checks whether c is a 7-bit unsigned char value.
 * @details Tests if the character fits into the ASCII character set (0-127).
 * @param c The character to test.
 * @return Non-zero if the character is ASCII, 0 otherwise.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
