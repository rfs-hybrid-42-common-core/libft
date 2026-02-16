/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:40:24 by maaugust          #+#    #+#             */
/*   Updated: 2025/12/13 16:41:41 by maaugust         ###   ########.fr       */
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
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
