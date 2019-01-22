/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle_15.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 20:09:35 by kbatz             #+#    #+#             */
/*   Updated: 2019/01/22 20:53:28 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUZZLE_15_H
# define PUZZLE_15_H

# include <stdio.h>
# include <stdlib.h>

# define X_SIZE 4
# define Y_SIZE 4

typedef struct		s_list
{
	int				n;
	struct s_list	*next;
}					t_list;

#endif
