/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:24:51 by lpin              #+#    #+#             */
/*   Updated: 2024/10/17 19:25:13 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_ps_destroy(t_ps **lst)
{
	t_ps	*aux;

	if (!lst || !*lst)
		return ;
	ft_find_bottom(lst);
	(*lst)->prev->next = NULL;
	(*lst)->prev = NULL;
	while (*lst)
	{
		aux = (*lst)->next;
		(*lst)->prev = NULL;
		(*lst)->next = NULL;
		free(*lst);
		*lst = NULL;
		*lst = aux;
	}
}
