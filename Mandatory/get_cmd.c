/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:39:57 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/24 14:25:50 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Mandatory/pipex.h"

static char **get_path(char **env)
{
    int i;
    char    **path;

    i = 0;
    while (*env)
    {
        if (ft_strncmp(*env, "PATH", 4) == 0)
        {
            dprintf(2,"%s\n", *env);
            path = split(*env + 5, ':');
            dprintf(2,"hna %s\n", *env + 5);
            return (path);
        }
        env++;
    }
    return (NULL);
}

static char *get_cmd(char *cmd, char **env)
{
    char **path;
    char *full_path;
    char *return_path;
    int     i;

    if (*(cmd) == '.' || *(cmd) == '/')
        return (cmd);
    full_path = ft_strjoin("/", cmd);
    path = get_path(env);
    i = 0;
    dprintf(2, "path === %s", path[0]);
    while (path[i])
    {
        return_path = ft_strjoin(path[i], full_path);
        dprintf(2, "%s", return_path);
        if (access(return_path, X_OK) == 0)
            return (return_path);
        i++;
    }
    return (NULL);
}

void execute_commande(char *cmd, char **env)
{
       char *path;
       char **av;
       puts(cmd);
       av = split(cmd, ' ');
       puts(av[0]);
       path = get_cmd(av[0], env);
       execve(path, av, env);
       perror("execve");
}

int main(int ac, char **av, char **env)
{
    execute_commande("ls -l", env);
}