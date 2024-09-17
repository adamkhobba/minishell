/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:21:46 by oouaadic          #+#    #+#             */
/*   Updated: 2024/09/07 17:58:49 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "parsing.h"

bool	is_in_env(char *key)
{
	int		i;
	int		len;

	i = 0;
	len = strlen(key);
	while (g_data.environ && g_data.environ[i])
	{
		if (strncmp(g_data.environ[i], key, len) == 0
			&& (g_data.environ[i][len] == '='
			|| g_data.environ[i][len] == '\0'))
			return (true);
		i++;
	}
	return (false);
}

char	*ft_getenv(char *name)
{
	int		i;
	int		len;

	i = -1;
	name = ft_strjoin(name, "=");
	len = strlen(name);
	while (g_data.environ && g_data.environ[++i])
		if (strncmp(g_data.environ[i], name, strlen(name)) == 0)
			return (free(name), g_data.environ[i] + len);
	free(name);
	return (NULL);
}

char	**addtoenv(char **env, char *key, char *value)
{
	int		i;
	char	**new_env;

	i = 0;
	while (env && env[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return (NULL);
	i = 0;
	while (env && env[i])
	{
		new_env[i] = env[i];
		i++;
	}
	if (value)
		key = ft_strjoin(key, "=");
	else
		key = ft_strdup(key);
	new_env[i] = ft_strjoin(key, value);
	free(key);
	new_env[i + 1] = NULL;
	free(env);
	return (new_env);
}

void	update_pwd(char **env)
{
	char	*pwd;

	pwd = ft_getenv("PWD");
	if (!pwd)
		pwd = "";
	if (is_in_env("OLDPWD"))
		update_env(env, "OLDPWD", pwd);
	else
		g_data.environ = addtoenv(g_data.environ, "OLDPWD", pwd);
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return ;
	if (is_in_env("PWD"))
		update_env(env, "PWD", pwd);
	else
		g_data.environ = addtoenv(g_data.environ, "PWD", pwd);
	free(pwd);
}

void	update_env(char **env, char *key, char *value)
{
	int		i;
	int		len;

	if (!value)
		return ;
	i = 0;
	len = strlen(key);
	while (env[i])
	{
		if (strncmp(env[i], key, len) == 0 && (env[i][len] == '='
			|| env[i][len] == '\0'))
		{
			key = ft_strjoin(key, "=");
			free(env[i]);
			env[i] = ft_strjoin(key, value);
			free(key);
			break ;
		}
		i++;
	}
}
