void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int		i;
	int					tmp;
	int					action;

	i = -1;
	action = 0;
	while (++i < size - 1 )
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			action = 1;
		}
	}
	if (action == 1)
		sort_int_tab(tab, size);
}
