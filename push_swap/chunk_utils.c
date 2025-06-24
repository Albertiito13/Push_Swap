/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 01:41:09 by albcamac          #+#    #+#             */
/*   Updated: 2025/06/24 17:58:42 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	*build_and_sort(int *size_out, t_node *stack)
{
	int		*arr;
	int		size;
	t_node	*tmp;
	int		i;

	size = stack_size(stack);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		error_exit(NULL, NULL, NULL);
	tmp = stack;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	sort_array(arr, size);
	*size_out = size;
	return (arr);
}

void	index_stack(t_node *stack)
{
	int		*arr;
	int		size;
	int		i;
	t_node	*tmp;

	arr = build_and_sort(&size, stack);
	tmp = stack;
	while (tmp)
	{
		i = 0;
		while (i < size && arr[i] != tmp->value)
			i++;
		tmp->value = i;
		tmp = tmp->next;
	}
	free(arr);
}
