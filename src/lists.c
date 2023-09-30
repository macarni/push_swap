/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:21:58 by adrperez          #+#    #+#             */
/*   Updated: 2023/09/30 16:36:21 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * The function `ft_lstadd_back` adds a new node to the end of a linked list.
 * 
 * @param lst A pointer to a pointer to the head of a linked list.
 * @param new The "new" parameter is a pointer to a t_node structure that represents the new node to be
 * added to the end of the linked list.
 */
void	ft_lstadd_back(t_node **lst, t_node *new)
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

/**
 * The function `ft_lstadd_front` adds a new node to the front of a linked list.
 * 
 * @param lst A pointer to a pointer to a t_node struct. This is a pointer to the head of the linked
 * list.
 * @param new The "new" parameter is a pointer to a node that we want to add to the front of the linked
 * list.
 */
void	ft_lstadd_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}

/**
 * The function `ft_lstnew` creates a new node for a linked list with the given content.
 * 
 * @param content The "content" parameter is an integer value that represents the data to be stored in
 * the new node of the linked list.
 * 
 * @return a pointer to a newly created t_node structure.
 */
t_node	*ft_lstnew(int content)
{
	t_node	*new_node;
	
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = 0;
	return (new_node);
}

t_node	*ft_last(t_node *lst)
{
	t_node *aux;

	aux = lst;
	while (aux->next)
		aux = aux->next;
	return(aux); 
}

int	ft_lstsize(t_node *lst)
{
	int		size;
	t_node	*aux;

	aux = lst;
	size = 1;
	if (!lst)
		return (0);
	while (aux->next != 0)
	{
		size++;
		aux = aux->next;
	}
	return (size);
}


void	ft_freelist(t_node **stack_a)
{
	t_node	*aux;

	aux = *stack_a;
	while (*stack_a)
	{
		aux = (*stack_a)->next;
		free(*stack_a);
		*stack_a = aux;
	}
	free(stack_a);
}

int	is_sorted(t_node *stack_a)
{
	t_node	*aux;

	aux = stack_a;
	while (aux->next)
	{
		if(aux->content > aux->next->content)
			return (0);
		aux = aux->next;
	}
	return (1);
}

//TODO Error aqui, don't know why
int	get_min_position(t_node *stack_a)
{
	int		index;
	int 	min;
	int		position;
	t_node	*aux;

	aux = stack_a;
	min = aux->content;
	index = -1;
	position = 0;
	while(aux)
	{
		index++;
		if (min > aux->content)
		{
			min = aux->content;
			position = index;
		}
		aux = aux->next;
	}
	return (position);
}

//TODO borrar funcion
void print_list(t_node *stack_a)
{
	t_node	*aux;
	
	aux = stack_a;
	while(aux)
	{
		printf("%lld ", aux->content);
		aux = aux->next;
	}
	printf("\n");
}

// void	map_indexes(t_node *stack_a)
// {
// 	int		num;
// 	t_node	*aux;
// 	t_node	*aux2;

// 	num = 0;
// 	aux = stack_a;
// 	aux2 = stack_a;
// 	while (aux)
// 	{
// 		num = aux->content;
// 		while(aux2)
// 		{
// 			if (num != aux2->content && num >= aux2->content)
// 				aux->index++;
// 			aux2 = aux2->next;
// 		}
// 		aux = aux->next;
// 	}

// }

// function(*n)
// while(stack_a)
// struct node* aux = n;
// free( stack_a );
// stack_a = aux->next;