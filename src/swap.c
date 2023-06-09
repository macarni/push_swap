/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:57:15 by adrperez          #+#    #+#             */
/*   Updated: 2023/03/24 17:48:36 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//swap a (sa) - intercambia los dos primeros elementos encima del stack a. No hace nada si hay uno o menos elementos.
//swap b (sb) - intercambia los dos primeros elementos encima del stack b. No hace nada si hay uno o menos elementos.

void	swap(t_node **lst, char *msg)
{
	t_node	*first;
	t_node	*second;
	t_node	*aux;

	if (*lst || (*lst)-> next)
	{
		first = *lst;
		second = (*lst)->next;

		*lst = second; //el primero de la lista ahora es el segundo
		aux = second->next; //me guardo el tercero
		(*lst)->next = first; //hago que el segundo sea el primero que tengo gaurdado
		first->next = aux;
	}
	ft_printf("%s\n", msg);
}