#ifndef BRAINFUCK_H
# define BRAINFUCK_H

#include <unistd.h>
#include <stdlib.h>

typedef struct			s_list
{
	int				debut_boucle;
	struct s_list	*prev;
}						t_list;

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_inter_brainfuck(char *tab, int octet, char *s, int operateur, t_list *list_prev);

#endif
