#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void
	ft_put(char *string)
{
	register short	index;

	index = -1;
	while (index++, string[index])
		write(1, &string[index], 1);
}

short
	ft_strlen(char *string)
{
	register short	counter;

	counter = 0;
	while (string[counter])
		counter++;
	return (counter);
}

static inline short
	unicode_checker_tr(char *string, register short index)
{
	if ((string[index] == -61 && string[index + 1] == -89) \
		|| (string[index] == -60 && string[index + 1] == -79) \
		|| (string[index] == -61 && string[index + 1] == -74) \
		|| (string[index] == -59 && string[index + 1] == -97) \
		|| (string[index] == -61 && string[index + 1] == -68))
		return (1);
	return (0);
}

static inline short
	unicode_len(char *string, register int len)
{
	register short	counter;
	register short	result;

	counter = -1;
	result = 0;
	while (counter++, string[counter] && counter < len + result)
		if (unicode_checker_tr(string, counter))
			result++;
	return (result + len);
}

int
	main(int ac, char *av[])
{
	char	*ptr;
	short	index;
	int		len;

	index = -1;
	len = unicode_len(av[1], 5);
	printf("[%d]\n", len);
	ptr = (char *)malloc(sizeof(char) * len);
	if (ac == 2)
	{
		while (index++, index < len)
			ptr[index] = av[1][index];
		ptr[index] = 0;
		ft_put(ptr);
		printf("\n");
	}
	free(ptr);
	return (0);
}