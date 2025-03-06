/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:44:18 by dahmane           #+#    #+#             */
/*   Updated: 2024/11/21 15:10:58 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void    ft_print(char **strs)
{
        int     i;
        int     j;

        i = 0;
        j = 0;
        while (strs[i] != NULL)
        {
                while (strs[i][j])
                {
                        write (1, &strs[i][j], 1);
                        j++;
                }
                if (strs[i][j] == '\0')
                        write (1, "\\", 1);
                write (1, "\n", 1);
                i++;
                j = 0;
        }
        if (strs[i] == NULL)
                write (1, "null", 4);
}*/

static int	count_word(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				count++;
			i++;
		}
	}
	return (count);
}

static char	*allocate_word(const char *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	add_words(char **strs, char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			strs[i] = allocate_word(s, c);
			if (!strs[i])
			{
				while (i > 0)
					free(strs[--i]);
				free(strs);
				return (0);
			}
			while (*s != c && *s)
				s++;
			i++;
		}
	}
	strs[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (NULL);
	strs = malloc((count_word (s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	if (!add_words(strs, s, c))
		return (NULL);
	return (strs);
}
/*
int	main(void)
{
	//int	i;
	//char	**strs;
	const char	*s = "  bonjour je suis un chat ";
	char	c = ' ';
	ft_split(s, c);
}*/
