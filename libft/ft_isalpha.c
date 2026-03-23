/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoldo <marmoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:05:34 by marmoldo          #+#    #+#             */
/*   Updated: 2025/11/17 17:49:36 by marmoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

// int	main()
// {
// 	printf("%d\n", ft_isalpha(65));
// 	printf("%d\n", ft_isalpha(122));
// 	printf("%d\n", ft_isalpha(77));
// 	printf("%d\n", ft_isalpha(4));
// }