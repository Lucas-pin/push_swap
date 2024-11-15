/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:13:53 by lpin              #+#    #+#             */
/*   Updated: 2024/11/16 00:15:55 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_swap(t_ps **stack)
{
	t_ps	*first_node;
	t_ps	*second_node;
	t_ps	*third_node;

	if (ft_ps_size(*stack) <= 1)
		return ;
	ft_find_bottom(stack);
	third_node = NULL;
	first_node = *stack;
	second_node = first_node->next;
	if (ft_ps_size(*stack) >= 3)
	{
		third_node = second_node->next;
		third_node->prev = first_node;
	}
	first_node->prev->next = second_node;
	first_node->next = second_node->next;
	second_node->prev = first_node->prev;
	second_node->next = first_node;
	first_node->prev = second_node;
	first_node->tail = 0;
	second_node->tail = 1;
	*stack = second_node;
}
