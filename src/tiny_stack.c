/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:12:30 by adrperez          #+#    #+#             */
/*   Updated: 2023/03/24 17:27:15 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_two(t_node **stack_a)
{
	if((*stack_a)->content > ((*stack_a)->next)->content)
	{
		rotate(stack_a, "ra");
	}
}

void	sort_tiny_stack(int	size, t_node **stack_a)
{
	if (size == 2)
		sort_two(stack_a);
}