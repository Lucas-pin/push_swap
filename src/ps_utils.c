/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:54:22 by lpin              #+#    #+#             */
/*   Updated: 2024/10/03 20:58:09 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_lst_creator(t_ps **lst, int content)
{
	*lst = ft_ps_new(content);
	(*lst)->next = *lst;
	(*lst)->prev = *lst;
	(*lst)->tail = 1;
}

void	ft_lst_init(char **matrix, t_ps **lst)
{
	int		aux_len;

	aux_len = 0;
	ft_memset(*lst, 0, sizeof(*lst));
	ft_lst_creator(lst, ft_ps_atoi(*matrix, *lst));
	matrix++;
	while (*matrix)
	{
		ft_ps_add_back(lst, ft_ps_new(ft_ps_atoi(*matrix, *lst)));
		matrix++;
		aux_len++;
	}
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
		ft_printf("%i\n", aux->content);
		return ;
	}
	ft_printf("%i\n", aux->content);
	aux = aux->next ;
	while (aux->tail == 0)
	{
		ft_printf("%i\n", aux->content);
		aux = aux->next;
	}
}

int	ft_ps_atoi(char *s, t_ps *lst)
{
	long	nbr;
	int		flag;

	nbr = 0;
	flag = 1;
	while (*s && (*s <= '0' || *s >= '9'))
	{
		if (*s == '-')
			flag = -1;
		if ((*s == '-' || *s == '+')
			&& (*(s + 1) < '0' || *(s + 1) > '9'))
			ft_error(INVALID_ARG, &lst);
		s++;
	}
	while (*s && (*s >= '0' && *s <= '9'))
	{
		nbr = nbr * 10 + (*s - '0');
		s++;
	}
	if (*s != '\0' || nbr > INT_MAX || nbr < INT_MIN)
		ft_error(INVALID_ARG, &lst);
	return (nbr * flag);
}
