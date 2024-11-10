/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:50:10 by lpin              #+#    #+#             */
/*   Updated: 2024/11/10 19:42:52 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_sort_three(t_ps **stack_a)
{
	t_ps	*aux;

	if (!stack_a || !*stack_a || ft_check_sort(*stack_a) == 1)
		return ;
	aux = *stack_a;
	while (ft_check_sort(aux) != 1)
	{
		if (aux->content > aux->next->content)
			sa(&aux);
		else
			rra(&aux);
	}
}
void	ft_sort_big(t_ps **stack_a, t_ps **stack_b)
{
	int		cost_a;
	int		cost_b;
	t_ps	*cheapest;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	cheapest = ft_cheapest(stack_b);
	cost_a = cheapest->metadata.cost_a;
	cost_b = cheapest->metadata.cost_b;
	ft_db_moves(stack_a, stack_b, &cost_a, &cost_b);
	ft_sgle_moves(stack_a, stack_b, &cost_a, &cost_b);
	pa(stack_a, stack_b);
}
