#include "shell.h"
/**
 * _strtok- breaks a string into a sequence of zero or more nonempty tokens.
 * @str: the string to be parsed.
 * @delim: set of bytes that delimit the tokens in the parsed string.
 * Return: a pointer to a null-terminated string containing the next token.
 */

char *_strtok(char *str, char *delim)
{
	char *token = NULL, *delimpos = NULL;
	static char *nxt_token;

	if (str != NULL)
		nxt_token = str;
	if (!nxt_token || *nxt_token == '\0')
		return (NULL);
	token = nxt_token;
	delimpos = _strstr(nxt_token, delim);
	if (delimpos != NULL)
	{
		*delimpos = '\0';
		nxt_token = delimpos + my_strlen(delim);
	}
	else
	{
		nxt_token += my_strlen(nxt_token);
	}
	return (token);
}

/**
 * _strstr- searches for string needle from haystack.
 * @haystack: string to search from.
 * @needle: string to search for.
 *Return: pointer to the begining of the found string or NULL.
 */
char *_strstr(char *haystack, char *needle)
{
	char *n = needle;
	char *h = haystack;
	int i = 0, j = 0;

	if (*n == '\0')
		return (h);
	while (h[i] != '\0')
	{
		j = 0;
		while (n[j] != '\0')
		{
			if (h[i + j] != n[j])
				break;
			j++;
		}
		if (n[j] == '\0')
			return ((char *)(h + i));
		i++;
	}
	return (NULL);
}
