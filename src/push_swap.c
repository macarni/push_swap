/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:58:53 by adrperez          #+#    #+#             */
/*   Updated: 2023/03/20 13:30:48 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_lstadd_back(t_node **lst, t_node *new)
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
		*lst = new;
}

int	main(int argc, char **argv)
{
	t_node 	*new_node;
	t_node	**stack_a; //para modificar cosas (especialmente cosas de la stack_aa, estilo borrar un nodo), doble puntero	
	t_node 	*aux;
	t_node 	*aux2;
	int	i;
	
	i = 1;
	stack_a = malloc(sizeof(t_node*));
	*stack_a = 0;
	while(i < argc)
	{
		new_node = malloc(sizeof(t_node));
		new_node->content = ft_atoi(argv[i++]);
		new_node->next = 0;
		printf("new_node->content %d\n", new_node->content);
		ft_lstadd_back(stack_a, new_node);
		printf("stack_a->content %d\n", (*stack_a)->content);
	}
	
	aux = *stack_a;
	printf("Antes \n");
	while(aux)
	{
		printf("%d\n", aux->content);
		aux = aux->next;
	}
	
	swap_a(stack_a);

	aux2 = *stack_a;
	printf("Después \n");
	
	while(aux2)
	{
		printf("%d\n", aux2->content);
		aux2 = aux2->next;
	}
	return (0);
}