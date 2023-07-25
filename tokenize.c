#include "shell.h"
void rm_spaces(char *p);
/**
 * tokenize- tokenize the command entered by user.
 * @buffer: buffer to tokenize.
 * @delim: delimeter.
 * Return: array of tokenized commands.
 */
char **tokenize(char *buffer, char *delim)
{
	int num_toks = 0, i = 0;
	char *token = NULL, *buf_cpy = NULL, **args = NULL;

	while (*buffer == ' ')	/* remove preceding spaces */
		buffer++;

	buf_cpy = my_strdup(buffer);
	if (!buf_cpy)
	{
		perror("strdup");
		free(buffer);
		return (NULL);
	}
	rm_spaces(buf_cpy);
	token = _strtok(buf_cpy, delim);
	while (token != NULL)	/* get number of tokens*/
	{
		num_toks++;
		token = _strtok(NULL, delim);
	}
	args = malloc(sizeof(char *) * (num_toks + 1));
	if (!args)
	{
		perror("Error: malloc");
		free(buf_cpy);
		free(buffer);
		return (NULL);
	}
	token = _strtok(buffer, delim);
	for (; i < num_toks && token != NULL; i++)
	{
		args[i] = my_strdup(token);
		token = _strtok(NULL, delim);
	}
	args[i] = NULL;
	free(buf_cpy);
	return (args);
}

/**
 * rm_spaces- removes trailing spaces from buffer.
 * @p: buffer to remove space from
 * Return: nothing
 */
void rm_spaces(char *p)
{
	char *e = NULL;

	e = p;	/* remove trailing spaces */
	while (*e != '\0')
		e++;
	if (*e == ' ')
	{
		while (*e == ' ')
			e--;
		*(e + 1) = '\0';
	}
}
