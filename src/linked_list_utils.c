/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:01:58 by lpin              #+#    #+#             */
/*   Updated: 2024/10/17 19:47:19 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_ps	*ft_ps_new(long content)
{
	t_ps	*nodo;

	nodo = NULL;
	nodo = malloc(sizeof(t_ps));
	if (nodo == NULL)
		return (NULL);
	nodo->content = content;
	nodo->tail = 0;
	nodo->next = NULL;
	nodo->prev = NULL;
	return (nodo);
}

void	ft_ps_add_front(t_ps **lst, t_ps *new)
{
	t_ps	*last;

	if (!new)
		return ;
	else if (!*lst)
	{
		*lst = new;
		(*lst)->next = new;
		(*lst)->prev = new;
		new ->tail = 1;
	}
	else
	{
		last = (*lst)->prev;
		(*lst)->tail = 0;
		new->tail = 1;
		new->next = *lst;
		new->prev = last;
		last->next = new;
		(*lst)->prev = new;
		*lst = new;
	}
}

void	ft_ps_add_back(t_ps **lst, t_ps *new)
{
	if (!new)
		return ;
	else if (!*lst)
	{
		*lst = new;
		(*lst)->next = new;
		(*lst)->prev = new;
		new ->tail = 1;
	}
	else
	{
		new->next = *lst;
		new->prev = (*lst)->prev;
		(*lst)->prev->next = new;
		(*lst)->prev = new;
	}
}

int	ft_ps_size(t_ps *lst)
{
	int		size;
	t_ps	*aux;

	size = 1;
	if (lst->next == lst)
		return (size);
	aux = lst;
	aux = aux->next;
	while (aux->tail == 0)
	{
		aux = aux->next;
		size++;
	}
	return (size);
}

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
