/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmoldo <marmoldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:50:17 by marmoldo          #+#    #+#             */
/*   Updated: 2025/11/17 17:30:17 by marmoldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*p1 = s1;
	const unsigned char	*p2 = s2;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (p1[i] != p2[i])
		{
			return (p1[i] - p2[i]);
		}
		i++;
	}
	return (0);
}

// int main()
// {
// 	char str1[15] = "asdfsd";
//    char str2[15] = "dff";
//    int ret;

//    ret = ft_memcmp(str1, str2, 5);

//    if(ret > 0) {
//       printf("str2 is less than str1");
//    } 
//    else if(ret < 0) {
//       printf("str1 is less than str2");
//    } 
//    else {
//       printf("str1 is equal to str2");
//    }
//    return(0);
// }