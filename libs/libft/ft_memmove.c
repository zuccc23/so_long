/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:54:40 by dahmane           #+#    #+#             */
/*   Updated: 2024/11/18 12:30:33 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	i = 0;
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	if (!dest && !src)
		return (dest);
	if (dest > src)
	{
		while (n-- > 0)
			temp_dest[n] = temp_src[n];
	}
	else
	{
		while (i < n)
		{
			temp_dest[i] = temp_src[i];
			i++;
		}
	}
	return (dest);
}

/*int	main(void)
{
	char dest[] = "abcdefghi";
	char destt[] = "abcdefghi";
	char *str = dest + 2;
	char *strr = destt + 2;
	ft_memmove(dest, str, 0);
	memmove(destt, strr, 0);
	printf("%s\n", dest);
	printf("%s\n", destt);
	return (0);
}*/
