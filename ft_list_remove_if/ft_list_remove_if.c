#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())   // la seule fonction a push
{
	t_list	*list;
	t_list	*list_to_ret;
	t_list	*elem_to_free;
	
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
			{
				list_to_ret->next = list; // on coffre les maillon valides
				list_to_ret = list_to_ret->next;
			}
			list = list->next;
		}
		else
		{
			elem_to_free = list;
			list = list->next;		//on parcout la liste de depart
			free(elem_to_free);
		}		
	}
	if (list_to_ret == NULL)
		*begin_list = NULL;
	else
		list_to_ret->next = NULL;
}
