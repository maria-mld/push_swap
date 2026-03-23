/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoldo <marmoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:20:48 by marmoldo          #+#    #+#             */
/*   Updated: 2025/11/20 17:17:47 by marmoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	s_len;

	s_len = ft_strlen(s);
	while (s_len >= 0)
	{
		if (s[s_len] == (char)c)
		{
			return ((char *)&s[s_len]);
		}
		s_len--;
	}
	return (NULL);
}

// int main()
// {
// 	char str[] = "Hello";

// 	printf("%s", ft_strrchr(str, 'l'));
// }