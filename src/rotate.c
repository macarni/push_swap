/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:01:30 by adrperez          #+#    #+#             */
/*   Updated: 2023/03/20 17:02:47 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * rotate a (ra) - desplaza hacia arriba todos los elementos del stack a una posición, de forma que el primer elemento se convierte en el último.
 * rotate b (rb) - desplaza hacia arriba todos los elementos del stack b una posición, de forma que el primer elemento se convierte en el último.
 * rotate a y rotate b (rr) - desplaza al mismo tiempo todos los elementos del stack a y del stack b una posición hacia arriba, de forma que el primer elemento se convierte en el último.
 * reverse rotate a (rra) - desplaza hacia abajo todos los elementos del stack a una posición, de forma que el último elemento se convierte en el primero.
 * reverse rotate b (rrb) - desplaza hacia abajo todos los elementos del stack b una posición, de forma que el último elemento se convierte en el primero.
 * reverse rotate a y reverse rotate b (rrr) - desplaza al mismo tiempo todos los elementos del stack a y del stack b una posición hacia abajo, de forma que el último elemento se convierte en el primero.
 * 
 */

void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	first = *stack;
	*stack = (*stack)->next;
	last = ft_lstnew(first->content);
	ft_lstadd_back(stack, last);
	free(first);
}

void	rotate_reverse(t_node **stack) //arreglar rotate_reverse, not working, hace falta poner un 0 a final de la lista después de haber recogido el ultimo nodo
{
	t_node	*aux;
	t_node	*last;
	t_node	*aux2;

	aux = *stack;
	aux2 = *stack;
	while(aux->next && aux2->next)
	{
		aux = aux->next; //guardo el ultimmo
		aux2 = aux2->next;
	}
	last = ft_lstnew(aux->content);
	aux2->next = 0;
	ft_lstadd_front(stack, last);
	free(aux);
}

void	rotate_rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	reverse_rr(t_node **stack_a, t_node **stack_b)
{
	rotate_reverse(stack_a);
	rotate_reverse(stack_b);
}