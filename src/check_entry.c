/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:30:18 by lpin              #+#    #+#             */
/*   Updated: 2024/10/06 17:38:25 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_invalid_entry(char **argv)
{
	char	*temp;

	while (*argv)
	{
		temp = *argv;
		while (*temp)
		{
			if (!ft_isdigit(*temp) && *temp != '-' && *temp != '+'
				&& *temp != ' ')
				ft_error(INVALID_ARG, NULL);
			if (ft_isdigit(*temp) == 1
				&& (*(temp + 1) != ' '
					&& !ft_isdigit(*(temp + 1))
					&& *(temp + 1) != '\0'))
				ft_error(INT_ERROR, NULL);
			if ((*temp == '-' || *temp == '+') && !ft_isdigit(*(temp + 1)))
				ft_error(INVALID_ARG, NULL);
			temp++;
		}
		argv++;
	}
}

void	ft_empty_arg(char **argv)
{
	char	**aux;

	aux = NULL;
	aux = ft_split(*argv, ' ');
	if (!aux)
		ft_error(INVALID_ARG, NULL);
	if (!*aux)
	{
		ft_split_destroyer(aux);
		free(aux);
		ft_error(INVALID_ARG, NULL);
	}
	ft_split_destroyer(aux);
	free(aux);
}

char	*ft_rebuild_entry(char **argv)
{
	char	*aux;

	aux = ft_strdup(*argv);
	aux = ft_strjoin_free_s1(aux, " ");
	argv++ ;
	while (*argv)
	{
		aux = ft_strjoin_free_s1(aux, *argv);
		aux = ft_strjoin_free_s1(aux, " ");
		argv++ ;
	}
	return (aux);
}
