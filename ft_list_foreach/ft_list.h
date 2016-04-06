#ifndef LIST_H
# define LISTE_H

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

#endif
