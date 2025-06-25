/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 23:54:30 by albcamac          #+#    #+#             */
/*   Updated: 2025/06/25 06:13:41 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

int		is_integer(char *str);
int		is_duplicate(t_node *stack, int num);
void	error_exit(char **args, t_node *a, t_node *b);
t_node	*add_node_end(t_node *stack, int value);
void	free_stack(t_node *stack);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	sort_3(t_node **a);
void	sort_4(t_node **a, t_node **b);
void	sort_5(t_node **a, t_node **b);
int		find_min(t_node *stack);
int		find_position(t_node *stack, int value);
void	move_to_top(t_node **stack, int pos, char stack_id);
int		stack_size(t_node *stack);
void	index_stack(t_node *stack);
void	chunk_sort(t_node **a, t_node **b);
int		is_sort(t_node *a);
void	free_stack(t_node *stack);
void	free_split(char **arr);

#endif
