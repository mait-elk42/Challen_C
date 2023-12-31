/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 10:33:26 by mait-elk          #+#    #+#             */
/*   Updated: 2023/12/31 10:36:11 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#ifndef ROT_V
# define ROT_V 13
#endif

static void	_rotate_char(char *str, int rotationv)
{
	if (rotationv >= 0)
	{
		while (rotationv--)
		{
			if (rotationv >= 26)
				rotationv %= 26;
			if (*str == 'Z' || *str == 'z')
				*str -= 26;
			(*str)++;
		}
	}
	else
	{
		rotationv *= -1;
		while (rotationv--)
		{
			if (rotationv >= 26)
				rotationv %= 26;
			if (*str == 'A' || *str == 'a')
				*str += 26;
			(*str)--;
		}
	}
}

static void	_miniapi(char *str, int rotationv)
{
	if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
		_rotate_char(str, rotationv);
}

int	main(int ac, char *av[])
{
	char	*str;

	if (ac == 2)
	{
		str = *(av + 1);
		while (*str)
		{
			_miniapi(str, ROT_V);
			write (1, str, 1);
			str++;
		}
		return (0);
	}
	return (-1);
}
