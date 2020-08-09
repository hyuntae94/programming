/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim <hyunkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 04:09:15 by hyunkim           #+#    #+#             */
/*   Updated: 2020/08/05 02:59:03 by hyunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	size_t	length;
	char	*res;

	if (s == NULL)
		return (NULL);
	index = 0;
	length = ft_strlen(s);
	res = (char*)malloc((length + 1) * sizeof(char));
	while (index < length)
	{
		res[index] = (*f)(index, s[index]);
		index++;
	}
	res[index] = '\0';
	return (res);
}
