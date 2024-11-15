/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:48:40 by lpin              #+#    #+#             */
/*   Updated: 2024/11/15 23:25:28 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_move_stack_a(t_ps **stack_a, t_ps **stack_b)
{
	int	i;
	int	size;
	int	max_index;
	t_ps	*aux;

	i = 0;
	max_index = 0;
	aux = *stack_a;
	size = ft_ps_size(aux) + 1;
	while (--size > 0)
	{
		if (aux->metadata.index > max_index)
			max_index = aux->metadata.index;
		aux = aux->next;
	}
	while (i < max_index && ft_ps_size(*stack_a) > 3)
	{
		if ((*stack_a)->metadata.index <= max_index / 2)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
	while (ft_ps_size(*stack_a) > 3)
		pb(stack_a, stack_b);
}

t_ps	*ft_cheapest(t_ps **stack_b)
{
	int		size;
	t_ps	*aux_b;
	t_ps	*cheapest;

	size = ft_ps_size(*stack_b) + 1;
	aux_b = *stack_b;
	cheapest = *stack_b;
	while (--size > 0)
	{
		if (aux_b->metadata.cost_abs < cheapest->metadata.cost_abs)
			cheapest = aux_b;
		aux_b = aux_b->next;
	}
	return (cheapest);
}

void	ft_db_moves(t_ps **stack_a, t_ps **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(stack_a, stack_b);
		*cost_a = *cost_a - 1;
		*cost_b = *cost_b - 1;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(stack_a, stack_b);
		*cost_a = *cost_a + 1;
		*cost_b = *cost_b + 1;
	}
}

void	ft_sgle_moves(t_ps **stack_a, t_ps **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a != 0 || *cost_b != 0)
	{
		if (*cost_a > 0)
		{
			ra(stack_a);
			*cost_a = *cost_a - 1;
		}
		else if (*cost_a < 0)
		{
			rra(stack_a);
			(*cost_a)++;
		}
		if (*cost_b > 0)
		{
			rb(stack_b);
			*cost_b = *cost_b - 1;
		}
		else if (*cost_b < 0)
		{
			rrb(stack_b);
			*cost_b = *cost_b + 1;
		}
	}
}

void	ft_final_order(t_ps **stack_a)
{
	t_ps	*low_index;
	t_ps	*aux;

	aux = *stack_a;
	low_index = aux;
	aux = aux->next;
	while (aux != *stack_a)
	{
		if (low_index->metadata.index > aux->metadata.index)
			low_index = aux;
		aux = aux->next;
	}
	if (low_index->metadata.pos < (ft_ps_size(*stack_a) / 2))
	{
		while (ft_check_sort(*stack_a) != 1)
			ra(stack_a);
	}
	else
	{
		while (ft_check_sort(*stack_a) != 1)
			rra(stack_a);
	}
}
