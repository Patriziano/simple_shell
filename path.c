#include "shell.h"
/**
 * path_handler- finds the valid path to a command.
 * @argv: command's path to find.
 * Return: valid path or NULL if path not found.
 */
char *path_handler(char **argv)
{
	char *path = NULL, *path_cpy = NULL;
	char *token = NULL, *cmd = NULL;
	int arg_len = my_strlen(argv[0]);
	struct stat st;

	path = _getenv("PATH");
	path_cpy = my_strdup(path);
	token = _strtok(path_cpy, ":");
	while (token)
	{
		cmd = malloc(sizeof(char) * (my_strlen(token) + arg_len + 2));
		if (!cmd)
		{
			free(path_cpy);
			return (NULL);
		}
		my_strcpy(cmd, token);
		my_strcat(cmd, "/");
		my_strcat(cmd, argv[0]);
		my_strcat(cmd, "\0");

		if (stat(cmd, &st) == 0)
		{
			free(path_cpy);
			return (cmd);
		}
		free(cmd);
		token = _strtok(NULL, ":");
	}
	if (stat(argv[0], &st) == 0)
	{
		free(path_cpy);
		return (argv[0]);
	}
	free(path_cpy);
	return (NULL);
}
