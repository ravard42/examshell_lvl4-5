#include "brainfuck.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
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
			list = create_list(argv[1]);
			octet[0] = 0;
			operateur[0] = 0;
			while (argv[1][operateur[0]])
				ft_inter_brainfuck(tab, octet, argv[1], operateur, list);
			free(tab);
		}
		return (0);
}	
