#include "hsh.h"

/**
 * help_alias - prints help info for 'alias' built-in
 * @info: struct with flags
 * Return: void
 */
void help_alias(info_t *info)
{
	if (info->help && _strcmp(info->help, "s") == 0)
	{
		printf("alias: alias [-p] [name[=value] ... ]\n");
		info->help = NULL;
		return;
	}
	printf("alias: alias [-p] [name[=value] ... ]\n");
	printf("    Define or display aliases.\n\n");

	printf("    Without arguments, `alias' prints the list of aliases in the ");
	printf("reusable\n    form `alias NAME=VALUE' on standard output.\n\n");

	printf("    Otherwise, an alias is defined for each NAME whose VALUE is ");
	printf("given.\n");
	printf("    A trailing space in VALUE causes the next word to be checked ");
	printf("for\n    alias substitution when the alias is expanded.\n\n");

	printf("    Options:\n"
	"      -p\tPrint all defined aliases in a reusable format\n\n");

	printf("    Exit Status:\n"
	"    alias returns true unless a NAME is supplied for which no alias ");
	printf("has been\n    defined.\n");
}

/**
 * help_echo - prints help info for 'echo' built-in
 * @info: struct with flags
 * Return: void
 */
void help_echo(info_t *info)
{
	if (info->help && _strcmp(info->help, "s") == 0)
	{
		printf("echo: echo [-neE] [arg ...]\n");
		info->help = NULL;
		return;
	}
	printf("echo: echo [-neE] [arg ...]\n"
	"    Write arguments to the standard output.\n\n");
	printf("    Display the ARGs, separated by a single space character and ");
	printf("followed by a\n    newline, on the standard output.\n\n");
	printf("    Options:\n"
	"      -n\tdo not append a newline\n"
	"      -e\tenable interpretation of the following backslash escapes\n"
	"      -E\texplicitly suppress interpretation of backslash escapes\n\n");
	printf("    `echo' interprets the following backslash-escaped characters:\n"
	"      \\a\talert (bell)\n"
	"      \\b	backspace\n"
	"      \\c	suppress further output\n"
	"      \\e	escape character\n"
	"      \\E	escape character\n"
	"      \\f	form feed\n"
	"      \\n	new line\n"
	"      \\r	carriage return\n"
	"      \\t	horizontal tab\n"
	"      \\v	vertical tab\n"
	"      \\tbackslash\n"
	"      \\0nnn\tthe character whose ASCII code is NNN (octal).  ");
	printf("NNN can be\n        0 to 3 octal digits\n"
	"      \\xHH\tthe eight-bit character whose value is HH (hexadecimal).  HH\n"
	"        can be one or two hex digits\n\n");
	printf("    Exit Status:\n");
	printf("    Returns success unless a write error occurs.\n");
}

/**
 * help_pwd - prints help info for 'pwd' built-in
 * @info: struct with flags
 * Return: void
 */
void help_pwd(info_t *info)
{
	if (info->help && _strcmp(info->help, "s") == 0)
	{
		printf("pwd: pwd [-LP]\n");
		info->help = NULL;
		return;
	}
	printf("pwd: pwd [-LP]\n"
	"    Print the name of the current working directory.\n\n");

	printf("    Options:\n"
	"      -L	print the value of $PWD if it names the current working\n"
	"        directory\n"
	"      -P	print the physical directory, without any symbolic links\n\n");

	printf("    By default, `pwd' behaves as if `-L' were specified.\n\n");

	printf("    Exit Status:\n"
	"    Returns 0 unless an invalid option is given or the current directory\n"
	"    cannot be read.\n");
}
