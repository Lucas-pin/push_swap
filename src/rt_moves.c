/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:56:37 by lpin              #+#    #+#             */
/*   Updated: 2024/10/10 21:04:47 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ra(t_ps **stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_ps **stack_b)
{
	ft_rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_ps **stack_a, t_ps **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}