#include "../cub3d.h"

void ft_free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13) || c == ',')
		return (1);
	return (0);
}

int count_word(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		while (is_space(*str))
			str++;
		if (*str == '\0')
			break;
		while (!is_space(*str) && *str != '\0')
			str++;
		count++;
	}
	return (count);
}

char *ft_strndup(char *str, unsigned int n)
{
	unsigned int i;
	char *dup;

	dup = (char *)malloc((n + 1) * sizeof(char));
	i = 0;
	while (i < n)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char **ft_split_line(char *str)
{
	int i;
	int word_count;
	char *word_start;
	char **array;

	word_count = count_word(str);
	array = (char **)malloc((word_count + 1) * sizeof(char *));
	i = 0;
	while (*str)
	{
		while (is_space(*str))
			str++;
		if (*str == '\0')
			break;
		word_start = str;
		while (!is_space(*str) && *str != '\0')
			str++;
		array[i] = ft_strndup(word_start, str - word_start);
		i++;
	}
	array[i] = 0;
	return (array);
}
