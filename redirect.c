#include "hsh.h"

/**
 * parse_redirect - parses redirect directives from input
 * @info: parameter struct
 * Return: void
 */
void parse_redirect(info_t *info)
{
	char *p = _strchrlast(info->arg, '>'), *file;
	int fd;

	if (!p) /* no redirect */
		return;

	file = p + 1;
	if (p > info->arg && *(p - 1) == '>')
	{
		info->right_append = 1;
		p--;
	}
	if (p > info->arg) /* if not start of string */
	{
		/* check if previous char is digit */
		if (*(p - 1) >= '0' && *(p - 1) <= '9')
		{
			p--;
			info->right_redirect_from_fd = *p - '0';
		}
	}
	fd = open_redirect(info, file);
	if (fd == -1)
	{
		/* TODO: print message, set status, etc? */
		return;
	}
	info->right_redirect_to_fd = fd;
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
		print_error_noarg(info, "Syntax error: newline unexpected\n");
		return (-1);
	}
	fd = open(file, O_CREAT | O_RDWR |
		(info->right_append ? O_APPEND : O_TRUNC), 0644);
	if (fd == -1)
	{
		char buf[256];

		buf[0] = 0;
		sprintf(buf, "Cannot create %s: Permission denied\n", file);
		print_error_noarg(info, buf);
	}
	return (fd);
}
