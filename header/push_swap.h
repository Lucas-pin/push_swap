/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:46:12 by lpin              #+#    #+#             */
/*   Updated: 2024/10/06 17:42:08 by lpin             ###   ########.fr       */
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
	long			content;
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

// orchestor.c

char	*ft_entry_orchestor(int argc, char **argv);

void	ft_lst_orchestor(char *entry, t_ps *lst);

// errors.c

void	ft_error(int error, t_ps **lst);

// check_entry.c

void	ft_invalid_entry(char **argv);

void	ft_empty_arg(char **argv);

char	*ft_rebuild_entry(char **argv);

// list_init.c

void	ft_lst_init(char *entry, t_ps **lst);

void	ft_lst_creator(t_ps **lst, long content);

// linked_list_utils.c

t_ps	*ft_ps_new(long content);

void	ft_ps_add_front(t_ps **lst, t_ps *new);

void	ft_ps_add_back(t_ps **lst, t_ps *new);

int		ft_ps_size(t_ps *lst);

void	ft_ps_destroy(t_ps **lst);

// check_list.c

void	ft_check_list(t_ps *lst);

int		ft_check_sort(t_ps *lst);

int		ft_check_number(t_ps *lst);

void	ft_repetead_number(t_ps **lst);

// ps_utils.c

long	ft_ps_atoi(char *s);

void	ft_print_list(t_ps *lst);

#endif