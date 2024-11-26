/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:27:03 by lpin              #+#    #+#             */
/*   Updated: 2024/11/26 20:33:32 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main( int argc, char **argv)
{
	char	*entry;
	t_ps	lst;
	t_ps	*stack_a;
	t_ps	*stack_b;

	entry = NULL;
	stack_a = NULL;
	stack_b = NULL;
	ft_memset(&lst, 0, sizeof(lst));
	if (argc <= 1)
		return (0);
	else
	{
		argv++ ;
		entry = ft_entry_orchestor(argc, argv);
		stack_a = ft_lst_orchestor(entry, &lst);
		if (!stack_a)
			exit (-1);
		ft_mov_orchestor(stack_a, stack_b);
	}
	return (0);
}
