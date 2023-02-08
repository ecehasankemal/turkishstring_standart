#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static inline void
    ft_put(char *str)
{
    register short    index;

    index = 0;
    while (str[index] != '\0')
    {
        write(1, &str[index], 1);
        index++;
    }
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
    register short  counter;
    register short  result;

    counter = -1;
    result = 0;
    while (counter++, string[counter] && counter < len + result)
        if (unicode_checker_tr(string, counter))
            result++;
    return (result + len);
}

static inline short
    unicode_checker_calculator(char *str, int len, int n)
{
    short   count;

    count = -1;
    while (count++, str[count] && count < len + n)
        if (unicode_checker_tr(str, count))
            n++;
    return (n);
}

static inline short
    ft_turkishstrlen(char *str)
{
    register short   count;
    register short   count2;

    count = 0;
    count2 = 0;
    while (str[count])
        count++;
    count2 = unicode_checker_calculator(str, count, count2);
    return (count - count2);
}

static inline short
    ft_americanstrlen(char *str)
{
    register short  count;

    count = 0;
    while (str[count])
        count++;
    return (count);
}

static inline char
    *ft_turkishstrlcpy(char *str, char *ptr, int len)
{
    char    difference;
    short   index;

    difference = ft_americanstrlen(str) - len;
    ptr = (char *)malloc(sizeof(char) * (ft_turkishstrlen(str) + difference));
    index = 0;
    while (index < (ft_turkishstrlen(str) + difference))
    {
        ptr[index] = str[index];
        index++;
    }
    return (ptr);
}

int
    main(int ac, char *av[])
{
    char    *ptr;
    char    *save;
    short   index;
    int     len;

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
    printf("\n--%d--\n", ft_turkishstrlen("ırmak"));
    printf("girilen input %d karakterdir\n", ft_turkishstrlen(ptr));

    save = ft_turkishstrlcpy(ptr, save, ft_turkishstrlen(ptr));
    printf("--%s--\n", save);
    free(ptr);
    return (0);
}