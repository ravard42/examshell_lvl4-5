#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*begin;
	int		tmp;
	int		action;

	begin = lst;
	action = 0;
	while (lst->next)
	{
		if (!(cmp)(lst->data, lst->next->data))
		{
			tmp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp;
			action = 1;
		}
		lst = lst->next;
	}
	if (action == 1)
		sort_list(begin, cmp);
	return (begin);
}
