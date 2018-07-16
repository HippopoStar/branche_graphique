#include "libft.h"
#include <stdio.h>

int	main(void)
{
	wchar_t	test0[2];
	wchar_t	test1[4];
	wchar_t	test2[2];
	wchar_t	test3[5];
	char	*str0;
	char	*str1;
	char	*str2;
	char	*str3;

	(void)str1;
	(void)str3;
	*(test0 + 0) = L'a';
	*(test0 + 1) = L'\0';
	*(test1 + 0) = L'一';
	*(test1 + 1) = L'α';
	*(test1 + 2) = L'一';
	*(test1 + 3) = L'\0';
	*(test2 + 0) = L'ሴ';
	*(test2 + 1) = L'\0';
	*(test3 + 0) = L'一';
	*(test3 + 1) = L'α';
	*(test3 + 2) = L'一';
	*(test3 + 3) = L'ሴ';
	*(test3 + 4) = L'\0';
	str0 = ft_wildstring_to_string(test0);
	str1 = ft_wildstring_to_string(test1);
	str2 = ft_wildstring_to_string(test2);
	str3 = ft_wildstring_to_string(test3);
	ft_putstr(str0);
	ft_putchar('\n');
	ft_putstr(str1);
	ft_putchar('\n');
	ft_putstr(str2);
	ft_putchar('\n');
	ft_putstr(str3);
	ft_putchar('\n');
	return (0);
}
