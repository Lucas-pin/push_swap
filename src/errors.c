/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:07:31 by lpin              #+#    #+#             */
/*   Updated: 2024/10/03 20:58:10 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_error(int error, t_ps **lst)
{
	if (error == EMPTY_ARG)
		ft_printf("Empty argument\n");
	if (error == INVALID_ARG)
		ft_printf("Invalid argument\n");
	if (error == REPETEAD_ARG)
		ft_printf("Repetead argument\n");
	if (lst)
		ft_ps_destroy(lst);
	exit (-1);
}
