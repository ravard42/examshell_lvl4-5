#include <unistd.h>
#include <stdlib.h>

void					ft_putchar(char c)
{
			write(1, &c, 1);
}

void					ft_putstr(char *s)
{
	int		i;

	i = -1;
	if (s)
		while (s[++i])
			ft_putchar(s[i]);
}

typedef struct			s_list
{
		struct s_list	*prev;
		struct s_list	*next;
		char			*word;
		char			*ptr_sur_next_word;
}						t_list;

int						size_word(char *ptr_sur_word, int *fin)
{
			int		i;
			
			i = 0;
			while (ptr_sur_word[i] != ' ' && ptr_sur_word[i] != '\t' && ptr_sur_word[i] != '\0')
				++i;
			if (ptr_sur_word[i] == '\0')
				*fin = 1;
			return (i);
}

t_list					*new_elem(t_list *prev, char *ptr_sur_word, int *fin)
{
			t_list		*new;
			int			size;
			char		*tmp;
			int			i;

			new = (t_list *)malloc(sizeof(t_list));
			size = size_word(ptr_sur_word, fin);
			tmp = (char *)malloc(sizeof(char *) * (size + 1));
			i = -1;
			while (++i < size)
				tmp[i] = ptr_sur_word[i];
			tmp[i] = '\0';
			new->prev = prev;
			if (new->prev != NULL)
				prev->next = new;
			new->next = NULL;
			new->word = tmp;
			new->ptr_sur_next_word = (*fin == 0) ? ptr_sur_word + size + 1 : NULL;
			return (new);
}

t_list				*create_list(char * str)
{
	int		a;	
	int		*fin;
	t_list	*list;

	a = 0;
	fin = &a;
	list = new_elem(NULL, str, fin);
	while (*fin == 0)
		list = new_elem(list, list->ptr_sur_next_word, fin);
	return (list);
}

void			print_list(t_list *list)
{
			while(list->prev)
			{
				ft_putstr(list->word);
				ft_putchar(' ');
				list = list->prev;
			}
			ft_putstr(list->word);
			ft_putchar('\n');
}

int				main(int argc, char ** argv)
{
			if (argc != 2)
				ft_putchar('\n');
			else
				print_list(create_list(argv[1]));
			return (0);
}
