/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estimate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:14:36 by lpin              #+#    #+#             */
/*   Updated: 2024/11/15 23:23:05 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_index(t_ps **stack)
{
	t_ps	*aux;

	if (!stack || !*stack)
		return ;
	aux = *stack;
	*stack = (*stack)->next;
	while ((*stack) != aux)
	{
		if (aux->content > (*stack)->content)
			aux->metadata.index = aux->metadata.index + 1;
		*stack = (*stack)->next;
	}
}

void	ft_position(t_ps **stack)
{
	if (!stack || !*stack)
		return ;
	if ((*stack)->next == *stack)
		(*stack)->metadata.pos = 0;
	else if ((*stack)->tail == 1)
		(*stack)->metadata.pos = 0;
	else
		(*stack)->metadata.pos = (*stack)->prev->metadata.pos + 1;
}

void	ft_target_pos(t_ps **stack_a, t_ps **stack_b)
{
	t_ps	*target;
	t_ps	*target_aux;
	t_ps	*aux_a;
	int		size;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	aux_a = *stack_a;
	target = NULL;
	target_aux = NULL;
	size = ft_ps_size(*stack_a) + 1;
	while (--size > 0)
	{
		if (aux_a->content > (*stack_b)->content && (target == NULL
			|| aux_a->metadata.index < target->metadata.index))
			target = aux_a;
		else if (target_aux == NULL
			|| target_aux->metadata.index > aux_a->metadata.index)
			target_aux = aux_a;
		aux_a = aux_a->next;
	}
	if (target ==  NULL)
		(*stack_b)->metadata.target_pos = target_aux->metadata.pos;
	else
		(*stack_b)->metadata.target_pos = target->metadata.pos;
}

void	ft_cost(t_ps **stack_a, t_ps **stack_b)
{
	int		size_a;
	int		size_b;
	
	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	size_a = ft_ps_size(*stack_a);
	size_b = ft_ps_size(*stack_b);
	if ((*stack_b)->metadata.target_pos <= (size_a / 2))
		(*stack_b)->metadata.cost_a = (*stack_b)->metadata.target_pos;
	else
		(*stack_b)->metadata.cost_a =
			((size_a - (*stack_b)->metadata.target_pos) * (-1));
	if ((*stack_b)->metadata.pos <= (size_b / 2))
		(*stack_b)->metadata.cost_b = (*stack_b)->metadata.pos;
	else
		(*stack_b)->metadata.cost_b =
			((size_b - (*stack_b)->metadata.pos) * (-1));
}

void	ft_absolute(t_ps **stack_b)
{
	int	cost_a;
	int	cost_b;

	if (!stack_b || !*stack_b)
		return ;
	cost_a = (*stack_b)->metadata.cost_a;
	cost_b = (*stack_b)->metadata.cost_b;
	if (cost_a == cost_b)
		(*stack_b)->metadata.cost_abs = cost_a;
	else if ((cost_a < 0 && cost_b < 0))
		if (cost_a < cost_b)
			(*stack_b)->metadata.cost_abs = cost_a;
		else
			(*stack_b)->metadata.cost_abs = cost_b;
	else if (cost_a > 0 && cost_b > 0)
		if (cost_a > cost_b)
			(*stack_b)->metadata.cost_abs = cost_a;
		else
			(*stack_b)->metadata.cost_abs = cost_b;
	else if (cost_a < 0)
		(*stack_b)->metadata.cost_abs = (cost_a * (-1)) + cost_b;
	else
		(*stack_b)->metadata.cost_abs = cost_a + (cost_b * (-1));
	if ((*stack_b)->metadata.cost_abs < 0)
		(*stack_b)->metadata.cost_abs = (*stack_b)->metadata.cost_abs * -1;
}
