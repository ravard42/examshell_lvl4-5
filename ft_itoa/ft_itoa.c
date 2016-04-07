#include <stdlib.h>

int		nbr_octet(int	nbr)
{
	int		i;

	i = 1;
	while ((nbr = nbr / 10))
		i++;
	return (i);
}

char	*ft_itoa(int nbr)
{
	char	*ret;
	int		neg;
	int		len;
	int		i;
	int		exept;

	neg = (nbr >= 0) ? 0 : 1;
	exept = (nbr == -2147483648) ? 1 : 0;
	if (exept)
		nbr = 2147483647;
	nbr = (nbr > 0) ? nbr : -nbr;
	len = nbr_octet(nbr) + neg;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	ret[len - 1] = '0' + nbr % 10;
	i = len - 2;
	while ((nbr = nbr / 10))
	{
		ret[i] = '0' + nbr % 10;
		i--;
	}
	if (exept)
		ret[len - 1] = '0' + 8;
	if (neg)
		ret[0] = '-';
	return (ret);
}
