/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:10:50 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/24 14:07:38 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_pipex
{
    int infile;
    int outfile;
    int fd[2];
    char *cmd;
} t_pipex;

/* FUNCTIONS HELPER */
int ft_strlen(char *s);
void ft_putchar(char c, int fd);
void ft_putstr_fd(char *s, int fd);
char *ft_strdup(char *str);
char *ft_strjoin(char *s1, char *s2);
int ft_strncmp(char *str, char *str2, int len);
char	*ft_strtrim(char *s1, char *set);
char **split(char *s, char c);

/*  UTILS FUNCTION  */
void finish(char *str, int fd);
void finish2(char *str, int fd);
void close_fd(t_pipex *pipex);

/*   PIPEX */
void execute_commande(char *cmd, char **env);

#endif
