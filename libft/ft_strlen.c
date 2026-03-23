/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoldo <marmoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:41:12 by marmoldo          #+#    #+#             */
/*   Updated: 2025/11/18 19:28:51 by marmoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (*s++)
	{
		count++;
	}
	return (count);
}

// int main()
// {
// 	char *str = "HELLO";
// 	printf("%d", ft_strlen(str));
// }