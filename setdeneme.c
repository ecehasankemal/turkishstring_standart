/*#include <stdio.h>
#include <wchar.h>

void	print_wchar(wchar_t wc)
{
	__asm__("movw %1, %%ax\n\t""movw %%ax, %0\n\t": "=m"(wc): "m"(wc));
	printf("%lc", (wchar_t)wc);
}

int	main(void)
{
	wchar_t	a = L'a';
	print_wchar(a);
	return (0);
}*/
/*#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#define ldbl_strong_alias(name aliasname)

int	main(void)
{
	setlocale(LC_ALL, "");
	wint_t	a = L'Ö';
	printf("%lc", a);
	return (0);
}*/

/*#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>

void	ft_put(wchar_t *str)
{
	short index;

	index = 0;
	while (str[index] != '\0')
	{
		printf("%lc", (wchar_t)str[index]);
		index++;
	}
}

void	print_alphabet(void)
{
	setlocale(LC_ALL, "");

	wchar_t	a;
	wchar_t	*alphabet;
	short	index;

	alphabet = (wchar_t *)malloc(sizeof(wchar_t) * 27);
	index = 0;
	a = L'a';
	while (index < 29)
	{
		alphabet[index] = a;
		if (a == L'c')
		{
			index++;
			alphabet[index] = L'ç';
		}
		a++;
		index++;
	}
	ft_put(alphabet);
}

int	main(void)
{
	print_alphabet();
	return (0);
}*/

// #########################################################

/*#include <unistd.h>
#include <stdlib.h>

void	ft_put(char *str)
{
	short	index;

	index = 0;
	while (str[index] != '\0')
	{
		write(1, &str[index], 1);
		index++;
	}
}

void	print_alphabet(void)
{
	char	a;
	char	*alphabet;
	short	index;

	alphabet = (char *)malloc(sizeof(char) * 36);
	index = 0;
	a = 'a';
	while (index < 36)
	{
		alphabet[index] = a;
		if (alphabet[index] == 'c')
		{
			index++;
			alphabet[index] = -61;
			index++;
			alphabet[index] = -89;
		}
		else if (alphabet[index] == 'i')
		{
			index++;
			alphabet[index] = -60;
			index++;
			alphabet[index] = -79;
		}
		else if (alphabet[index] == 'o')
		{
			index++;
			alphabet[index] = -61;
			index++;
			alphabet[index] = -74;
		}
		else if (alphabet[index] == 's')
		{
			index++;
			alphabet[index] = -59;
			index++;
			alphabet[index] = -97;
		}
		else if (alphabet[index] == 'u')
		{
			index++;
			alphabet[index] = -61;
			index++;
			alphabet[index] = -68;
		}
		index++;
		a++;
	}
	ft_put(alphabet);
}

int	main(void)
{
	print_alphabet();
	return (0);
} */

#include <string.h>
#include <stdio.h>

short	ft_strlen(char *str)
{
	short	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

short main(void)
{
	char	*str = strdup("İĞÜŞÖÇ");
	char	*str3 = strdup("Ü");
	//printf("%d", str[0]);
	//printf(" %d", str[1]);
	//printf("--- %d", str[2]);
	//printf (" %d", str[3]);
	printf("--- %d", str[4]);
	printf (" %d", str[5]);
	printf("--- %d", str[6]);
	printf (" %d", str[7]);
	//printf("--- %d", str[8]);
	//printf (" %d", str[9]);
	//printf("--- %d", str[10]);
	//printf (" %d", str[11]);
	char	*str2 = "ß";
	//printf("  {{%s}}, << %d >> << %d >> << %d >> << %d >> ", str2, str2[0], str2[1], str2[2], str2[3]);
	printf("\n------ %d -------\n", ft_strlen("şü"));
	printf("\n ------% d -------\n", ft_strlen(str3));
	return (0);
} 