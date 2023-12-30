#include <unistd.h>

static void	_rotate_char(char *str, int rotationv)
{
	while (rotationv--)
	{
		if (*str == 'Z' || *str == 'z')
			*str -= 26;
		(*str)++;
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
			_miniapi(str, 99);
			write (1, str, 1);
			str++;
		}
		return (0);
	}
	return (-1);
}