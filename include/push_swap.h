/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pippex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:00:08 by adrperez          #+#    #+#             */
/*   Updated: 2023/02/13 12:12:41 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int			content;
	struct node	*next;
}	t_node;

int		main(int argc, char **argv);
int		ft_atoi(const char *str);
void	swap(t_node **lst);
void	push(t_node **stack_a, t_node **stack_b);
void	rotate(t_node **stack);
void	ft_lstadd_back(t_node **lst, t_node *new);
t_node	*ft_lstnew(int content);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	rotate_rr(t_node **stack_a, t_node **stack_b);
void	rotate_reverse(t_node **stack);
void	reverse_rr(t_node **stack_a, t_node **stack_b);
t_node	*ft_last(t_node *lst);

#endif