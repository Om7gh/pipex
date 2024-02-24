/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:16:33 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/24 13:20:15 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mandatory/pipex.h"

char *ft_strjoin(char *s1, char *s2)
{
    char *new;
    int i;
    int j;

    new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!new)
        return (NULL);
    i = 0;
    j = 0;
    while (s1[i])
    {
        new[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        new[i + j] = s2[j];
        j++;
    }
    new[i + j] = '\0';
    return (new);
}