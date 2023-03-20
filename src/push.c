/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:59:59 by adrperez          #+#    #+#             */
/*   Updated: 2023/03/20 15:55:05 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * push a - toma el primer elemento del stack b y lo pone encima del stack a. No hace nada si b está vacío.
 * push b - toma el primer elemento del stack a y lo pone encima del stack b. No hace nada si a está vacío.
 */

static void	ft_lstadd_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}

void	push(t_node **to, t_node **from)
{
	t_node	*first;
	t_node	*aux;
	
	if (*from || (*from)-> next)
	{
		first = *from;
		aux = (*from)->next;
		ft_lstadd_front(to, first);
		*from = aux; 
	}
}

