#include "shell.h"

/**
 * _myenv - Prints the current environment
 * @info: Structure with potential arguments to maintain
 * constant function prototype.
 * Return: 0 Always
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - Gets value of environ variable
 * @info: Structure with potential arguments to maintain
 * @name: env var name
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *s;

	while (node)
	{
		s = starts_with(node->str, name);
		if (s && *s)
			return (s);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize new environment variable,
 *             or modify existing one
 * @info: Structure with potential arguments to maintain
 * constant function prototype.
 *  Return: 0 Always
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove environment variable
 * @info: Structure with potential arguments to maintain
 *  constant function prototype.
 *  Return: 0 Always
 */
int _myunsetenv(info_t *info)
{
	int p;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (p = 1; p <= info->argc; p++)
		_unsetenv(info, info->argv[p]);

	return (0);
}

/**
 * populate_env_list - Populates env linked list
 * @info: Structure with potential arguments to maintain
 * constant function prototype.
 * Return: 0 Always
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t p;

	for (p = 0; environ[p]; p++)
		add_node_end(&node, environ[p], 0);
	info->env = node;
	return (0);
}
