/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 04:30:00 by albcamac          #+#    #+#             */
/*   Updated: 2025/06/24 16:38:25 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_chunks(int size, int *chunk_size, int *chunk_start)
{
	if (size <= 100)
		*chunk_size = size / 4;
	else if (size <= 200)
		*chunk_size = size / 6;
	else
		*chunk_size = size / 9;
	*chunk_start = 0;
}

static int	advance_chunk(int *chunk_start, int chunk_size, int total)
{
	if (*chunk_start + chunk_size >= total)
		return (0);
	*chunk_start += chunk_size;
	return (1);
}

static void	bring_to_top(t_node **a, int pos)
{
	int	rem;

	rem = stack_size(*a);
	if (pos <= rem / 2)
		while (pos-- > 0)
			ra(a);
	else
		while (pos++ < rem)
			rra(a);
}

static void	push_opt_b(t_node **a, t_node **b, int chunk_start,
				int chunk_size)
{
	pb(a, b);
	if ((*b)->value <= chunk_start + chunk_size / 2
		&& *a && ((*a)->value < chunk_start
			|| (*a)->value >= chunk_start + chunk_size))
		rr(a, b);
	else if ((*b)->value <= chunk_start + chunk_size / 2)
		rb(b);
}

void	dual_chunk_sort(t_node **a, t_node **b)
{
	int	size;
	int	chunk_size;
	int	chunk_start;
	int	pushed;
	int	pos;

	size = stack_size(*a);
	init_chunks(size, &chunk_size, &chunk_start);
	index_stack(*a);
	pushed = 0;
	while (pushed < size)
	{
		pos = find_next_in_chunk(*a, chunk_start,
				chunk_start + chunk_size);
		if (pos == -1)
		{
			if (!advance_chunk(&chunk_start, chunk_size, size))
				break ;
			continue ;
		}
		(bring_to_top(a, pos), push_opt_b(a, b, chunk_start, chunk_size));
		pushed++;
	}
	while (*b)
		bring_max_from_b_to_a(a, b);
}
