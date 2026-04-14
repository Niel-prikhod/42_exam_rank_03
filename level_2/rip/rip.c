#include <stdio.h>
#include <unistd.h>

char buf[256];

int unmatched_count(char *str)
{
	int open_count, close_count;

	open_count = 0;
	close_count = 0;
	while (*str)
	{
		if (*str == '(')
			open_count++;
		else if (*str == ')')
		{
			if (open_count > 0)
				open_count--;
			else
				close_count++;
		}
		str++;
	}
	return open_count + close_count;
}

int		count_spaces(char *str)
{
	int i = 0;

	if (!str)
		return 0;
	while (*str)
	{
		if (*str == ' ')
			i++;
		str++;
	}
	return i;
}

void	solve(char *str, int index, int min_space_count)
{
	char	c;

	c = str[index];
	if (!c)
	{
		buf[index] = '\0';
		if (!unmatched_count(buf) && count_spaces(buf) == min_space_count)
			puts(buf);
		return;
	}
	if (c == '(' || c == ')')
	{
		buf[index] = c;
		solve(str, index + 1, min_space_count);
	}
	buf[index] = ' ';
	solve(str, index + 1, min_space_count);
}

int main(int argc, char **argv)
{
	int min_spaces;
	char *str;

	if (argc != 2)
		return 1;
	str = argv[1];
	min_spaces = unmatched_count(str);
	solve(str, 0, min_spaces);
	return 0;
}
