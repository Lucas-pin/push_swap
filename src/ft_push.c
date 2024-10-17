/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:31:20 by lpin              #+#    #+#             */
/*   Updated: 2024/10/17 18:45:22 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_ps	*ft_isolate(t_ps **stack_src)
{
	t_ps	*isolated;

	isolated = *stack_src;
	if ((*stack_src)->next == (*stack_src))
		*stack_src = NULL;
	else
	{
		(*stack_src)->prev->next = (*stack_src)->next;
		(*stack_src)->next->prev = (*stack_src)->prev;
		*stack_src = (*stack_src)->next;
		(*stack_src)->tail = 1;
	}
	isolated->next = isolated;
	isolated->prev = isolated;
	return (isolated);
}

void	ft_push(t_ps **stack_src, t_ps **stack_dst)
{

	if (!stack_src || !*stack_src)
		return ;
	ft_find_bottom(stack_src);
	ft_find_bottom(stack_dst);
	ft_ps_add_front(stack_dst, ft_isolate(stack_src));
}