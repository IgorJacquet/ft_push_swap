/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igor <igor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:55:19 by igor              #+#    #+#             */
/*   Updated: 2021/03/31 16:56:11 by igor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ft_realloc(char **str[2], char *new, int size)
{
	int	i;

	if (!new)
		return (0);
	i = 0;
	if (!(str[1] = malloc(sizeof(char *) * (size + 2))))
		return (ft_exit_write("Error\nFailed malloc\n", 0, -1));
	while (i < size)
	{
		str[1][i] = str[0][i];
		i++;
	}
	if (!(str[1][i] = ft_strdup(new)))
		return (ft_exit_write("Error\nFailed malloc\n", 0, -1));
	str[1][i + 1] = 0;
	if (str[0])
		free(str[0]);
	return (4219);
}

int	ft_line_reader(char ***string, int size)
{
	char	*line;
	char	**str[2];
	int		r;

	str[0] = NULL;
	str[1] = NULL;
	while ((r = get_next_line(0, &line)) >= 0)
	{
		if (!line[0])
		{
			free(line);
			break ;
		}
		if (r > 0 && !(line = ft_memcat(line, "\n", ft_strlen(line), 1)))
			return (ft_exit_write("malloc Error\n", 0, -2));
		if (ft_realloc(str, line, ++size) < 0)
			return (-2);
		str[0] = str[1];
		*string = str[1];
		free(line);
		if (r == 0)
			break ;
	}
	return (size + 1);
}
