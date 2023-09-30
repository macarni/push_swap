/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:58:53 by adrperez          #+#    #+#             */
/*   Updated: 2023/09/30 17:32:24 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//TODO Para el radix https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
//TODO Info de Bri: https://picayune-piper-447.notion.site/Push_swap-bbeltran-07463a2c9f8349e5bcaf616a0160a447
//TODO funciona con 5 numeros, pasar ahora a radix

int	main(int argc, char **argv)
{
	
	t_node	**stack_a; //para modificar cosas (especialmente cosas de la stack_a, estilo borrar un nodo), doble puntero	
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
		//print_list(*stack_a);
	}
	//ft_freelist(stack_a);
	// free(stack_a);
	return (0);
}