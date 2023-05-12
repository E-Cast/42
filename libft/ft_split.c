/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 11:25:15 by ecastong          #+#    #+#             */
/*   Updated: 2023/05/10 22:12:05 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_countwords(const char *str, char sep);
static char	*st_writenextword(char **word, char *str_p1, char sep);
static void	st_freeall(char **words, int nb_words);

char	**ft_split(const char *str, char sep)
{
	char	**words;
	char	*str_ptr;
	int		nb_words;
	int		j;

	if (!str)
		return (NULL);
	nb_words = st_countwords(str, sep);
	words = ft_calloc(nb_words + 1, sizeof(char *));
	if (!words)
		return (NULL);
	j = 0;
	str_ptr = (char *)str;
	while (j < nb_words)
	{
		str_ptr = st_writenextword(&words[j], str_ptr, sep);
		if (!str_ptr)
		{
			st_freeall(words, nb_words);
			return (NULL);
		}
		j++;
	}
	return (words);
}

static int	st_countwords(const char *str, char sep)
{
	int	counter;
	int	nb_words;

	counter = 0;
	nb_words = 0;
	while (*str)
	{
		if (counter > 0 && *str == sep)
			counter = 0;
		if (counter == 0 && *str != sep)
		{
			nb_words++;
			counter++;
		}
	str++;
	}
	return (nb_words);
}

static char	*st_writenextword(char **word, char *str_p1, char sep)
{
	int	i;

	i = 0;
	while (*str_p1 && *str_p1 == sep)
		str_p1++;
	while (str_p1[i] && str_p1[i] != sep)
		i++;
	*word = ft_calloc(i + 1, sizeof(char));
	if (!*word)
		return (NULL);
	i = 0;
	while (*str_p1 && *str_p1 != sep)
	{
		(*word)[i] = *str_p1;
		i++;
		str_p1++;
	}
	(*word)[i] = '\0';
	return (str_p1);
}

static void	st_freeall(char **words, int nb_words)
{
	int	j;

	j = 0;
	while (j < nb_words)
	{
		free(words[j]);
		j++;
	}
	free(words);
}
