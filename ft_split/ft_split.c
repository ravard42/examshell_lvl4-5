#include <stdlib.h>

typedef struct			s_list
{
	char				*indice_next_word;
	char				*word;
	struct s_list		*prev;
	struct s_list		*next;
}						t_list;

char		*rm_wsp(char *str)
{
	int			i;

	i = -1;
	while (str[++i] == '\n' || str[i] == ' ' || str[i] == '	')
		;
	return (str + i);
}

char	*revstr(char *s)
{
	int		i;
	int		len;
	char	*tmp;

	len = -1;
	while (s[++len])
		;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	i = -1;
	while (++i < len)
		tmp[i] = s[len - i - 1];
	tmp[i] = '\0';
	return (tmp);
}

t_list		*new_elem(t_list *list_prev, char *str, int *end)
{
		int		i;
		char	*tmp;
		t_list	*new;

		str = (list_prev) ? list_prev->indice_next_word : str; 
		i = -1;
		while (str[++i] != '\n' && str[i] != ' ' && str[i] != '	' && str[i] != '\0')
			;
		if (str[i] == '\0')
			*end = 1;
		tmp = (char *)malloc(sizeof(char) * (i + 1));
		i = -1;
		while (str[++i] != '\n' && str[i] != ' ' && str[i] != '	' && str[i] != '\0')
			tmp[i] = str[i];
		tmp[i] = '\0';
		new  = (t_list *)malloc(sizeof(t_list));
		if (!(*end))
			new->indice_next_word = rm_wsp(str + i);
		new->word = tmp;
		new->prev = list_prev;
		if (list_prev)
			list_prev->next = new;
		new->next = NULL;
		return (new);
}

char	**ft_split(char *str)
{
		t_list		*list;
		int			numb_w;
		int			end[1];
		char		**ret;
		int			i;

		if (!str)
		{
			ret = (char **)malloc(sizeof(char *));
			*ret = NULL;
			return (ret);
		}
		str = revstr(rm_wsp(revstr(rm_wsp(str))));
		if (str[0] == '\0')
		{
			ret = (char **)malloc(sizeof(char *));
			*ret = NULL;
			return (ret);
		}
		list = NULL;
		numb_w = 0;
		end[0] = 0;
		while (end[0] == 0)
		{
			list = new_elem(list, str, end);
			numb_w++;
		}
		while (list->prev)
			list = list->prev;
		ret = (char **)malloc(sizeof(char *) * (numb_w + 1));
		i = 0;
		while (list)
		{
			ret[i] = list->word;
			i++;
			list = list->next;
		}
		ret[i] = NULL;
		return (ret);
}
