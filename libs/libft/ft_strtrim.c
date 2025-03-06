/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:36:22 by dahmane           #+#    #+#             */
/*   Updated: 2024/11/20 13:32:30 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static void	assign(char const *s1, char *s2, int i, int len)
{
	int	o;

	o = 0;
	while (i <= len)
	{
		s2[o] = s1[i];
		i++;
		o++;
	}
	s2[o] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		i;
	int		len;
	int		count;

	count = 0;
	len = ft_strlen(s1) - 1;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (isset(s1[i], set) == 1)
		i++;
	if (isset(s1[i], set) == 0 && s1[i])
		i--;
	while (isset(s1[len], set) == 1 && s1[len])
		len--;
	count = len - i;
	if (count <= 0)
		return (ft_strdup(""));
	s2 = malloc (count * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	assign(s1, s2, i + 1, len);
	return (s2);
}

/*int	main(void)
{
	char	s1[] = "lorem ipsum dolor sit amet";
	char	set[] = "tel";

	//count_size(s1, set);

	printf("%s\n", ft_strtrim(s1, set));
}*/
