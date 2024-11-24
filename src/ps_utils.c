/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:54:22 by lpin              #+#    #+#             */
/*   Updated: 2024/11/24 19:26:30 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_find_bottom(t_ps **stack)
{
	t_ps	*aux;

	aux = *stack;
	if (!aux)
		return ;
	while (aux->tail != 1)
		aux = aux->next;
	*stack = aux;
}

void	ft_print_node(t_ps **lst)
{
	if (!lst || !*lst)
		return ;
	ft_printf("Content: %d, Index: %d, Pos: %d, target_pos: %d, cost_a: %d, "
		"cost_b: %d, cost_abs: %d\n",
		(*lst)->content, (*lst)->metadata.index,
		(*lst)->metadata.pos, (*lst)->metadata.target_pos,
		(*lst)->metadata.cost_a, (*lst)->metadata.cost_b,
		(*lst)->metadata.cost_abs);
}

void	ft_print_list(t_ps *lst)
{
	t_ps	*aux;

	aux = lst;
	if (!lst)
	{
		ft_printf("Empty list\n");
		return ;
	}
	else if (aux->next == aux)
	{
		ft_printf("Hay un único nodo\n");
		printf("content: %li\n", aux->content);
		ft_printf("tail: %i\n", aux->tail);
		return ;
	}
	printf("content: %li\n", aux->content);
	ft_printf("tail: %i\n", aux->tail);
	aux = aux->next ;
	while (aux != lst)
	{
		printf("content: %li\n", aux->content);
		ft_printf("tail: %i\n", aux->tail);
		aux = aux->next;
	}
}

long	ft_ps_atoi(char *s)
{
	long	nbr;
	int		flag;

	nbr = 0;
	flag = 1;
	while (*s && (*s < '0' || *s > '9'))
	{
		if (*s == '-')
			flag = -1;
		s++;
	}
	while (*s && (*s >= '0' && *s <= '9'))
	{
		nbr = nbr * 10 + (*s - '0');
		s++;
	}
	return (nbr * flag);
}
