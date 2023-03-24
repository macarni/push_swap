/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:12:30 by adrperez          #+#    #+#             */
/*   Updated: 2023/03/24 18:33:27 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_three(t_node **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;
	if(first > second && second < third && first < third)
		swap(stack_a, "sa");
	else if (first > second && second > third)
	{
		swap(stack_a, "sa");
		rotate_reverse(stack_a, "rra");
	}
	else if (first > second && second < third)
		rotate(stack_a, "ra");
	else if (first < second && second > third && third > first)
	{
		swap(stack_a, "sa");
		rotate(stack_a, "ra");
	}
	else
		rotate_reverse(stack_a, "rra");
}

static void	sort_five(t_node **stack_a)
{
	t_node	**stack_b;

	stack_b = malloc(sizeof(t_node*));
	*stack_b = 0;
	push(stack_b, stack_a, "pb");
	push(stack_b, stack_a, "pb");
	sort_three(stack_a);
	//Esto no funsiona, de aqui pabajo arreglar
	push(stack_a, stack_b, "pa");
	rotate(stack_a, "ra");
	push(stack_a, stack_b, "pa");
	ft_freelist(stack_b);
}

void	sort_tiny_stack(int	size, t_node **stack_a)
{
	if (size == 2)
		swap(stack_a, "sa");
	if (size == 3)
		sort_three(stack_a);
	else
		sort_five(stack_a);
}