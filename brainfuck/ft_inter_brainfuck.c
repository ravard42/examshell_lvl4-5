#include "brainfuck.h"

t_list	*ft_inter_brainfuck(char *tab, int *octet, char *s, int *operateur, t_list *list_prev)
{
	t_list		*list;

	if (s[operateur[0]] == '[')
	{
		list = (t_list *)malloc(sizeof(t_list));
		list->debut_boucle = operateur[0] + 1;
		list->prev = list_prev;
		operateur[0]++;
		return (list);
	}
	else if (s[operateur[0]] == ']')
	{
		if (tab[octet[0]] == 0)
		{
			operateur[0]++;
			return (list_prev->prev);
		}
		else
		{
			operateur[0] = list_prev->debut_boucle;
			return (list_prev);
		}
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
	return (list_prev);
}



