#include <stdlib.h>

int	octet_needed(int value, int base)
{
	int	i;

	i = 1;
	while ((value = (value / base)) != 0)
		i++;
	return (i);
}	

char	*ft_itoa_base(int value, int base)
{
	int			exept;
	unsigned int		val;
	int			len;
	char			*tab;
	char			*ret;
	int			i;

	exept = (base == 10 && value < 0) ? 1 : 0;
	val = (unsigned int)(exept == 1) ? -value : value;
	len = octet_needed(val, base);
	tab = (char *)malloc(sizeof(char) * len);
	tab[len - 1] = val % base;
	i = 2;
	while (i <= len)
	{
		val = val / base;
		tab[len - i] = val % base;
		i++;
	}
	ret = (char *)malloc(sizeof(char) * (len + exept + 1));
	if (exept)
		ret[0] = '-';
	i = -1;
	while (++i < len)
	{
		if (tab[i] >= 0 && tab[i] <= 9)
			ret[i + exept] = '0' + tab[i];
		else if (tab[i] >= 10 && tab[i] <= 16)
			ret[i + exept] = 'A' - 10 + tab[i];
	}
	ret[i + exept] = '\0';
	return (ret);
}
