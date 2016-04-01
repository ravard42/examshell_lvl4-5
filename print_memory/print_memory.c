#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	decimal_to_hexa (char chiffre, int signe)
{
	if (signe == 1)
	{
		if (chiffre >= 0 && chiffre <= 9)
			ft_putchar('0' + chiffre);
		else
			ft_putchar('a' + chiffre - 10);
	}
	else
	{
		if (chiffre <= 0 && chiffre >= -5)
			ft_putchar('f' + chiffre);
		else
			ft_putchar('9' + chiffre + 6);
	}
}

void	ft_hexa_putchar(char c)
{
	int	h;
	int	u;

	if (c >= 0)
	{
		h = c / 16;
		u = c % 16;
		decimal_to_hexa(h, 1);
		decimal_to_hexa(u, 1);
	}
	else
	{
		h = (-1 -c) / 16;
		u = (-1 -c) % 16;
		decimal_to_hexa(-h, -1);
		decimal_to_hexa(-u, -1);
		
	}
}

void	ft_put_carac(const void *addr, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
	{
		if (*((char *)addr + i) >= 33 && *((char *)addr + i) <= 126)
			ft_putchar(*((char *)addr + i));
		else
			ft_putchar('.');
	}
	ft_putchar('\n');
}

void	spaces(int n)
{
	int	i;

	i = -1;
	while (++i < n)
		ft_putchar(' ');
}

void	print_memory(const void *addr, size_t size)
{
	size_t	i;
	int		cpt;

	i = -1;
	cpt = 0;
	while (++i < size)
	{
		ft_hexa_putchar(*((char *)addr + i));
		cpt += 2;
		if (i % 2 == 1)
		{
			ft_putchar(' ');
			cpt++;
		}
		if ((i + 1) % 16 == 0)
			ft_put_carac(addr + i - 15, 16);
		else if (i == size - 1 && ((i + 1) % 16 != 0))
		{
			spaces(40 - cpt % 40);
			ft_put_carac(addr + i - ((i + 1) % 16), ((i + 1) % 16));
		}
	}
}
