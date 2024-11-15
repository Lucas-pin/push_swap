/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orchestor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:34:02 by lpin              #+#    #+#             */
/*   Updated: 2024/11/15 22:45:49 by lpin             ###   ########.fr       */
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

void	ft_mov_orchestor(t_ps *stack_a, t_ps *stack_b)
{
	ft_ps_iter(&stack_a, ft_index);
	if (ft_ps_size(stack_a) > 3)	
		ft_move_stack_a(&stack_a, &stack_b);
	ft_sort_three(&stack_a);
	ft_metadata(&stack_a, &stack_b);
	while (ft_ps_size(stack_b) > 0)
	{
		ft_sort_big(&stack_a, &stack_b);
		ft_metadata(&stack_a, &stack_b);
	}
	if (ft_check_sort(stack_a) == 0)
	{
		ft_ps_iter(&stack_a, ft_position);
		ft_final_order(&stack_a);
	}
	//ft_print_list(stack_a);
 	//ft_printf("---------------stack_a-------------\n");
	//ft_ps_iter(&stack_a, ft_print_node);
	//ft_printf("---------------stack_b-------------\n");
	//ft_ps_iter(&stack_b, ft_print_node);
	ft_ps_destroy(&stack_a);
	ft_ps_destroy(&stack_b);
}
