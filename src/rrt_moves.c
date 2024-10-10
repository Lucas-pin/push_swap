/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrt_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:14:02 by lpin              #+#    #+#             */
/*   Updated: 2024/10/10 21:14:38 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	rra(t_ps **stack_a)
{
	ft_reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_ps **stack_b)
{
	ft_reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_ps **stack_a, t_ps **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_printf("rrr\n");
}