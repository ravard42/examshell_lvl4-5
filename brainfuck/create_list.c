#include "brainfuck.h"

t_list		*new_elem(t_list *prev, int	indice)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (prev)
		prev->next = new;
	new->next = NULL;
	new->debut_boucle = indice;
	return (new);
}

void		lf_end_loop(t_list *list, char *str)
{
	int	i;
	int	cpt;
	
	while (list)
	{
		i = list->debut_boucle + 1;
		cpt = 1;
		while (cpt != 0)
		{
			if (str[i] == '[')
				cpt++;
			if(str[i] == ']')
				cpt--;
			i++;
		}
		list->fin_boucle = i - 1;
		list = list->next;
	}
}


t_list		*create_list(char *str)
{
	int		i;
	t_list		*begin;
	t_list		*list;

	begin = NULL;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '[')
		{
			if (!begin)
			{
				begin = new_elem(NULL, i);
				list = begin;
			}
			else
				list = new_elem(list, i);
		}
	}
	lf_end_loop(begin, str);	
	return (begin);
}
