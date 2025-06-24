/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 23:54:43 by albcamac          #+#    #+#             */
/*   Updated: 2025/06/24 18:00:48 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "push_swap.h"

void	free_stack(t_node *stack)
{
	t_node	*tmp;
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
	free(tmp);
	}
}

char	**parse_arguments(int argc, char **argv, int *new_argc)
{
	char	**args;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !args[0])
			error_exit("Error");
		*new_argc = 0;
		while (args[*new_argc])
			(*new_argc)++;
		return (args);
	}
	else
	{
		*new_argc = argc - 1;
		return (&argv[1]);
	}
}

void	free_split(char **arr)
{
	int	i = 0;

	if (!arr)
		return;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a = NULL;
	t_node	*stack_b = NULL;
	char	**args;
	int		new_argc;
	int		i = 0;
	long	num;

	if (argc < 2)
		return (0);

	args = parse_arguments(argc, argv, &new_argc);
	while (i < new_argc)
	{
		if (!is_integer(args[i]))
			error_exit("Error");
		num = ft_atol(args[i]);
		if (num < INT_MIN || num > INT_MAX)
			error_exit("Error");
		if (is_duplicate(stack_a, (int)num))
			error_exit("Error");
		stack_a = add_node_end(stack_a, (int)num);
		i++;
	}

	if (argc == 2) // entrada entre comillas → liberar
		free_split(args);

	int size = stack_size(stack_a);
	if (is_sort(stack_a) == 0)
	{
		if (size == 2 && stack_a->value > stack_a->next->value)
			sa(&stack_a);
		else if (size == 3)
			sort_3(&stack_a);
		else if (size == 4)
			sort_4(&stack_a, &stack_b);
		else if (size == 5)
			sort_5(&stack_a, &stack_b);
		else if (size > 5)
			dual_chunk_sort(&stack_a, &stack_b);
	}
	else
		return (0);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 23:54:43 by albcamac          #+#    #+#             */
/*   Updated: 2025/06/24 19:05:00 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**expand_args(char **result, char **split, int *total)
{
	char	**temp;
	int		split_count;
	int		i;

	split_count = 0;
	while (split[split_count])
		split_count++;
	temp = malloc(sizeof(char *) * (*total + split_count + 1));
	if (!temp)
		error_exit(NULL, NULL, NULL);
	i = -1;
	while (++i < *total)
		temp[i] = result[i];
	i = 0;
	while (split[i])
	{
		temp[*total + i] = ft_strdup(split[i]);
		if (!temp[*total + i])
			error_exit(NULL, NULL, NULL);
		i++;
	}
	temp[*total + i] = NULL;
	(free(result), free_split(split));
	*total += i;
	return (temp);
}

char	**parse_arguments(int argc, char **argv, int *new_argc)
{
	char	**result;
	char	**split;
	int		i;
	int		total;

	result = malloc(sizeof(char *));
	if (!result)
		error_exit(NULL, NULL, NULL);
	result[0] = NULL;
	total = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !split[0])
			error_exit(NULL, NULL, NULL);
		result = expand_args(result, split, &total);
		i++;
	}
	*new_argc = total;
	return (result);
}

static void	parse_numbers(char **args, int count, t_node **stack_a)
{
	int		i;
	long	num;

	i = 0;
	while (i < count)
	{
		if (!is_integer(args[i]))
			error_exit(args, *stack_a, NULL);
		num = ft_atol(args[i]);
		if (num < INT_MIN || num > INT_MAX)
			error_exit(args, *stack_a, NULL);
		if (is_duplicate(*stack_a, (int)num))
			error_exit(args, *stack_a, NULL);
		*stack_a = add_node_end(*stack_a, (int)num);
		i++;
	}
}

static void	sort_dispatch(t_node **a, t_node **b)
{
	int	size;

	size = stack_size(*a);
	if (is_sort(*a) != 0)
		return ;
	if (size == 2 && (*a)->value > (*a)->next->value)
		sa(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
	else if (size > 5)
		dual_chunk_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**args;
	int		new_argc;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	args = parse_arguments(argc, argv, &new_argc);
	parse_numbers(args, new_argc, &stack_a);
	free_split(args);
	sort_dispatch(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
