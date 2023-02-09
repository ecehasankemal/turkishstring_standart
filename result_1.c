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
    if ((string[index] == -61 && string[index + 1] == -89)    /* ç */\
        || (string[index] == -60 && string[index + 1] == -79) /* ı */\
        || (string[index] == -60 && string[index + 1] == -97) /* ğ */\
        || (string[index] == -61 && string[index + 1] == -74) /* ö */\
        || (string[index] == -59 && string[index + 1] == -97) /* ş */\
        || (string[index] == -61 && string[index + 1] == -68) /* ü */\
        || (string[index] == -60 && string[index + 1] == -80) /* İ */\
        || (string[index] == -60 && string[index + 1] == -98) /* Ğ */\
        || (string[index] == -61 && string[index + 1] == -100)/* Ü */\
        || (string[index] == -59 && string[index + 1] == -98) /* Ş */\
        || (string[index] == -61 && string[index + 1] == -106)/* Ö */\
        || (string[index] == -61 && string[index + 1] == -121)/* Ç */)
        return (1);
    return (0);
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
    unicode_len(char *string, register int len)
{
    register short  result;

    result = 0;
    result = unicode_checker_calculator(string, len, result);
    return (result + len);
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
    *ft_strdup(char *str)
{
    register short  index;
    char            *res;

    index = 0;
    res = (char *)malloc(sizeof(char) * ft_americanstrlen(str));
    while (str[index] != '\0')
    {
        res[index] = str[index];
        index++;
    }
    return (res);
}

static inline char
    *ft_turkishstrlcpy(char *str, char *ptr, int len)
{
    register short   index;

    index = 0;
    while (ptr[index] != '\0' && index < unicode_len(ptr, len))
    {
        str[index] = ptr[index];
        index++;
    }
    str[index] = '\0';
    return (str);
}

static inline void
    ft_turkishstrlcat(char *str, char *ptr, int len)
{
    register short index;
    register short jndex;

    index = ft_americanstrlen(str);
    jndex = 0;
    while (ptr[jndex] != '\0' && index + 1 < unicode_len(ptr, len + 1))
    {
        if (ptr[jndex] < 0 && ptr[jndex + 1] < 0)
        { 
            str[index] = ptr[jndex];
            str[index + 1] = ptr[jndex + 1];
            index+=2;
            jndex+=2;
        }
        else if (ptr[jndex] > 0)
        {
            str[index] = ptr[jndex];
            index++;
            jndex++;
        }
        else
            jndex++;
    }
    str[index] = '\0';
}

int
    main(int ac, char *av[])
{
    char    *ptr;
    char    *save;
    short   index;
    int     len;
    char    str[] = "merhabö";
    char    str2[] = "wö";
    char    str3[] = "merhabö";
    char    str4[] = "wö";

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
    ft_turkishstrlcpy(str2, str, 7);
    printf("--%s--\n", str2);
    printf("stringi uzunlugu = %d\n", ft_turkishstrlen(str2));

    ft_turkishstrlcat(str4, str3, 9);
    printf("%s\n", str4);
    free(ptr);
    return (0);
}