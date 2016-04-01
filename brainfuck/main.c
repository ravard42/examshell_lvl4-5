#include "brainfuck.h"



void	ft_putchar(char c)
{
	write(1, &c, 1);
}



void	ft_putstr(char *s)
{
	int		i;

	i = -1;
	if (s)
		while (s[++i])
			ft_putchar(s[i]);
}

int		main(int argc, char **argv)
{
		char	*tab;
		int		i;
		t_list	*list;

		if (argc != 2)
			ft_putchar('\n');
		else
		{
			tab = (char *)malloc(sizeof(char) * 2048);
			i = -1;
			while (++i < 2048)
				tab[i] = 0;
			list = NULL;
			ft_inter_brainfuck(tab, 0, argv[1], 0, list);
		}
		return (0);
}	
