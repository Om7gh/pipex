/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:07:57 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/24 13:39:47 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void finish(char *str, int fd)
{
    ft_putchar(str, fd);
    exit(1);
}

void finish2(char *str, int fd)
{
    ft_putchar(str, fd);
}

void close_fd(t_pipex *pipex)
{
    close(pipex->fd[0]);
    close(pipex->fd[1]);
}