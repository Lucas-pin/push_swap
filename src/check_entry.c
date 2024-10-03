/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:30:18 by lpin              #+#    #+#             */
/*   Updated: 2024/10/03 20:49:49 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_invalid_entry(char **argv)
{
	char	*temp;

	while (*argv)
	{
		temp = *argv;
		while (*temp)
		{
			if (!ft_isdigit(*temp) && *temp != '-' && *temp != '+'
				&& *temp != ' ')
				ft_error(INVALID_ARG, NULL);
			temp++;
		}
		argv++;
	}
}

void	ft_repetead_entry(t_ps **lst)
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

void	ft_empty_arg(char **argv)
{
	char	**aux;

	aux = NULL;
	aux = ft_split(*argv, ' ');
	if (!aux)
		return ;
	if (!*aux)
	{
		ft_split_destroyer(aux);
		free(aux);
		ft_error(EMPTY_ARG, NULL);
	}
	ft_split_destroyer(aux);
	free(aux);
}
