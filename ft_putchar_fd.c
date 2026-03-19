/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:35:32 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/19 16:07:03 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @fn void ft_putchar_fd(char c, int fd)
 * @brief Outputs the character 'c' to the given file descriptor.
 * @details Uses the write() system call to print a single character to the 
 * specified file descriptor (e.g., 1 for standard output, 2 for standard 
 * error).
 * @param c  The character to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
