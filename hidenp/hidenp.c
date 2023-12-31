/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 10:43:31 by mait-elk          #+#    #+#             */
/*   Updated: 2023/12/31 11:14:41 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char *av[])
{
	char	*hid;
	char	*str;

	if (ac == 3)
	{
		hid = av[1];
		str = av[2];
		while (*str)
		{
			if (*str == *hid)
			{
				hid++;
				if (*hid == '\0')
				{
					write(1, "1\n", 2);
					return (0);
				}
			}
			str++;
		}
		write(1, "0\n", 2);
		return (0);
	}
	return (-1);
}
