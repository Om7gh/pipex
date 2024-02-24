/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:21:02 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/24 14:30:27 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mandatory/pipex.h"

int count_word(char *str , char c)
{
    char last;
    int i;
    int count;

    last = c;
    i = 0;
    count = 0;
    while (str[i])
    {
        if (last == c && str[i] != c)
            count++;
        last = str[i];
        i++;
    }
    return (count);
}

int world_len(char *str, char c)
{
    int i;

    i = 0;
    while (str[i] && str[i] != c)
        i++;
    return (i);    
}


char *ft_strcpy(char *s1, char *s2, char c)
{
    int i;

    i = 0;
    while (s1[i] && s1[i] != c)
    {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';
    return (s2);
}

char **split(char *s, char c)
{
    char **new;
    int j;
    int i;

    new = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
    if (!new)
        return (NULL);
    i = 0;
    dprintf(2, "%s\n\n", s);
    while (s[i])
    {
        while (s[i] && s[i] == c)
            i++;
        if (s[i])
        {
            new[j] = malloc(sizeof(char) * (world_len(s, c) + 1));
            new[j] = ft_strcpy(s + i, new[j], c);
            dprintf(2, "%s", new[j]);
            j++;
        }
        while (s[i] && s[i] != c)
            i++;
    }
    new[j] = NULL;
    return (new);
}
