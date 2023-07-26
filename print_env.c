#include "shell.h"

/**
 * printenv - prints all environment variables
 * @args: arguments.
 * Return: nothing.
 */

int printenv(char **args)
{
	char **k = environ;
	int i = 0;

	(void)args;
	while (k[i])
	{
		write(STDOUT_FILENO, k[i], my_strlen(k[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (1);
}


/**
 * _exitt - exits the shell with status.
 * @args: arguments
 * Return: exit status.
 */
int _exitt(char **args)
{
	int exit_status = 0;

	if (args[1] != NULL)
		exit_status = atoi(args[1]);
	exit(exit_status);
}

/**
 * built_ins - Array of structs for builtin commands.
 *
 * Description: This array stores a list of builtin commands and their
 * corresponding functions.
 * The commands can be executed by the parent process.
 */
builtins_t built_ins[] = {
	{"cd", ch_dir},
	{"env", printenv},
	{"exit", _exitt},
	{"setenv", _setenv},
	{"unsetenv", _unsetenv},
	{NULL, NULL}
};
