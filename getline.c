#include "shell.h"
/**
 * _getline- reads an entire line from stream.
 * @lineptr: address of buffer containing text.
 * @n: size of buffer
 *@stream: stream of file
 * Return: Number of bytes read or -1 on error
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char *buf;
	size_t index = 0, bytes_read = 0, buf_size = BUFSIZ;
	char *new_buf = NULL, ch;

	if (!lineptr || !n || !stream)
		return (-1);
	buf = malloc(buf_size);
	while (1)
	{
		if (bytes_read >= (buf_size - 1))
		{
			buf_size += BUFSIZ;
			new_buf = _realloc(buf, buf_size);
			if (!new_buf)
			{
				free(buf);
				buf = NULL;
				return (-1);
			}
			free(buf);
			buf = new_buf;
		}
		if ((read(fileno(stream), &ch, 1)) <= 0)
		{
			free(buf);
			buf = NULL;
			if (bytes_read > 0)
				return (bytes_read);
			return (-1);
		}
		buf[index] = ch;
		index++, bytes_read++;
		if (buf[index - 1] == '\n')
			break;
	}
	buf[index] = '\0';
	*lineptr = buf;
	return (bytes_read);
}
