#include "brainfuck.h"

void	ft_inter_brainfuck(char *tab, int octet, char *s, int operateur, t_list *list_prev)
{
	t_list		*list;

	if (s[operateur])
	{
		if (s[operateur] == '>')
			ft_inter_brainfuck(tab, octet + 1, s, operateur + 1, list_prev);	
		else if (s[operateur] == '<')
			ft_inter_brainfuck(tab, octet - 1, s, operateur + 1, list_prev);	
		else if (s[operateur] == '+')
		{
			tab[octet]++;
			ft_inter_brainfuck(tab, octet, s, operateur + 1, list_prev);
		}
		else if (s[operateur] == '-')	
		{
			tab[octet]--;
			ft_inter_brainfuck(tab, octet, s, operateur + 1, list_prev);
		}
		else if (s[operateur] == '.')
		{
			ft_putchar(tab[octet]);
			ft_inter_brainfuck(tab, octet, s, operateur + 1, list_prev);
		}
		else if (s[operateur] == '[')
		{
			list = (t_list *)malloc(sizeof(t_list));
			list->debut_boucle = operateur + 1;
			list->prev = list_prev;
			ft_inter_brainfuck(tab, octet, s, operateur + 1, list);
		}
		else if (s[operateur] == ']')
		{
			if (tab[octet] == 0)
				ft_inter_brainfuck(tab, octet, s, operateur + 1, list_prev->prev);
			else
				ft_inter_brainfuck(tab, octet, s, list_prev->debut_boucle, list_prev);
		}
		else
			ft_inter_brainfuck(tab, octet, s, operateur + 1, list_prev);

	}
}



