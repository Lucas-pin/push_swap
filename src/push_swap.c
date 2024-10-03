/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:27:03 by lpin              #+#    #+#             */
/*   Updated: 2024/10/03 20:38:37 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main( int argc, char **argv)
{
	t_ps	lst;

	ft_memset(&lst, 0, sizeof(lst));
	ft_printf("lst.next: %p\n", lst.next);
	ft_printf("lst.prev: %p\n", lst.prev);
	ft_printf("lst.content: %i\n", lst.content);
	ft_printf("lst.tail: %i\n", lst.tail);
	if (argc <= 1)
		return (0);
	else
	{
		argv++ ;
		ft_entry_orchestor(argc, argv);
		ft_lst_orchestor(argc, argv, &lst);
	}
	return (0);
}
