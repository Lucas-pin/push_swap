/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:27:03 by lpin              #+#    #+#             */
/*   Updated: 2024/10/04 18:40:09 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main( int argc, char **argv)
{
	char	*entry;
	t_ps	lst;

	entry = NULL;
	ft_memset(&lst, 0, sizeof(lst));
	if (argc <= 1)
		return (0);
	else
	{
		argv++ ;
		entry = ft_entry_orchestor(argc, argv);
		ft_lst_orchestor(entry, &lst);
	}
	return (0);
}
