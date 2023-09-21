#include "monty.h"
/**
 * newnode - check the code.
 * @n: n.
 * Return: stack_t.
*/
stack_t *newnode(int n)
{
	stack_t *new_n;

	new_n = malloc(sizeof(stack_t));
	if (!new_n)
	{
		error(4);
	}
	new_n->n = n;
	new_n->next = NULL;
	new_n->prev = NULL;
	return (new_n);
}

/**
 * freen - Free
*/
void freen(void)
{
	stack_t *current;

	if (!head)
		return;

	while (head)
	{
		current = head;
		head = head->next;
		free(current);
	}
}

/**
 * mul - check the code.
 * @_LIFO: _LIFO.
 * @l: the line number.
*/
void mul(stack_t **_LIFO, unsigned int l)
{
	int s;

	if (!_LIFO || !(*_LIFO) || (*_LIFO)->next == NULL)
	{
		error2(8, l, "mul");
	}
	(*_LIFO) = (*_LIFO)->next;
	s = (*_LIFO)->n * (*_LIFO)->prev->n;
	(*_LIFO)->n = s;
	free((*_LIFO)->prev);
	(*_LIFO)->prev = NULL;
}


/**
 * mod - check the code.
 * @_LIFO: _LIFO.
 * @l: line number.
*/
void mod(stack_t **_LIFO, unsigned int l)
{
	int s;

	if (!_LIFO || !(*_LIFO) || (*_LIFO)->next == NULL)
	{
		error2(8, l, "mod");
	}
	if ((*_LIFO)->n == 0)
	{
		error2(9, l);
	}
	(*_LIFO) = (*_LIFO)->next;
	s = (*_LIFO)->n % (*_LIFO)->prev->n;
	(*_LIFO)->n = s;
	free((*_LIFO)->prev);
	(*_LIFO)->prev = NULL;
}
