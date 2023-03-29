/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:58:53 by adrperez          #+#    #+#             */
/*   Updated: 2023/03/29 20:05:41 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	
	t_node	**stack_a; //para modificar cosas (especialmente cosas de la stack_a, estilo borrar un nodo), doble puntero	
	t_node	*aux;
	int		stack_size;
	
	stack_a = 0;
	if (argc > 1)
	{
		stack_a = malloc(sizeof(t_node*));
		*stack_a = 0;
		if (!create_args(argv, stack_a))
			return (0);
		if (is_sorted(*stack_a) || has_duplicates(*stack_a))
		{	
			ft_freelist(stack_a);
			return (0);
		}
		stack_size = ft_lstsize(*stack_a);
		if(stack_size <= 5)
			sort_tiny_stack(stack_size, stack_a);
		aux = *stack_a;
		while(aux)
		{
			printf("Content: %lld ", aux->content);
			printf("Index: %d \n", aux->index);
			aux = aux->next;
		}
	}
	ft_freelist(stack_a);
	// free(stack_a);
	return (0);
}