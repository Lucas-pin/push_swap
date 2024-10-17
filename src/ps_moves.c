/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:27:31 by lpin              #+#    #+#             */
/*   Updated: 2024/10/17 18:57:11 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	pb(t_ps **stack_a, t_ps **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
}

void	pa(t_ps **stack_a, t_ps **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_printf("pa\n");
}