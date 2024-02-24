/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:34:39 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/24 14:12:28 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mandatory/pipex.h"

int ft_strncmp(char *str, char *str2, int len)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while ((str[i] || str[j]) && j < len - 1)
    {
        if (str[i] != str[j])
            break;
        i++;
        j++;
    }
    return (str[i] - str2[j]);
}