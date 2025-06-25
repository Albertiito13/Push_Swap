/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 04:30:00 by albcamac          #+#    #+#             */
/*   Updated: 2025/06/25 06:13:50 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max(t_node *stack) // get_max_position fusionar las 2 funciones
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

static int	get_position(t_node *stack, int value)
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

static	void	bring_max_from_b_to_a(t_node **a, t_node **b)
{
	int	max;
	int	pos;
	int	size;

	max = get_max(*b);
	pos = get_position(*b, max);
	size = stack_size(*b);
	if (pos <= size / 2)
		while ((*b)->value != max)
			rb(b);
	else
		while ((*b)->value != max)
			rrb(b);
	pa(a, b);
}

void	chunk_sort(t_node **a, t_node **b)
{
	int	chunk;
	int	i;

	chunk = (ft_sqrt(stack_size(*a)) * (133 / 100));
	i = 0;
	index_stack(*a);
	while (*a)
	{
		if ((*a)->value <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->value <= i + chunk)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	while (*b)
		bring_max_from_b_to_a(a, b);
}
