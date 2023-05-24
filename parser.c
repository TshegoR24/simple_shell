#include "shell.h"

/**
 * is_cmd - Determines if file is executable command
 * @info: Info struct
 * @path: Path to the file
 * Return: true if 1, otherwise 0
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - Duplicates characters
 * @pathstr: PATH string
 * @start: Starting index
 * @stop: Stopping index
 * Return: Pointer to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int a = 0, l = 0;

	for (l = 0, a = start; a < stop; a++)
		if (pathstr[a] != ':')
			buf[l++] = pathstr[a];
	buf[l] = 0;
	return (buf);
}

/**
 * find_path - Finds cmd in the PATH string
 * @info: Info struct
 * @pathstr: PATH string
 * @cmd: cmd to find
 * Return: Full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int a = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[a] || pathstr[a] == ':')
		{
			path = dup_chars(pathstr, curr_pos, a);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[a])
				break;
			curr_pos = a;
		}
		a++;
	}
	return (NULL);
}
