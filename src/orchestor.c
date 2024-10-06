/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orchestor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:34:02 by lpin              #+#    #+#             */
/*   Updated: 2024/10/04 18:51:25 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

char	*ft_entry_orchestor(int argc, char **argv)
{
	char	*aux;

	aux = NULL;
	ft_invalid_entry(argv);
	if (argc == 2)
		aux = ft_strdup(*argv);
	else if (argc > 2)
		aux = ft_rebuild_entry(argv);
	ft_empty_arg(&aux);
	return (aux);
}

void	ft_lst_orchestor(char *entry, t_ps *lst)
{
	ft_lst_init(entry, &lst);
	ft_print_list(lst);
	ft_ps_destroy(&lst);
}
