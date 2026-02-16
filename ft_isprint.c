/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:24:57 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/13 15:41:10 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @fn int ft_isprint(int c)
 * @brief Checks for any printable character.
 * @details Includes space (ASCII 32) through tilde (ASCII 126).
 * @param c The character to test.
 * @return Non-zero if the character is printable, 0 otherwise.
 */
int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}
