#include "monty.h"
/**
 * addtostack - ddtostack
 * @new_node: new node.
 * @ln: ln
*/
void addtostack(stack_t **new_node, unsigned int ln)
{
	stack_t *current;

	(void)ln;
	if (!new_node || !(*new_node))
	{
		exit(EXIT_FAILURE);
	}
	if (!head)
	{
		head = *new_node;
		return;
	}
	current = head;
	head = *new_node;
	head->next = current;
	current->prev = head;
}


/**
 * print - print
 * @_LIFO: _LIFO
 * @line_number: ln
*/
void print(stack_t **_LIFO, __attribute__((unused))unsigned int line_number)
{
	stack_t *current;

	if (!_LIFO)
	{
		exit(EXIT_FAILURE);
	}
	current = *_LIFO;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pop_t - pop_t
 * @_LIFO: _LIFO
 * @line_number: ln
*/
void pop_t(stack_t **_LIFO, unsigned int line_number)
{
	stack_t *current;

	if (!_LIFO || !(*_LIFO))
	{
		error2(7, line_number);
	}
	current = *_LIFO;
	*_LIFO = current->next;
	if (*_LIFO)
	{
		(*_LIFO)->prev = NULL;
	}
	free(current);
}

/**
 * top - check the code
 * @_LIFO: _LIFO
 * @ln: ln
*/
void top(stack_t **_LIFO, unsigned int ln)
{
	if (!_LIFO || !(*_LIFO))
		error2(6, ln);
	printf("%d\n", (*_LIFO)->n);
}
/**
 * addtoqueue - check the code
 * @new_n: new
 * @ln: ln
*/
void addtoqueue(stack_t **new_n, unsigned int ln)
{
	stack_t *current;

	(void)ln;
	if (!new_n || !(*new_n))
	{
		exit(EXIT_FAILURE);
	}
	if (!head)
	{
		head = *new_n;
		return;
	}
	current = head;
	while (current->next)
	{
		current = current->next;
	}
	current->next = *new_n;
	(*new_n)->prev = current;

}
