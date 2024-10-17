/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:54:22 by lpin              #+#    #+#             */
/*   Updated: 2024/10/11 19:41:23 by lpin             ###   ########.fr       */
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
		printf("tail: %i\n", aux->tail);
		return ;
	}
	printf("content: %li\n", aux->content);
	printf("tail: %i\n", aux->tail);
	aux = aux->next ;
	while (aux->tail == 0)
	{
		printf("content: %li\n", aux->content);
		printf("tail: %i\n", aux->tail);
		aux = aux->next;
	}
}

long	ft_ps_atoi(char *s)
{
	long	nbr;
	int		flag;

	nbr = 0;
	flag = 1;
	while (*s && (*s <= '0' || *s >= '9'))
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
