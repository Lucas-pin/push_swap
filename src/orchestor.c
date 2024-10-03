/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orchestor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:34:02 by lpin              #+#    #+#             */
/*   Updated: 2024/10/03 20:58:11 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_entry_orchestor(int argc, char **argv)
{
	ft_invalid_entry(argv);
	if (argc == 2)
	{
		ft_empty_arg(argv);
	}
}

void	ft_lst_orchestor(int argc, char **argv, t_ps *lst)
{
	char	**aux;

	aux = NULL;
	if (argc == 2)
	{
		aux = ft_split(*argv, ' ');
		if (!aux)
			exit (-1);
		ft_lst_init(aux, &lst);
		ft_split_destroyer(aux);
		free(aux);
	}
	else
	{
		ft_lst_init(argv, &lst);
	}
	ft_repetead_entry(&lst);
	if (ft_check_sort(lst) == 1)
	{
		ft_printf("The list is ordered\n");
		ft_ps_destroy(&lst);
		return ;
	}
	ft_print_list(lst);
	ft_ps_destroy(&lst);
}
