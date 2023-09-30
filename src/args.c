/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrperez <adrperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:19:30 by adrperez          #+#    #+#             */
/*   Updated: 2023/09/30 17:34:03 by adrperez         ###   ########.fr       */
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

/**
 * The function `create_args` takes command line arguments and creates a stack of nodes, where each
 * node contains an integer value.
 * 
 * @param argv A pointer to an array of strings, where each string represents a command-line argument.
 * @param stack_a The parameter `stack_a` is a pointer to a pointer to a `t_node` struct. It is used to
 * store a linked list of nodes, where each node contains an integer value (`content`) and a pointer to
 * the next node (`next`).
 * 
 * @return The function `create_args` is returning an integer value.
 */
int	create_args(char **argv, t_node	**stack_a)
{
	char	**args;
	t_node 	*new_node;
	int		i;
	int		j;

	i = 1;
	while(argv && argv[i])
	{
		if (!ft_strlen(argv[i]))
		{	
			ft_printf("Error\n");
			return (0);
		}
		args = ft_split(argv[i++], ' ');
		j = 0;
		while(args && args[j])
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
	//map_ x indexes(*stack_a);
	return (1);
}
