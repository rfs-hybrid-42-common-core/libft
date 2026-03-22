/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:40:52 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/22 03:53:13 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @fn int ft_lstsize(t_list *lst)
 * @brief Counts the number of nodes in a list.
 * @details Iterates through the linked list sequentially, incrementing a 
 * counter for each node encountered.
 * @param lst The beginning of the list.
 * @return    The length of the list.
 */
int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
