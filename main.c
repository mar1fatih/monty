#include "monty.h"
stack_t *head = NULL;
/**
 * main - main function
 * @ac: ac
 * @av: av
 * Return: 0
*/
int main(int ac, char *av[])
{
	if (ac < 2 || ac > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_exec(av[1]);
	freen();
	return (0);
}
