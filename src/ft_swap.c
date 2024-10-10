/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:13:53 by lpin              #+#    #+#             */
/*   Updated: 2024/10/10 20:22:37 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_swap(t_ps **stack)
{
	t_ps	*first_node;
	t_ps	*second_node;

	if (ft_ps_size(*stack) <= 1)
		return ;
	ft_find_bottom(stack);
	first_node = *stack;
	second_node = (*stack)->next;
	first_node->prev->next = second_node;
	first_node->next = second_node->next;
	second_node->prev = first_node->prev;
	second_node->next = first_node;
	first_node->prev = second_node;
	first_node->tail = 0;
	second_node->tail = 1;
	*stack = second_node;
}
