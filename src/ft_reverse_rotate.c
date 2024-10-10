/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:13:31 by lpin              #+#    #+#             */
/*   Updated: 2024/10/10 21:42:46 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_reverse_rotate(t_ps **stack)
{
	int		size;

	if (!stack || !*stack)
		return ;
	size = ft_ps_size(*stack);
	if (size <= 1)
		return ;
	ft_find_bottom(stack);
	(*stack)->tail = 0;
	(*stack)->prev->tail = 1;
	*stack = (*stack)->prev;
}