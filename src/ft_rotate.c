/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:43:32 by lpin              #+#    #+#             */
/*   Updated: 2024/10/10 21:38:42 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_rotate(t_ps **stack)
{
	int		size;

	if (!stack || !*stack)
		return ;
	size = ft_ps_size(*stack);
	if (size <= 1)
		return ;
	ft_find_bottom(stack);
	(*stack)->tail = 0;
	(*stack)->next->tail = 1;
	*stack = (*stack)->next;
}