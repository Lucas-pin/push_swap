/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:24:32 by lpin              #+#    #+#             */
/*   Updated: 2024/10/10 20:26:56 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	sa(t_ps **stack_a)
{
	ft_swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_ps **stack_b)
{
	ft_swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_ps **stack_a, t_ps **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss\n");
}