/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15_puzzle.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 19:26:23 by kbatz             #+#    #+#             */
/*   Updated: 2019/01/22 19:45:16 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 15_PUZZLE_H
# define 15_PUZZLE_H

# include <stdio.h>

# define X_SIZE 4
# define Y_SIZE 4

typedef struct		s_list
{
	int				nbr;
	struct s_list	*next;
}					t_list;

char				(*g_cmds)[] =
{
	&up,
	&down,
	&left,
	&right
};

#endif
