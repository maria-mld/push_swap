/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoldo <marmoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:24:03 by marmoldo          #+#    #+#             */
/*   Updated: 2025/11/25 18:29:27 by marmoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
	return ;
}

// int main()
// {
// 	char arr1[] = "Hello world";
// 	int arr2[] = {1, 2, 3, 4, 5};

// 	ft_bzero(arr1, 5);
// 	ft_bzero(arr2, sizeof(int) * 3);
// 	//printf("%d\n", arr1);
// 	int i = 0;
// 	while (i < 5){
// 		printf("%d ", arr2[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	i = 0;
// 	while (i < 11){
// 		printf("%d ", arr1[i]);
// 		i++;
// 	}
// }