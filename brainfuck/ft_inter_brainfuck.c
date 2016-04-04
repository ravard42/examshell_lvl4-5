#include "brainfuck.h"

t_list		*lf_maillon(int	indice, t_list *list)
{
	while (list)
	{
		if (list->debut_boucle == indice || list->fin_boucle == indice)
			return (list);
		list = list->next;
	}
	return (NULL);
}



void		ft_inter_brainfuck(char *tab, int *octet, char *s, int *operateur, t_list *list)
{
	if (s[operateur[0]] == '[')
	{
		if (tab[octet[0]] == 0)
			operateur[0] = lf_maillon(operateur[0], list)->fin_boucle + 1;
		else
			operateur[0]++;
	}
	else if (s[operateur[0]] == ']')
	{
		if (tab[octet[0]] != 0)
			operateur[0] = lf_maillon(operateur[0], list)->debut_boucle + 1;
		else
			operateur[0]++;
	}
	else if (s[operateur[0]] == '>')
	{
		octet[0]++;
		operateur[0]++;
	}	
	else if (s[operateur[0]] == '<')
	{
		octet[0]--;
		operateur[0]++;
	}
	else if (s[operateur[0]] == '+')
	{
		tab[octet[0]]++;
		operateur[0]++;
	}
	else if (s[operateur[0]] == '-')	
	{
		tab[octet[0]]--;
		operateur[0]++;
	}
	else if (s[operateur[0]] == '.')
	{
		ft_putchar(tab[octet[0]]);
		operateur[0]++;
	}
	else
		operateur[0]++;
}



