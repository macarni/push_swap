/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:57:15 by adrperez          #+#    #+#             */
/*   Updated: 2023/03/20 13:30:31 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//swap a - intercambia los dos primeros elementos encima del stack a. No hace nada si hay uno o menos elementos.

void	swap_a(t_node **lst)
{
	t_node	*first;
	t_node	*second;
	t_node	*aux;

	first = *lst;
	second = (*lst)->next;

	*lst = second; //el primero de la lista ahora es el segundo
	aux = second->next; //me guardo el tercero
	(*lst)->next = first; //hago que el segundo sea el primero que tengo gaurdado
	first->next = aux;
	
}