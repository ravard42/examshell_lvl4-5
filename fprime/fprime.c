#include <stdlib.h>
#include <stdio.h>

unsigned int	racine_inf_de(unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (i * i <= nbr)
		i++;
	return (i);
}

int	is_prime(unsigned int nbr)
{
	unsigned int 	i;

	i = 1;
	while ( ++i <= racine_inf_de(nbr))
		if (nbr % i == 0)
			return (0);
	return (1);
}

unsigned int	next_prime(unsigned int prime)
{
	unsigned int	i;

	i = prime + 1;
	while (!is_prime(i))
		i++;
	return (i);
}


void	fprime(unsigned int nbr)
{
	int prime;

	prime = 2;
	while (nbr != 1)
	{
		if (is_prime(nbr))
		{
			printf("%d\n", nbr);
			nbr = 1;
		}
		else if (nbr % prime != 0)
			prime = next_prime(prime);
		else
		{
			nbr = nbr / prime;
			if (nbr != 1)
				printf("%d*", prime);
			else
				printf("%d\n", prime);
		}
	}
}


int	main(int argc, char **argv)
{
	if (argc != 2)
		printf("\n");
	else
		fprime(atoi(argv[1]));
	return (0);
}
