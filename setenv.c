#include "shell.h"
/**
 * _setenv- updates or create an environment variable.
 * @args: arguments
 * Return: 1 for loop to continue.
 */
int _setenv(char **args)
{
	char *name = args[1];
	int i = 0;
	char *value = args[2];
	size_t len_name = 0, env_len = 0, val_len = 0;
	char *new_env = NULL;

	if (!name || !value)
	{
		perror("setenv");
		return (1);
	}
	len_name = my_strlen(name);        /* create new_env */
	val_len = my_strlen(value);
	env_len = len_name + val_len + 2;
	new_env = malloc(env_len * sizeof(char *));
	if (!new_env)
	{
		perror("setenv");
		return (1);
	}
	my_strcpy(new_env, name);
	my_strcat(new_env, "=");
	my_strcat(new_env, value);
	my_strcat(new_env, "\0");
	while (environ[i] != NULL)
	{
		if (my_strncmp(environ[i], name, len_name) == 0
&& environ[i][len_name] == '=')
		{
			free(environ[i]);
			environ[i] = new_env;
			return (1);
		}
		i++;
	}
	environ[i] = new_env;
	environ[i + 1] = '\0';
	return (1);
}
