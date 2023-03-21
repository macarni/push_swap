/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:21:58 by adrperez          #+#    #+#             */
/*   Updated: 2023/03/21 16:05:11 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node *aux;

	aux = *lst;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	else
	{
		printf("entro");
		*lst = new;
	}
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}

t_node	*ft_lstnew(int content)
{
	t_node	*new_node;
	
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = 0;
	return (new_node);
}

t_node	*ft_last(t_node *lst)
{
	t_node *aux;

	aux = lst;
	while (aux->next)
		aux = aux->next;
	return(aux); 
}
