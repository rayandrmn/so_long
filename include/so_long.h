/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayderha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:38:33 by rayderha          #+#    #+#             */
/*   Updated: 2024/06/15 17:46:55 by rayderha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_checkmap
{
	int			ligne;
	int			colone;
	int			player;
	int			piece;
	int			exit;
	char		*map;
	char		**test;
}	t_checkmap;

int	error_msg(char *msg);
int	check_file_name(char *av);
int	check_config_map(char *av);

#endif
