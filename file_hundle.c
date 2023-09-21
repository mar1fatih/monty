#include "monty.h"

/**
 * file_exec - check the code
 * @name: name
*/

void file_exec(char *name)
{
	FILE *f;

	f = fopen(name, "r");
	if (!name || !f)
	{
		error(2, name);
	}
	read_f(f);
	fclose(f);
}


/**
 * read_f - check the code
 * @f: f
*/

void read_f(FILE *f)
{
	char *buff;
	int ln;
	size_t len;
	int form;

	form = 0;
	buff = NULL;
	len = 0;
	ln = 1;
	while (getline(&buff, &len, f) != -1)
	{
	form = line_exec(buff, ln, form);
	ln++;
	}
	free(buff);
}


/**
 * line_exec - check the code
 * @buff: buff
 * @ln: ln
 * @form:  form
 * Return: Returns 0 if the opcode is stack. 1 if queue.
*/

int line_exec(char *buff, int ln, int form)
{
	char *com;
	char *op;

	if (!buff)
	{
		error(4);
	}
	op = strtok(buff, "\n ");
	if (!op)
	{
		return (form);
	}
	com = strtok(NULL, "\n ");

	if (strcmp(op, "queue") == 0)
		return (1);
	if (strcmp(op, "stack") == 0)
		return (0);

	func_finder(op, com, ln, form);
	return (form);
}

/**
 * func_finder - check the code
 * @op: op
 * @com: com
 * @form: form
 * @ln: ln
*/
void func_finder(char *op, char *com, int ln, int form)
{
	int i;
	int is_ok;

	instruction_t list[] = {
		{"swap", swap_nodes},
		{"sub", sub},
		{"add", add},
		{"div", div_s},
		{"rotr", rr},
		{"push", addtostack},
		{"pint", top},
		{"pall", print},
		{"pop", pop_t},
		{"pchar", print_c},
		{"mod", mod},
		{"mul", mul},
		{"rotl", rl},
		{"pstr", str_print},
		{"nop", nothing},
		{NULL, NULL}
	};

	if (op[0] == '#')
		return;

	is_ok = 1;
	i = 0;
	while (list[i].opcode)
	{
		if (strcmp(op, list[i].opcode) == 0)
		{
			func_caller(list[i].f, op, com, ln, form);
			is_ok = 0;
		}
		i++;
	}
	if (is_ok == 1)
		error(3, ln, op);
}


/**
 * func_caller - Check the code
 * @exe: exe
 * @op: op
 * @com: com
 * @ln: ln
 * @form: Form
*/
void func_caller(func_exec exe, char *op, char *com, int ln, int form)
{
	int i;
	stack_t *nd;
	int mul = 1;

	if (strcmp(op, "push") == 0)
	{
		if (com && com[0] == '-')
		{
			com = com + 1;
			mul = -1;
		}
		if (!com)
		{
			error(5, ln);
		}
		i = 0;
		while (com[i] != '\0')
		{
			if (isdigit(com[i]) == 0)
			{
				error(5, ln);
			}
			i++;
		}
		nd = newnode(atoi(com) * mul);
		if (form == 1)
		{
			addtoqueue(&nd, ln);
		}
		if (form == 0)
		{
			exe(&nd, ln);
		}
	}
	else
		exe(&head, ln);
}
