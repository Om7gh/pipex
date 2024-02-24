/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:14:52 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/24 13:16:26 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mandatory/pipex.h"

char *ft_strdup(char *str)
{
    char *new;
    int i;

    new = malloc(ft_strlen(str) + 1);
    if (!new)
        return (NULL);
    i = 0;
    while (*(str + i))
    {
        new[i] = *(str + i);
        i++;
    }
    new[i] = '\0';
    return (new);
}