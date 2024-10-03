/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:46:12 by lpin              #+#    #+#             */
/*   Updated: 2024/10/03 20:50:09 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"

typedef struct s_ps
{
	int				tail;
	int				content;
	struct s_ps		*next;
	struct s_ps		*prev;
}					t_ps;

typedef enum e_entry_error
{
	EMPTY_ARG,
	INVALID_ARG,
	REPETEAD_ARG,
	INT_ERROR
}	t_entry_error;

void	ft_entry_orchestor(int argc, char **argv);

void	ft_lst_orchestor(int argc, char **argv, t_ps *lst);

void	ft_error(int error, t_ps **lst);

// check_entry.c

void	ft_invalid_entry(char **argv);

void	ft_empty_arg(char **argv);

void	ft_repetead_entry(t_ps **lst);

// parser.c

void	ft_lst_init(char **matrix, t_ps **lst);

int		ft_ps_atoi(char *s, t_ps *lst);

// linked_list_utils.c

t_ps	*ft_ps_new(int content);

void	ft_ps_add_front(t_ps **lst, t_ps *new);

void	ft_ps_add_back(t_ps **lst, t_ps *new);

int		ft_ps_size(t_ps *lst);

void	ft_ps_destroy(t_ps **lst);

// ps_utils.c

void	ft_lst_creator(t_ps **lst, int content);

void	ft_lst_init(char **matrix, t_ps **lst);

void	ft_print_list(t_ps *lst);

int		ft_check_sort(t_ps *lst);

#endif