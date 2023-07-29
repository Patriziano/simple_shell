#include "shell.h"

/**
 * construct_command_path - concatenates the token with the command name.
 * @token: the splitted strings
 * @command_name: name of the command.
 * Return: the command path or NULL if memory allocation fails.
 */
char *construct_command_path(const char *token, const char *command_name)
{
	int token_len = my_strlen(token);
	int command_name_len = my_strlen(command_name);
	char *cmd_path = NULL;

	cmd_path = malloc(sizeof(char) * (token_len + command_name_len + 2));

	if (cmd_path)
	{
		my_strcpy(cmd_path, token);
		my_strcat(cmd_path, "/");
		my_strcat(cmd_path, command_name);
	}

	return (cmd_path);
}

/**
 * search_command_in_path - searches for the command in the given path.
 * @path: the path to search for
 * @command_name: The name of the command
 * Return: the valid command path or NULL if not found.
 */
char *search_command_in_path(const char *path, const char *command_name)
{
	char *token = NULL;
	char *command_path = NULL;
	char *path_cp = my_strdup(path);
	struct stat st;

	if (!path_cp)
	return (NULL);

	token = _strtok(path_cp, ":");
	while (token)
	{
		command_path = construct_command_path(token, command_name);
		if (!command_path)
		{
			free(path_cp);
			return (NULL);
		}

		if (stat(command_path, &st) == 0)
		{
			free(path_cp);
			return (command_path);
		}

		free(command_path);
		token = _strtok(NULL, ":");
	}

	free(path_cp);
	return (NULL);
}

/**
 * path_handler - Handles PATH environment and searches for the command.
 * @argv: Parsed arguments
 * Return: the valid command path or NULL if not found.
 */
char *path_handler(char **argv)
{
	char *path = NULL;
	char *result = NULL;
	struct stat st;
	char *command_path = NULL;

	path = _getenv("PATH");
	if (!path)
	return (NULL);

	result = my_strdup(argv[0]);
	if (!result)
	return (NULL);

	command_path = search_command_in_path(path, argv[0]);
	if (command_path)
	{
		free(result);
		return (command_path);
	}

	if (stat(argv[0], &st) == 0)
	{
		free(result);
		return (my_strdup(argv[0]));
	}

	free(result);
	return (NULL);
}
