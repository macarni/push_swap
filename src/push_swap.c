/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:58:53 by adrperez          #+#    #+#             */
/*   Updated: 2023/03/20 16:53:53 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_node 	*new_node;
	t_node	**stack_a; //para modificar cosas (especialmente cosas de la stack_aa, estilo borrar un nodo), doble puntero	
	t_node 	*aux;
	t_node	**stack_b;
	int	i;
	int num;
	
	i = 1;
	stack_a = malloc(sizeof(t_node*));
	*stack_a = 0;
	stack_b = malloc(sizeof(t_node*));
	*stack_b = 0;
	while(i < argc)
	{
		new_node = malloc(sizeof(t_node));
		new_node->content = ft_atoi(argv[i++]);
		new_node->next = 0;
		ft_lstadd_back(stack_a, new_node);
	}
	
	num = 43;
	i = 1;
	while(i < argc)
	{
		new_node = malloc(sizeof(t_node));
		new_node->content = num++;
		new_node->next = 0;
		ft_lstadd_back(stack_b, new_node);
		i++;
	}
	
	aux = *stack_a;
	printf("Stack_a \n");
	while(aux)
	{
		printf("%d\n", aux->content);
		aux = aux->next;
	}
	aux = *stack_b;
	printf("Stack_b \n");
	while(aux)
	{
		printf("%d\n", aux->content);
		aux = aux->next;
	}
	
	// swap(stack_a);

	// aux2 = *stack_a;
	// printf("Después del swap de stack_a \n");
	
	// while(aux2)
	// {
	// 	printf("%d\n", aux2->content);
	// 	aux2 = aux2->next;
	// }

	//push a
	// push(stack_a, stack_b);
	// printf("Después de push(stack_b, stack_a) \n");
	// printf("Stack_a: \n");
	// aux = *stack_a;
	// while(aux)
	// {
	// 	printf("%d\n", aux->content);
	// 	aux = aux->next;
	// }
	// printf("Stack_b: \n");
	// aux = *stack_b;
	// while(aux)
	// {
	// 	printf("%d\n", aux->content);
	// 	aux = aux->next;
	// }
	
	//rotate a
	// rotate(stack_a);
	// printf("Después de rotate(stack_a): \n");
	// aux = *stack_a;
	// while(aux)
	// {
	// 	printf("%d\n", aux->content);
	// 	aux = aux->next;
	// }

	//rotate_reverse a
	rotate_reverse(stack_a);
	printf("Después de rotate_reverse(stack_a): \n");
	aux = *stack_a;
	while(aux)
	{
		printf("%d\n", aux->content);
		aux = aux->next;
	}
	
	return (0);
}