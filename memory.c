#include "shell.h"

/**
 * bfree - Frees pointer and NULLs the address
 * @ptr: address of the pointer to free
 * Return: if freed 1, 0 otherwise.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
