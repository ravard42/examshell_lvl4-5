#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthexamemory(unsigned char c)
{
	if (c < 16)
	{
		if (c <= 9)
			ft_putchar('0' + c);
		else
			ft_putchar('a' - 10 + c);
	}
	else
	{
		ft_puthexamemory(c / 16);
		ft_puthexamemory(c % 16);
	}
}

void	ft_puthexamemory2(unsigned char c)
{
	if (c < 16)
		ft_putchar('0');
	ft_puthexamemory(c);
}

void	print_memory(const void *addr, size_t size)
{
	size_t	i;
	size_t	j;
	int		cpt;

	i = 0;
	j = 0;
	while (i < size)
	{
		cpt = 0;
		while (i < size && cpt < 40)
		{
			ft_puthexamemory2(*((unsigned char *)addr + i));
			cpt += 2;
			i++;
			if (i < size)
			{
				ft_puthexamemory2(*((unsigned char *)addr + i));
				cpt += 2;
				i++;
			}
			ft_putchar(' ');
			cpt++;
		}
		while (cpt < 40)
		{
			ft_putchar(' ');
			cpt++;
		}
		while (j < i)
		{
			if (*((unsigned char *)addr + j) >= 32 && *((unsigned char *)addr + j) <= 126)
				ft_putchar(*((unsigned char *)addr + j));
			else
				ft_putchar('.');
			j++;
		}
		ft_putchar('\n');
	}
}
