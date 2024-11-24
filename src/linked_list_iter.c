/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_iter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:08:13 by lpin              #+#    #+#             */
/*   Updated: 2024/11/24 19:09:40 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_ps_iter(t_ps **lst, void (*f) (t_ps **))
{
	t_ps	*aux;

	if (!lst || !*lst || !f)
		return ;
	ft_find_bottom(lst);
	aux = *lst;
	f(&aux);
	aux = aux->next;
	while (aux->tail != 1)
	{
		f(&aux);
		aux = aux->next;
	}
}

void	ft_ps_iter_b(t_ps **stack_a, t_ps **stack_b,
		void (*f) (t_ps **, t_ps **))
{
	t_ps	*aux;

	if (!stack_a || !*stack_a || !f || !stack_b || !*stack_b)
		return ;
	ft_find_bottom(stack_a);
	ft_find_bottom(stack_b);
	aux = *stack_b;
	f(stack_a, &aux);
	aux = aux->next;
	while (aux->tail != 1)
	{
		f(stack_a, &aux);
		aux = aux->next;
	}
}
