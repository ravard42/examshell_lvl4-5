#ifndef BRAINFUCK_H
# define BRAINFUCK_H

#include <unistd.h>
#include <stdlib.h>

typedef struct			s_list
{
	int				debut_boucle;
	int				fin_boucle;
	struct s_list			*next;
}						t_list;

void	ft_putchar(char c);
t_list	*create_list(char *str);
void	ft_inter_brainfuck(char *tab, int *octet, char *s, int *operateur, t_list *list);

#endif
