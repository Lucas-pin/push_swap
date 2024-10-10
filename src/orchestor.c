/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orchestor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:34:02 by lpin              #+#    #+#             */
/*   Updated: 2024/10/10 20:29:42 by lpin             ###   ########.fr       */
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

t_ps	*ft_lst_orchestor(char *entry, t_ps *lst)
{
	ft_lst_init(entry, &lst);
	return (lst);
}

void	ft_mov_orchestor(t_ps *stack)
{
	ft_printf("-------original-------\n");
	ft_print_list(stack);
	ft_printf("-------modified-------\n");
	sb(&stack);
	ft_print_list(stack);
	ft_printf("----------------------\n");
	ft_ps_destroy(&stack);
}
