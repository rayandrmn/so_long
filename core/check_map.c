/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayderha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:31:14 by rayderha          #+#    #+#             */
/*   Updated: 2024/06/15 21:31:05 by rayderha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/libft.h"

int	check_file_name(char *av)
{
	int	len;

	len = ft_strlen(av);
	
	if (!ft_strnstr((av + len - 4), ".ber", len))
		return 0;
	return (1);
}

int	check_config_map(char *av)
{
	t_checkmap	mapfile;
	char		*str;
	char		*temp;
	int			fd;
	
	fd = open(av, O_RDONLY);
	mapfile.map = 0;
	while (1)
	{
		if (!mapfile.map)
		{
			mapfile.map = get_next_line(fd);
			if (mapfile.map == NULL)
			{
				free(mapfile.map);
				return (0);
			}
		}
		else
		{
			str = get_next_line(fd);
			if (str == NULL)
			{
				free(str);
				break ;
			}
			temp = ft_strjoin(mapfile.map, str);
			free(mapfile.map);
			mapfile.map = temp;
			free(str);
		}
	}
	//ft_printf("\n%s\n", mapfile.map);
	mapfile.test = ft_split(mapfile.map, '\n');
	printf("fonction ft split : \n");
	for (int i = 0; i <= 7; i++)
	{
		ft_printf("%s\n", mapfile.test[i]);
	}
	ft_printf("allo");
	free(mapfile.map);
	return 1;
}