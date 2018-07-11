#include "libft.h"

char	*aux2_ft_itoa_base(size_t length, t_list *lst)
{
	char	*str;
	size_t	i;

	if (!(str = (char *)malloc((length + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < length)
	{
		*(str + i) = *((char *)lst->content);
		lst = lst->next;
		i++;
	}
	*(str + length) = '\0';
	return (str);
}

char	*aux1_ft_itoa_base(t_list *l_n, size_t i, t_list *lst)
{
	t_list	new;
	char	c;

	if ((size_t)(*((int *)((l_n->next)->next)->content)) > i)
	{
		c = '0';
	}
	else if (l_n->content_size == 1)
	{
		c = '-';
		l_n->content_size = 0;
	}
	else if (((l_n->next)->next)->content_size > i)
	{
		c = ' ';
	}
	else
	{
		return (aux2_ft_itoa_base(i, lst));
	}
	new.content = (void *)(&c);
	new.next = lst;
	return (aux1_ft_itoa_base(l_n, i + 1, &new));
}

// Gerer le cas n = 0
char	*aux0_ft_itoa_base(t_list *l_n, size_t i, t_list *lst)
{
	t_list	new;
	char	c;
	int		tmp;

	if (*((int *)(l_n->content)) == 0)
	{
		return (aux1_ft_itoa_base(l_n, i, lst));
	}
	else
	{
		c = *((char *)((l_n->next)->content) + (*((int *)(l_n->content)) % (l_n->next)->content_size));
		tmp = *((int *)l_n->content) / (l_n->next)->content_size;
		l_n->content = (void *)(&tmp);
		new.content = (void *)(&c);
		new.next = lst;
		return (aux0_ft_itoa_base(l_n, i + 1, &new));
	}
}

char	*ft_itoa_base(int n, const char *base, int pres, int spac)
{
	t_list	l_n;
	t_list	l_base;
	t_list	l_length;

	l_n.content_size = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	l_n.content = (void *)(&n);
	l_n.next = &l_base;
	l_base.content = (void *)base;
	l_base.content_size = ft_strlen(base);
	l_base.next = &l_length;
	l_length.content = (void *)(&pres);
	l_length.content_size = spac;
	l_length.next = NULL;
	return (aux0_ft_itoa_base(&l_n, 0, NULL));
}
