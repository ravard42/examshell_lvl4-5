#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	brainfuck(char *s)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = (char *)malloc(sizeof(char) * 2048);
	i = -1;
	while (++i < 2048)
		ptr[i] = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '>')
			ptr++;
		else if (s[i] == '<')
			ptr--;
		else if (s[i] == '+')
			(*ptr)++;
		else if (s[i] == '-')
			(*ptr)--;
		else if (s[i] == '.')
			ft_putchar((*ptr));
		else if (s[i] == '[' && (*ptr) == 0)
		{
			i++;
			j = 1;
			while (j)
			{
				if (s[i] == '[')
					j++;
				else if (s[i] == ']')
					j--;
				i++;
			}
			i--;
		}
		else if (s[i] == ']')
		{
			i--;
			j = -1;
			while (j)
			{
				if (s[i] == '[')
					j++;
				else if (s[i] == ']')
					j--;
				i--;
			}
		}
		i++;
	}
}


int		main(int argc, char **argv)
{
	if (argc == 2)
		brainfuck(argv[1]);
	else
		ft_putchar('\n');
	return (0);
}
