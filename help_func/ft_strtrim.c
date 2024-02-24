/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:36:10 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/24 14:07:22 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mandatory/pipex.h"

static int	find_and_trim(char c, char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static void	*ft_memcpy(void *dst, void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;

	if (dst == src)
		return (dst);
	if (!dst && !src)
		return (dst);
	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (n--)
		*destination++ = *source++;
	return (dst);
}
static size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < size)
		ft_memcpy(dst, src, src_len + 1);
	else if (size > 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (src_len);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*arr;
	size_t	start;
	size_t	end;
	size_t	current_index;

	if (!s1)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && find_and_trim(s1[start], (char *)set) == 1)
		start++;
	while (end > start && find_and_trim(s1[end], (char *)set) == 1)
		end--;
	current_index = end - start + 1;
	arr = (char *)malloc(current_index + 1);
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, s1 + start, current_index + 1);
	return (arr);
}