#include "monty.h"

/**
 * nothing - nothing.
 * @_LIFO: _LIFO
 * @l: line number
*/
void nothing(stack_t **_LIFO, unsigned int l)
{
	(void)_LIFO;
	(void)l;
}


/**
 * swap_nodes - swap
 * @_LIFO: _LIFO
 * @l: l
*/
void swap_nodes(stack_t **_LIFO, unsigned int l)
{
	stack_t *current;

	if (!_LIFO || !(*_LIFO) || (*_LIFO)->next == NULL)
	{
		error2(8, l, "swap");
	}
	current = (*_LIFO)->next;
	(*_LIFO)->next = current->next;
	if (current->next)
	{
		current->next->prev = *_LIFO;
	}
	current->next = *_LIFO;
	(*_LIFO)->prev = current;
	current->prev = NULL;
	*_LIFO = current;
}

/**
 * add - check the code
 * @_LIFO: _LIFO
 * @l: l
*/
void add(stack_t **_LIFO, unsigned int l)
{
	int s;

	if (!_LIFO || !(*_LIFO) || (*_LIFO)->next == NULL)
		error2(8, l, "add");

	(*_LIFO) = (*_LIFO)->next;
	s = (*_LIFO)->n + (*_LIFO)->prev->n;
	(*_LIFO)->n = s;
	free((*_LIFO)->prev);
	(*_LIFO)->prev = NULL;
}


/**
 * sub - check the code
 * @_LIFO: _LIFO
 * @l: line number
*/
void sub(stack_t **_LIFO, unsigned int l)
{
	int s;

	if (!_LIFO || !(*_LIFO) || (*_LIFO)->next == NULL)
	{
		error2(8, l, "sub");
	}
	(*_LIFO) = (*_LIFO)->next;
	s = (*_LIFO)->n - (*_LIFO)->prev->n;
	(*_LIFO)->n = s;
	free((*_LIFO)->prev);
	(*_LIFO)->prev = NULL;
}


/**
 * div_s - check the code.
 * @_LIFO: _LIFO.
 * @l: the line number.
*/
void div_s(stack_t **_LIFO, unsigned int l)
{
	int s;

	if (!_LIFO || !(*_LIFO) || (*_LIFO)->next == NULL)
		error2(8, l, "div");

	if ((*_LIFO)->n == 0)
	{
		error2(9, l);
	}
	(*_LIFO) = (*_LIFO)->next;
	s = (*_LIFO)->n / (*_LIFO)->prev->n;
	(*_LIFO)->n = s;
	free((*_LIFO)->prev);
	(*_LIFO)->prev = NULL;
}
