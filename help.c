#include "hsh.h"

/**
 * help_info - returns information about args
 * @info: struct with arguments
 * Return: 0 on success
 */
int help_info(info_t *info)
{
	char **arg;

	arg = info->argv;

	if (arg[1] == NULL)
		return (1);

	if (_strcmp(arg[1], "cd") == 0)
		help_cd();
	else if (_strcmp(arg[1], "exit") == 0)
		help_exit();
	else if (_strcmp(arg[1], "help") == 0)
		help_help();
	else if (_strcmp(arg[1], "history") == 0)
		help_history();
	else
	{
		printf("-bash: help: no help topics match `%s'.", arg[1]);
		printf("  Try `help help' or `man -k %s' or `info %s'.\n", arg[1], arg[1]);
		return (1);
	}
	return (0);
}

/**
 * help_cd - prints help info for cd built-in
 * Return: void
 */
void help_cd(void)
{
	printf("cd: cd [-L|[-P [-e]] [-@]] [dir]\n");
	printf("    Change the shell working directory.\n\n");

	printf("    Change the current directory to DIR.  ");
	printf("The default DIR is the value of the\n");
	printf("    HOME shell variable.\n\n");

	printf("    The variable CDPATH defines the search path for the directory ");
	printf("containing\n    DIR.  Alternative directory names in CDPATH are ");
	printf("separated by a colon (:).\n");
	printf("    A null directory name is the same as the current directory.");
	printf("  If DIR begins\n"
	"    with a slash (/), then CDPATH is not used.\n\n");

	printf("    If the directory is not found, and the shell option");
	printf("`cdable_vars' is set,\n    the word is assumed to be  a variable ");
	printf("name.  ");
	printf("If that variable has a value,\n    its value is used for DIR.\n\n");

	printf("    Options:\n"
	"        -L\tforce symbolic links to be followed: resolve symbolic links in\n"
	"        DIR after processing instances of `..'\n");
	printf("        -P\tuse the physical directory structure without following");
	printf(" symbolic\n        links: resolve symbolic links in DIR before ");
	printf("processing instances\n        of `..'\n");
	printf("        -e\tif the -P option is supplied, and the current working ");
	printf("directory\n        cannot be determined successfully, exit with a ");
	printf("non-zero status\n");
	printf("        -@  on systems that support it, present a file with ");
	printf("extended attributes\n"
	"            as a directory containing the file attributes\n\n");

	printf("    The default is to follow symbolic links, as if `-L' were ");
	printf("specified.\n");
	printf("    `..' is processed by removing the immediately previous pathname");
	printf(" component\n    back to a slash or the beginning of DIR.\n\n");

	printf("    Exit Status:\n");
	printf("    Returns 0 if the directory is changed, and if $PWD is set ");
	printf("successfully when\n    -P is used; non-zero otherwise.\n");
}

/**
 * help_exit - prints help for exit built-in
 * Return: void
 */
void help_exit(void)
{
		printf("exit: exit [n]\n    Exit the shell.\n\n");
		printf("\n    Exits the shell with a status of N. ");
		printf("If N is omitted, the exit status\n");
		printf("    that of the last arg executed.\n");
}

/**
 * help_help - prints help for help
 * Return: void
 */
void help_help(void)
{
	printf("help: help [-dms] [pattern ...]\n");
	printf("    Display information about builtin commands.\n\n");
	printf("    Displays brief summaries of builtin commands.  If PATTERN is\n");
	printf("    specified, gives detailed help on all commands matching ");
	printf("PATTERN,\n");
	printf("    otherwise the list of help topics is printed.\n\n");

	printf("    Options:\n");
	printf("      -d\toutput short description for each topic\n");
	printf("      -m\tdisplay usage in pseudo-manpage format\n");
	printf("      -s\toutput only a short usage synopsis for each topic ");
	printf("matching\n");
	printf("        PATTERN\n\n");

	printf("    Arguments:\n");
	printf("      PATTERN\tPattern specifiying a help topic\n\n");

	printf("    Exit Status:\n");
	printf("    Returns success unless PATTERN is not found ");
	printf("or an invalid option is given.\n");
}

/**
 * help_history - displays help info about history built-in
 * Return: void
 */
void help_history(void)
{
	printf("history: history [-c] [-d offset] [n] or history -anrw [filename] ");
	printf("or history -ps arg [arg...]\n");
	printf("    Display or manipulate the history list.\n\n");

	printf("    Display the history list with line numbers, prefixing each ");
	printf("modified\n"
	"    entry with a `*'.  An argument of N lists only the last N entries.\n\n");

	printf("    Options:\n"
		"      -c\tclear the history list by deleting all of the entries\n"
		"      -d offset\tdelete the history entry at offset OFFSET.\n\n");
	printf("      -a\tappend history lines from this session to the history "
	printf("file\n"
		"      -n\tread all history lines not already read from the history file\n"
		"      -r\tread the history file and append the contents to the history\n"
		"        list\n"
		"      -w\twrite the current history to the history file\n"
		"        and append them to the history list\n\n");
	printf("      -p\tperform history expansion on each ARG and display the ");
	printf("result\n        without storing it in the history list\n"
	"      -s\tappend the ARGs to the history list as a single entry\n\n");

	printf("    If FILENAME is given, it is used as the history file.  ");
	printf("Otherwise,\n"
	"    if $HISTFILE has a value, that is used, else ~/.bash_history.\n\n");

	printf("    If the $HISTTIMEFORMAT variable is set and not null, its ");
	printf("value is used\n"
	"    as a format string for strftime(3) to print the time stamp associated\n"
	"    with each displayed history entry. ");
	printf("No time stamps are printed otherwise.\n\n");

	printf("    Exit Status:\n    Returns success unless an invalid option is ");
	printf("given or an error occurs.\n");
}
