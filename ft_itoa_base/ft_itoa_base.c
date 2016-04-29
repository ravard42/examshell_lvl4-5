#include <stdlib.h>

int		octet_needed(unsigned int val, int base)
{
	int		i;

	i = 1;
	while ((val = val / base) != 0)
		i++;
	return (i);
}

char	*ft_itoa_base(int value, int base)
{
	int				exept;
	unsigned int	val;
	int				*tab;
	char			*ret;
	int				len;
	int				i;

	exept = (value < 0 && base == 10) ? 1 : 0;
	val = (unsigned int)(value < 0) ? -value : value;
	len = octet_needed(val, base);
	tab = (int *)malloc(sizeof(int) * len);
	tab[len - 1] = val % base;
	i = 2;
	while (i <= len)
	{
		val = val / base;
		tab[len - i] = val % base;
		i++;
	}
	ret = (char *)malloc(sizeof(char) * (len + exept + 1));
	if (exept == 1)
		ret[0] = '-';
	i = 0;
	while (i < len + exept)
	{
		if (tab[i] <= 9)
			ret[i + exept] = '0' + tab[i];
		else
			ret[i + exept] = 'A' - 10 + tab[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
