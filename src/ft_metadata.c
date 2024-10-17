/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_metadata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:20:43 by lpin              #+#    #+#             */
/*   Updated: 2024/10/17 20:59:51 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_index(t_ps **stack)
{
	t_ps	*aux;

	aux = *stack;
	*stack = (*stack)->next;
	while ((*stack) != aux)
	{
		if (aux->content > (*stack)->content)
			aux->metadata.index = aux->metadata.index + 1;
		*stack = (*stack)->next;
	}
}

void	ft_position(t_ps **stack)
{
	if ((*stack)->next == *stack)
		(*stack)->metadata.pos = 0;
	else
		(*stack)->metadata.pos = (*stack)->prev->metadata.pos + 1;
}