#include "../libft/libft.h"
#include <stdio.h>
#include <stddef.h>
#include <fcntl.h>


int	main(void)
{
	int	fd = open("map.ber", O_RDONLY);
	char *str;
	char *map;
	char 	*temp;

	map = 0;
//	map = malloc(sizeof(char) + 1);
	while (1)
	{
		if (!map)
		{
			map = get_next_line(fd);
			if (map == NULL)
			{
				free(map);
				return 0;
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
			temp = ft_strjoin(map, str);
			free(map);
			map = temp;
			free(str);
		}
	}
	printf("\n\n\n");
	printf(" resultat \n%s", map);
	free(map);
	return 0;
}

