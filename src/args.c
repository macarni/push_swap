/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:19:30 by adrperez          #+#    #+#             */
/*   Updated: 2023/03/24 16:34:40 by adrperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	int	check_ifdigits(char *argv)
{
	int	i;
	
	i = 0;
	if (argv[i] == '+' || argv[i] == '-')
		i++;
	while(argv[i])
	{
		if (!ft_isdigit(argv[i++]))
		{	
			ft_printf("Error\n");
			return (0);
		}
	}
	return (1);
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

int	has_duplicates(t_node *stack_a)
{
	t_node	*aux;
	t_node	*aux2;
	int		len;
	int		i;
	int		j; 

	aux = stack_a;
	
	i = 0;
	j = 0;
	len = ft_lstsize(stack_a);
	while (i < len - 1)
	{
		j = i + 1;
		aux2 = aux->next;
		while (j < len)
		{
			if (aux->content == aux2->content){
				printf("Has duplicates\n");
				return (1);
			}
			j++;
			aux2 = aux2->next;
		}
		aux = aux->next;
		i++; 
	}
	return (0);
}

static void free_matrix(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	create_args(char **argv, t_node	**stack_a)
{
	char	**args;
	t_node 	*new_node;
	int		i;
	int		j;

	i = 1;
	while(argv[i])
	{
		if (!ft_strlen(argv[i]))
		{	
			ft_printf("Error\n");
			return (0);
		}
		args = ft_split(argv[i++], ' ');
		j = 0;
		while(args[j])
		{		
			new_node = malloc(sizeof(t_node));
			if(!check_ifdigits(args[j]))
				return(0);
			new_node->content = ft_atoi(args[j++]);
			new_node->next = 0;
			ft_lstadd_back(stack_a, new_node);
		}
		free_matrix(args);
	}
	return (1);
}
