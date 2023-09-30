/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:59:59 by adrperez          #+#    #+#             */
/*   Updated: 2023/09/30 17:01:26 by adrperez         ###   ########.fr       */
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
		first = *from; //me guarda el primero de la lista que es el que quiero pasar al otro stack
		aux = (*from)->next; //me guarda el segundo de la lista que es el que quiero que sea el primero
		first->next = 0; //pongo a nulo el siguiente del primero
		*from = aux; 
		if (*to == 0)
			*to = first;
		else 
			ft_lstadd_front(to, first); //añado el primero a la lista de destino
		
		ft_printf("%s\n", msg);
	}
}

