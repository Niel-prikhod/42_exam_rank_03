#include "get_next_line.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int	main(void) {
	char *str1 = "hello ";
	char *str2 = "world";
	char *res = ft_strjoin(str1, str2);
	if (!res)
		return (1);
	printf("%s\n", res);
	free (res);
	res = NULL;
	return 0;
}
