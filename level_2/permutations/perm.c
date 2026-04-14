// Allowed functions: puts, malloc, calloc, realloc, free, write

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static int ft_strlen(char *s)
{
	int i;

	if (!s)
		return 0;
	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return i;
}

static char *sort_string(char *str)
{
	unsigned char tmp = 0;
	int		i = 1;

	if (!str)
		return NULL;
	if (ft_strlen(str) == 1)
		return str;
	while (str[i])
	{
		while (str[i] < str [i - 1] && i > 0)
		{
			tmp = str[i];
			str[i] = str[i - 1];
			str[i - 1] = tmp;
			i--;
		}
		i++;
	}

	return str;
}

static int	find_permutee(char *str, int len)
{
	int i;

	i = len - 2;
	while (i >= 0)
	{
		if (str[i] < str[i+1])
			return i;
		i--;
	}
	return i;
}

static int find_smallest(char *str)
{
	int i = 1;
	int min = 1;
	
	if (ft_strlen(str) == 1)
		return 0;
	while (str[i])
	{
		if (str[i] < str[min] && str[0] < str[i])
			min = i;
		i++;
	}
	return min;
}

static void swap_char(char *str1, char *str2)
{
	char tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

static int	next_permutation(char *str, int len)
{
	int i;
	int j;

	i = find_permutee(str, len);
	if (i < 0)
		return 0;
	j = i + find_smallest(str + i);

	swap_char(&str[i], &str[j]);
	sort_string(str + i + 1);
	return 1;
}

int main(int argc, char **argv)
{
	char *str = NULL;
	int		len = 0;

	if (argc != 2)
		return 0;
	str = argv[1];
	str = sort_string(str);
	len = ft_strlen(str);
	puts(str);
	while (next_permutation(str, len))
		puts(str);
	return 0;
}
