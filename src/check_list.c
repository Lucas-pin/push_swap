/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:32:40 by lpin              #+#    #+#             */
/*   Updated: 2024/10/06 17:35:49 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_check_list(t_ps *lst)
{
	if (ft_check_sort(lst) == 1)
	{
		ft_ps_destroy(&lst);
		exit (0);
	}
	if (ft_check_number(lst) == 1)
		ft_error(INVALID_ARG, &lst);
	ft_repetead_number(&lst);
	return ;
}

int	ft_check_number(t_ps *lst)
{
	t_ps	*aux;

	aux = lst;
	if (aux->content > INT_MAX || aux->content < INT_MIN)
		return (1);
	aux = aux->next;
	while (aux->tail == 0)
	{
		if (aux->content > INT_MAX || aux->content < INT_MIN)
			return (1);
		aux = aux->next;
	}
	return (0);
}

int	ft_check_sort(t_ps *lst)
{
	t_ps	*aux;

	aux = lst;
	while (aux->next->tail == 0)
	{
		if (aux->content > aux->next->content)
			return (0);
		aux = aux->next;
	}
	return (1);
}

void	ft_repetead_number(t_ps **lst)
{
	t_ps	*aux;
	t_ps	*aux_2;

	aux = *lst;
	aux_2 = *lst;
	aux = aux->next;
	while (aux_2->next->tail == 0)
	{
		while (aux->tail == 0)
		{
			if (aux_2->content == aux->content)
				ft_error(REPETEAD_ARG, lst);
			aux = aux->next;
		}
		aux_2 = aux_2->next;
		aux = aux_2->next;
	}
}
