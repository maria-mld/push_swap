/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoldo <marmoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:29:50 by marmoldo          #+#    #+#             */
/*   Updated: 2026/03/21 21:31:31 by marmoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static void	free_all(char **array, int word_index)
{
	while (word_index >= 0)
		free(array[word_index--]);
	free(array);
}

static char	*word_dup(const char *start, const char *end)
{
	char	*word;
	int		i;

	word = malloc((end - start) + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = *start++;
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		word_index;
	const char	*start;

	if (!s || !(array = malloc((count_words(s, c) + 1) * sizeof(char *))))
		return (NULL);
	word_index = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			array[word_index] = word_dup(start, s);
			if (!array[word_index])
				return (free_all(array, word_index - 1), NULL);
			word_index++;
		}
		else
			s++;
	}
	return (array[word_index] = NULL, array);
}


// char	*world_dup(const char *start, const char *end)
// {
// 	char	*word;
// 	int		len;
// 	int		i;

// 	len = end - start;
// 	word = malloc(len + 1);
// 	i = 0;
// 	if (!word)
// 		return (NULL);
// 	while (start < end)
// 	{
// 		word[i++] = *start;
// 		start++;
// 	}
// 	word[i] = '\0';
// 	return (word);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char		**array;
// 	int			words_count;
// 	int			word_index;
// 	const char	*start;

// 	if (!s)
// 		return (NULL);
// 	word_index = 0;
// 	words_count = count_words(s, c);
// 	array = malloc((words_count + 1) * sizeof(char *));
// 	if (!array)
// 		return (NULL);
// 	while (*s)
// 	{
// 		if (*s != c)
// 		{
// 			start = s;
// 			while (*s != c && *s)
// 				s++;
// 			array[word_index++] = world_dup(start, s);
// 		}
// 		else
// 			s++;
// 	}
// 	return (array[word_index] = NULL, array);
// }

// int main()
// {
// 	char *str = "  ";
// 	char **array = ft_split(str, ' ');
// 	int i = 0;
// 	while (array[i])
// 	{
// 		printf("%s\n", array[i]);
// 		i++;
// 	}
// }