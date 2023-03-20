/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:58:53 by adrperez          #+#    #+#             */
/*   Updated: 2023/03/20 12:27:19 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Hacer una estructura en el header con el stack
//Guardar los numeros en el stack
//Imprimir el stack

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
	t_node	**list; //para modificar cosas (especialmente cosas de la lista, estilo borrar un nodo), doble puntero	
	t_node 	*aux;
	int	i;
	
	i = 1;
	list = malloc(sizeof(t_node*));
	*list = 0;
	while(i < argc)
	{
		new_node = malloc(sizeof(t_node));
		new_node->content = ft_atoi(argv[i++]);
		new_node->next = 0;
		printf("new_node->content %d\n", new_node->content);
		ft_lstadd_back(list, new_node);
		printf("list->content %d\n", (*list)->content);
	}
	
	aux = *list;
	while(aux)
	{
		printf("%d\n", aux->content);
		aux = aux->next;
	}
	return (0);
}