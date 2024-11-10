/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_metadata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:20:43 by lpin              #+#    #+#             */
/*   Updated: 2024/10/25 17:19:24 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_metadata(t_ps **stack_a, t_ps **stack_b)
{
	ft_ps_iter(stack_a, ft_position);
	ft_ps_iter(stack_b, ft_position);
	ft_ps_iter_b(stack_a, stack_b, ft_target_pos);
	ft_ps_iter_b(stack_a, stack_b, ft_cost);
	ft_ps_iter(stack_b, ft_absolute);
}