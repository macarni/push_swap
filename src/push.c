/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:59:59 by adrperez          #+#    #+#             */
/*   Updated: 2023/04/06 20:41:52 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * push a - toma el primer elemento del stack b y lo pone encima del stack a. No hace nada si b está vacío.
 * push b - toma el primer elemento del stack a y lo pone encima del stack b. No hace nada si a está vacío.
 */

void	push(t_node **to, t_node **from, char *msg)
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
	ft_printf("%s\n", msg);
}

