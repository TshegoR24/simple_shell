#include "shell.h"

/**
 * _myhistory - Displays history list by one command by line, preceded
 *              with line numbers starting at 0
 * @info: Structure with potential arguments to maintain
 *        constant function prototype.
 *  Return: 0 Always
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - Sets alias to string
 * @info: Parameter struct
 * @str: The string alias
 * Return: Success always on 0, error on 1
 */
int unset_alias(info_t *info, char *str)
{
	char *s, c;
	int ret;

	s = _strchr(str, '=');
	if (!s)
		return (1);
	c = *s;
	*s = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*s = c;
	return (ret);
}

/**
 * set_alias - Sets alias to string
 * @info: parameter struct
 * @str: the string alias
 * Return: Success always on 0, error on 1
 */
int set_alias(info_t *info, char *str)
{
	char *s;

	s = _strchr(str, '=');
	if (!s)
		return (1);
	if (!*++s)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - Prints an alias string
 * @node: the alias node
 * Return: Success always on 0, error on 1
 */
int print_alias(list_t *node)
{
	char *s = NULL, *a = NULL;

	if (node)
	{
		s = _strchr(node->str, '=');
		for (a = node->str; a <= s; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(s + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - Mimics alias builtin (man alias)
 * @info: Structure with potential arguments to maintain
 *          constant function prototype.
 *  Return: 0 Always
 */
int _myalias(info_t *info)
{
	int a = 0;
	char *s = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (a = 1; info->argv[a]; a++)
	{
		s = _strchr(info->argv[a], '=');
		if (s)
			set_alias(info, info->argv[a]);
		else
			print_alias(node_starts_with(info->alias, info->argv[a], '='));
	}

	return (0);
}
