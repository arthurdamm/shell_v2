#include "hsh.h"

/**
 * parse_redirect - parses redirect directives from input
 * @info: parameter struct
 * Return: void
 */
void parse_redirect(info_t *info)
{
	char *p = _strchrlast(info->arg, '>');
	int fd;

	if (!p) /* no redirect */
		return;

	fd = open_redirect(info, p + 1);
	if (fd == -1)
		return;
	info->right_redirect_to_fd = fd;
	if (p > info->arg) /* if not start of string */
	{
		/* check if previous char is digit */
		if (*(p - 1) >= '0' && *(p - 1) <= '9')
		{
			p--;
			info->right_redirect_from_fd = *p - '0';
		}
	}
	*p = 0; /* insert null char to cut string b4 > */
}

/**
 * open_redirect - opens a fd for redirect writing
 * @info: parameter struct
 * @file: name of file
 * Return: integer fd or -1
 */
int open_redirect(info_t *info, char *file)
{
	int fd;

	while (*file == ' ' || *file == '\n')
		file++;
	if (!*file)
	{
		/* TODO: print error */
		print_error(info, "Syntax error: newline unexpected\n");
		return (-1);
	}
	fd = open(file, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd == -1)
	{
		char buf[256];

		buf[0] = 0;
		sprintf(buf, "Cannot create %s: Permission denied\n", file);
		print_error(info, buf);
	}
	return (fd);
}
