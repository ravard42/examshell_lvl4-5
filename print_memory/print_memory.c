#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_hexamemory(unsigned char c)
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
		ft_put_hexamemory(c / 16);
		ft_put_hexamemory(c % 16);
	}
}

void	ft_put_hexamemory_bis(unsigned char c)
{
	if (c < 16)
		ft_putchar('0');
	ft_put_hexamemory(c);
}

void	print_memory(const void *addr, size_t size)
{
	int	cpt;
	int	l_cpt;
	size_t	i;
	size_t	j;
	int	first;

	i = 0;
	first = 0;
	while (i < size)
	{
		cpt = 0;
		j = i;
		while (i < size && cpt < 40)
		{
			ft_put_hexamemory_bis(*((char *)addr + i));
			i++;
			cpt += 2;
			if (i < size)
			{
				ft_put_hexamemory_bis(*((char *)addr + i));
				cpt += 2;
				i++;
			}
			ft_putchar(' ');
			cpt++;
		}
		if (first == 0)
			l_cpt = cpt;
		else
		{
			while (cpt != l_cpt)
			{
				ft_putchar(' ');
				cpt++;
			}
		}
		while (j < i)
		{
			if (*((char *)addr + j) >= 33 && *((char *)addr + j) <= 126) 
				ft_putchar(*((char *)addr + j));
			else
				ft_putchar('.');
			j++;
		}
		ft_putchar('\n');	
		first = 1;
	}
}
