/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoldo <marmoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:45:27 by marmoldo          #+#    #+#             */
/*   Updated: 2025/11/17 17:31:56 by marmoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_val;

	s_val = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s_val[i] = c;
		i++;
	}
	return (s);
}

// int main(){
// 	int i = 0;
// 	char str[] = "Hello, world";
// 	int	arr[] = {-1, -2, 3 ,4 ,5};

// 	ft_memset(arr, -1, sizeof(int) * 5);
// 	ft_memset(str, 'a', 5);
// 	printf("%s\n", str);
// 	while (i < 5)
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}
// }