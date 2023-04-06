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
#include "../utils/ft_printf/ft_printf.h"

typedef struct node
{
	long long	content;
	int			is_min;
	int			is_max;
	int			index;
	struct node	*next;
}	t_node;

int		main(int argc, char **argv);
int		ft_atoi(const char *str);
void	swap(t_node **lst, char *msg);
void	push(t_node **to, t_node **from, char *msg);
void	rotate(t_node **stack, char *msg);
void	ft_lstadd_back(t_node **lst, t_node *new);
t_node	*ft_lstnew(int content);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	rotate_rr(t_node **stack_a, t_node **stack_b);
void	rotate_reverse(t_node **stack, char *msg);
void	reverse_rr(t_node **stack_a, t_node **stack_b);
t_node	*ft_last(t_node *lst);
char	**ft_split(char const *s, char c);
int		create_args(char **argv, t_node	**stack_a);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		is_sorted(t_node *stack_a);
int		has_duplicates(t_node *stack_a);
int		ft_lstsize(t_node *lst);
void	ft_freelist(t_node **stack_a);
void	sort_tiny_stack(int	size, t_node **stack_a);
void	map_indexes(t_node *stack_a);
int		get_min_position(t_node *stack_a);
void 	print_list(t_node *stack_a);

#endif