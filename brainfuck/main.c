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
		int	i;
		t_list	*list;
		int	octet[1];
		int	operateur[1];

		if (argc != 2)
			ft_putchar('\n');
		else
		{
			tab = (char *)malloc(sizeof(char) * 2048);
			i = -1;
			while (++i < 2048)
				tab[i] = 0;
			list = NULL;
			octet[0] = 0;
			operateur[0] = 0;
			while (argv[1][operateur[0]])
				list = ft_inter_brainfuck(tab, octet, argv[1], operateur, list);
		}
		return (0);
}	
