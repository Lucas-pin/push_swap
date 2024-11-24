/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:07:31 by lpin              #+#    #+#             */
/*   Updated: 2024/11/24 19:09:57 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_error(int error, t_ps **lst)
{
	if (error == EMPTY_ARG)
		ft_putstr_fd("Error\n", 2);
	if (error == INVALID_ARG)
		ft_putstr_fd("Error\n", 2);
	if (error == REPETEAD_ARG)
		ft_putstr_fd("Error\n", 2);
	if (lst)
		ft_ps_destroy(lst);
	exit (-1);
}
