/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:13:31 by lpin              #+#    #+#             */
/*   Updated: 2024/10/10 21:18:02 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_reverse_rotate(t_ps **stack)
{
	t_ps	*first_node;
	int		size;

	if (!stack)
		return ;
	size = ft_ps_size(*stack);
	if (size <= 1)
		return ;
	ft_find_bottom(stack);
	first_node = *stack;
	first_node->tail = 0;
	first_node->prev->tail = 1;
	*stack = first_node->prev;
}