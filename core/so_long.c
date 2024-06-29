/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayderha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:32:49 by rayderha          #+#    #+#             */
/*   Updated: 2024/06/15 15:00:50 by rayderha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/libft.h"
int	main(int ac, char **av)
{
	//check nom de la map FAIT
	//check les lignes
	//check les colones
	//check les pieces
	//check le joueur
	//check la sortie
	
	if (ac != 2)
		return (error_msg("Un seul argument valable \nexemple : ./so_long map.ber"));
	if (!check_file_name(av[1]))
		return (error_msg("le nom de la map doit terminer par .ber"));
	if (!check_config_map(av[1]))
		return (0);
	ft_printf("le nom de la map est bon");
	return (0);
}