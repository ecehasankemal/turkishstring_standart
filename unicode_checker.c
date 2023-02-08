#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

short    unicode_checker(char *str)
{
    short    result;
    short    index;

    index = 0;
    result = 0;
    while (str[index] != '\0')
    {
        if ((str[index] == -61 && str[index + 1] == -89)
            || (str[index] == -60 && str[index + 1] == -79)
            || (str[index] == -61 && str[index + 1] == -74)
            || (str[index] == -59 && str[index + 1] == -97)
            || (str[index] == -61 && str[index + 1] == -68)
            || (str[index] == -60 && str[index + 1] == -97))
        {
            result++;
            index += 2;
        }
        else
            index++;
    }
    return (result);
}

void    ft_put(char *str)
{
    short    index;

    index = 0;
    while (str[index] != '\0')
    {
        write(1, &str[index], 1);
        index++;
    }
}

short    ft_strlen(char *str)
{
    short count;

    count = 0;
    while (str[count])
        count++;
    return (count);
}

short	ft_turkishstrlen(char *str)
{
	short	count;

	count = 0;
	while (str[count])
		count++;
	return (count - unicode_checker(str));
}

char	*ft_turkishstrlcpy(char *str, int len)
{
	char	*ptr;
	short	index;

	ptr = (char *)malloc(sizeof(char) * (len + unicode_checker(str)));
	index = 0;
	while (index < (len + unicode_checker(str)))
	{
		ptr[index] = str[index];
		index++;
	}
	return (ptr);
}

short    main(int ac, char *av[])
{
    char    *ptr;
    short    index;
    char	*save;

    index = 0;
    char copy_av[2];
    int len = 5 + unicode_checker(av[1]);
    ptr = (char *)malloc(sizeof(char) * (5 + unicode_checker(av[1])));
    if (ac == 2)
    {
        while (index < len)
        {
            copy_av[0] = av[1][index];
            copy_av[1] = av[1][index+1];
            if (unicode_checker(copy_av))
            {
                if (index + 1 == len)
                    index++;
                else
                {
                    ptr[index] = av[1][index];
                    ptr[index+1] = av[1][index+1];            
                    index += 2;
                }
            }
            else
            {
                ptr[index] = av[1][index];
                index++;
            }
        }
        ft_put(ptr);
        printf("\n%d\n", ft_turkishstrlen(ptr));
        printf("omer is len = %d\n", ft_turkishstrlen("omer"));
        printf("ömer is len = %d\n", ft_turkishstrlen("ömer"));
        printf("\n");

        save = ft_turkishstrlcpy(ptr, ft_turkishstrlen(ptr));
        printf("%s\n", save);
    }
    free(ptr);
    return (0);
}