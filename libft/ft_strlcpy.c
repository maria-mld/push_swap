/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoldo <marmoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:24:02 by marmoldo          #+#    #+#             */
/*   Updated: 2025/11/18 15:36:26 by marmoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (src[j] != '\0')
	{
		j++;
	}
	if (size > 0)
	{
		while ((i < size - 1) && (src[i] != '\0'))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (j);
}

// int main()
// {
// 	char src[] = "hello aaaaadk;lka;lsd;a";
// 	char dest[10];

// 	printf("%d\n", ft_strlcpy(dest, src, 10));
// 	printf("%s", dest);
// }
