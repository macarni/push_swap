/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:21:58 by adrperez          #+#    #+#             */
/*   Updated: 2023/03/29 21:03:00 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}

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