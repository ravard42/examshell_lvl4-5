#include <unistd.h>
#include <stdlib.h>


typedef struct		s_list
{
	char		*ptr_sur_next_w;
	char		*word;
	struct s_list	*next;
}			t_list;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		ft_putchar(s[i]);
}

char	*rm_wsp(char *s)
{
	int	i;

	i = -1;
	while (s[++i] == ' ' || s[i] == '\t')
		;
	return (s + i);
}

char	*revstr(char *s)
{
	int	len;
	char	*ret;
	int	i;

	len = -1;
	while (s[++len])
		;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	i = -1;
	while (++i < len)
		ret[len - 1 - i] = s[i];
	ret[len] = '\0';
	return (ret);
}

t_list	*new_elem(t_list *prev, char *ptr_sur_w,  int *end)
{
	t_list	*new;
	int	len;
	int	i;
	char	*word;

	len = -1;
	while (ptr_sur_w[++len] != ' ' && ptr_sur_w[len] != '\t' && ptr_sur_w[len] != '\0')
		;
	if (ptr_sur_w[len] == '\0')
		end[0] = 1;
	word = (char *)malloc(sizeof(char) * (len + 1));
	i = -1;
	while (++i < len)
		word[i] = ptr_sur_w[i];
	word[i] = '\0';
	new = (t_list *)malloc(sizeof(t_list));
	if (!end[0])
		new->ptr_sur_next_w = rm_wsp(ptr_sur_w + len);
	new->word = word;
	new->next = NULL;
	if (prev)
		prev->next = new;
	return (new);
}

t_list	*create_list(char *str)
{
	t_list	*begin;
	t_list	*list;
	int	end[0];

	list = NULL;
	end[0] = 0;
	while (!end[0])
	{
		if (list == NULL)
		{
			list = new_elem(NULL, str, end);
			begin = list;
		}
		else
			list = new_elem(list, list->ptr_sur_next_w, end);
	}
	list->next = begin;
	list = begin->next;
	begin->next = NULL;
	return (list);
}

void	print_list(t_list *list)
{
	while (list)
	{
		ft_putstr(list->word);
		if (list->next)
			ft_putchar(' ');
		else
			ft_putchar('\n');
		list = list->next;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_putchar('\n');
	else
		print_list(create_list(revstr(rm_wsp(revstr(rm_wsp(argv[1]))))));
	return (0);
}
