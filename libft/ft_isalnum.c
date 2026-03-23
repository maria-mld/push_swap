/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoldo <marmoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:25:17 by marmoldo          #+#    #+#             */
/*   Updated: 2025/11/17 17:50:59 by marmoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)
		|| (c >= 48 && c <= 57))
		return (1);
	else
		return (0);
}

// int main()
// {
// 	printf("%d\n", ft_isalnum(56));
// 	printf("%d\n", ft_isalnum(77));
// 	printf("%d\n", ft_isalnum(123));
// 	printf("%d\n", ft_isalnum(100));
// }