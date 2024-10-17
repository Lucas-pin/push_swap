/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:16:28 by lpin              #+#    #+#             */
/*   Updated: 2024/10/17 19:16:38 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_lst_creator(t_ps **lst, long content)
{
	*lst = ft_ps_new(content);
	(*lst)->next = *lst;
	(*lst)->prev = *lst;
	(*lst)->tail = 1;
	ft_memset((void *)(&(*lst)->metadata), 0, sizeof(t_algorithm));
}

void	ft_lst_init(char *entry, t_ps **lst)
{
	char	**matrix;
	char	**matrix_init;

	matrix = NULL;
	matrix_init = NULL;
	matrix = ft_split(entry, ' ');
	if (!matrix)
		exit (-1);
	matrix_init = matrix;
	ft_memset(*lst, 0, sizeof(*lst));
	ft_lst_creator(lst, ft_ps_atoi(*matrix));
	matrix++;
	while (*matrix)
	{
		ft_ps_add_back(lst, ft_ps_new(ft_ps_atoi(*matrix)));
		matrix++;
	}
	ft_destroyer(&entry);
	ft_split_destroyer(matrix_init);
	free(matrix_init);
	ft_check_list(*lst);
}
