/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:40:23 by dahmane           #+#    #+#             */
/*   Updated: 2024/11/19 11:24:08 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	ft_strupcase(unsigned int i, char c)
{
	i = 0;
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
	return (c);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s2;

	i = 0;
	s2 = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	while (s[i])
	{
		s2[i] = f(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/*int	main(void)
{
	 char	s[] = "hello";

	 printf("%s\n", ft_strmapi(s, &ft_strupcase));
}*/
