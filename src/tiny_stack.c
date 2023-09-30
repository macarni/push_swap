/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:12:30 by adrperez          #+#    #+#             */
/*   Updated: 2023/09/30 17:33:20 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * 3 numbers -> 1 or 2 movements
 * 5 numbers -> max 12 movements
 * 100 numbers -> max 1500
 * 500 -> max 11500
 * 
 * @param stack_a 
 */

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

static void	move_min_to_stack_b(t_node **stack_a, t_node **stack_b, int size)
{
	int		min;
	
	min = get_min_position(*stack_a);
	if (min == size - 1)
		rotate_reverse(stack_a, "rra");
	else if (size == 5 && min == size - 2)
	{
		rotate_reverse(stack_a, "rra");
		rotate_reverse(stack_a, "rra");
	} 
	else
	{
		while (min > 0)
		{
			rotate(stack_a, "ra");
			min--;
		}
	}
	push(stack_b, stack_a, "pb");
}

static void	sort_five(t_node **stack_a)
{
	t_node	**stack_b;
	int		size;

	//int		*min_2;

	size = 5;
	stack_b = malloc(sizeof(t_node*));
	*stack_b = 0;
	
	//TODO Quitar el index del struct? de momento no se usa
	if (size == 5)
		move_min_to_stack_b(stack_a, stack_b, size--);
	// printf("stack a:");
	// print_list(*stack_a);
	// printf("stack b:");
	// print_list(*stack_b);
	move_min_to_stack_b(stack_a, stack_b, size);
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	push(stack_a, stack_b, "pa");
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