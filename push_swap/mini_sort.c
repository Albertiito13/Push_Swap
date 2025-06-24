/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 00:56:42 by albcamac          #+#    #+#             */
/*   Updated: 2025/06/25 00:05:06 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_4(t_node **a, t_node **b)
{
	int	min;
	int	pos;

	min = find_min(*a);
	pos = find_position(*a, min);
	move_to_top(a, pos, 'a');
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_node **a, t_node **b)
{
	int	min;

	min = find_min(*a);
	move_to_top(a, find_position(*a, min), 'a');
	pb(a, b);
	min = find_min(*a);
	move_to_top(a, find_position(*a, min), 'a');
	pb(a, b);
	sort_3(a);
	if ((*b)->value < (*b)->next->value)
		sb(b);
	pa(a, b);
	pa(a, b);
}
