/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:40:24 by maaugust          #+#    #+#             */
/*   Updated: 2026/03/19 15:39:13 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @fn t_list *ft_lstnew(void *content)
 * @brief Allocates and returns a new node.
 * @details The member variable 'content' is initialized with the value of the
 * parameter 'content'. The variable 'next' is initialized to NULL.
 * @param content The content to create the new node with.
 * @return        The new node, or NULL if the allocation fails.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
