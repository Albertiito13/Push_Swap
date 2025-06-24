/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 23:54:53 by albcamac          #+#    #+#             */
/*   Updated: 2025/06/24 17:31:03 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_node *a)
{
	if (!a || !a->next)
		return (1);
	while (a->next != NULL && a->value < a->next->value)
		a = a->next;
	if (a->next == NULL)
		return (1);
	return (0);
}

int	find_min(t_node *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	find_position(t_node *stack, int value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value == value)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

void	move_to_top(t_node **stack, int pos, char stack_id)
{
	int	size;

	size = stack_size(*stack);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
		{
			if (stack_id == 'a')
				ra(stack);
			else
				rb(stack);
		}
	}
	else
	{
		while (pos++ < size)
		{
			if (stack_id == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
}

int	stack_size(t_node *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
