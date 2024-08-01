#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	while (*src)
	{
		dest[dest_len + i] = *src;
		i++;
		src++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

int	ft_any(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	is_bigger(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

int	main(void)
{
	char	str1[] = "abgDDc";
	char	str2[] = "bahhKhhhhchp";
	int		i;
	int		j;
	char	res[1000];
	int		bigger;

	i = 0;
	j = 0;
	bigger = is_bigger(ft_strlen(str1), ft_strlen(str2));
	while (i < bigger)
	{
		if (str1[i] != '\0' && ft_any(res, str1[i]) != 1)
		{
			res[j] = str1[i];
			j++;
		}
		if (str2[i] != '\0' && ft_any(res, str2[i]) != 1)
		{
			res[j] = str2[i];
			j++;
		}
		i++;
	}
	res[j] = '\0';
	printf("%s", res);
	return (0);
}
