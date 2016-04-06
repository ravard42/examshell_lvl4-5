#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"
#include <unistd.h>

void	ft_putchar(char c)  // pour debug sefault car ca chie avec printf .... sait pas pk mais c reccurent!
{
	write(1, &c, 1);
}



int	cmp(int	*a, int *b)                    //j  defini cmp avant histoire de pas avoir a le foutre ds le .h, pour la chrono de la compile QUOI
{
	if (*a == *b)
		return (1);
	else
		return (0);
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())   // la seule fonction a push
{
	t_list	*list;
	t_list	*list_to_ret;
	
	list_to_ret = NULL;
	list = *begin_list;
	while (list)
	{
		if (!(*cmp)(data_ref, list->data))
		{
			if (list_to_ret == NULL)       //on coffre le first a garder pour renvoyer
			{
				list_to_ret = list;
				*begin_list = list_to_ret;
			}
			else
				list_to_ret->next = list; // on coffre les maillon valides
		}		 
		list = list->next;		//on parcout la liste de depart
	}
	list_to_ret->next = NULL;
}

t_list	*new_elem(t_list *list_prev, int i)     //creation du vehicule de test!!! en gros tout le reste ne sera pas a rendre et cmp non plus d ailleur!
{
	t_list	*new;
	int	*tmp;
	
	new = (t_list *)malloc(sizeof(t_list));
	tmp = (int *)malloc(sizeof(int));
	tmp[0] = i;
	new->data = tmp;
	new->next = NULL;
	if (list_prev)
		list_prev->next = new;
	return (new);
}

void	print_list(t_list *list)
{
	while (list)
	{
		printf("%d\n", *((int *)(list->data)));
		list = list->next;
	}
		
}

int	main(void)
{
	t_list	*begin;
	t_list	*list;
	int	i;
	int	tarace[1];

	begin = NULL;
	list = NULL;
	i = 0;
	tarace[0] = 0;
	while (i < 10)
	{
		list = new_elem(list, i % 2);
		if (begin == NULL)
			begin = list;
		i++;
	}
//	print_list(begin);
	ft_list_remove_if(&begin, tarace, &cmp);
	print_list(begin);
	return (0);
}
