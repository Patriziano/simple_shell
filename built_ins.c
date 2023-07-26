#include "shell.h"
/**
 * ch_dir- changes the current working directory
 * @args: command/path to change to
 * Return: 1 for loop to continue.
 */

int ch_dir(char **args)
{
	char *old_dir = _getenv("OLDPWD");
	char *pwd = _getenv("PWD");

	if (args[1] == NULL)
	{
		printf("HOME");
		return (1);
	}
	if (my_strcmp(args[1], "-") == 0)
	{
		if (chdir(old_dir) < 0)
			perror("chdir");
		update_dir(pwd);
		return (1);
	}
	if (chdir(args[1]) < 0)
		perror("chdir");
	update_dir(pwd);

	return (1);
}
/**
 * update_dir- updates the pwd and oldpwd
 * @pwd: pwd to update with.
 * Return: nothing.
 */
void update_dir(char *pwd)
{
	char *cwd = getcwd(NULL, 0);

	if (cwd == NULL)
	{
		perror("getcwd");
		return;
	}
	setenv("OLDPWD", pwd, 1);
	setenv("PWD", cwd, 1);
	free(cwd);
}
