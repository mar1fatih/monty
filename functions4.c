#include "monty.h"
/**
 * print_c - check the code.
 * @_LIFO: _LIFO.
 * @l: line number.
*/
void print_c(stack_t **_LIFO, unsigned int l)
{
	int letter;

	if (!_LIFO || !(*_LIFO))
	{
		str_error(11, l);
	}
	letter = (*_LIFO)->n;
	if (letter < 0 || letter > 127)
	{
		str_error(10, l);
	}
	printf("%c\n", letter);
}

/**
 * str_print - check the code.
 * @_LIFO: _LIFO.
 * @l: line number.
*/
void str_print(stack_t **_LIFO, unsigned int l)
{
	stack_t *current;
	int letter;

	(void)l;
	if (!_LIFO || !(*_LIFO))
	{
		printf("\n");
		return;
	}

	current = *_LIFO;
	while (current)
	{
		letter = current->n;
		if (letter <= 0 || letter > 127)
		{
			break;
		}
		printf("%c", letter);
		current = current->next;
	}
	printf("\n");
}

/**
 * rl - check the code.
 * @_LIFO: _LIFO.
 * @l: line number.
*/
void rl(stack_t **_LIFO, unsigned int l)
{
	stack_t *current;

	(void)l;
	if (!_LIFO || !(*_LIFO) || (*_LIFO)->next == NULL)
	{
		return;
	}
	current = *_LIFO;
	while (current->next)
	{
		current = current->next;
	}
	current->next = *_LIFO;
	(*_LIFO)->prev = current;
	*_LIFO = (*_LIFO)->next;
	(*_LIFO)->prev->next = NULL;
	(*_LIFO)->prev = NULL;
}


/**
 * rr - icheck the code.
 * @_LIFO: _LIFO.
 * @l: line number.
*/
void rr(stack_t **_LIFO, unsigned int l)
{
	stack_t *current;

	(void)l;
	if (!_LIFO || !(*_LIFO) || (*_LIFO)->next == NULL)
	{
		return;
	}
	current = *_LIFO;
	while (current->next)
	{
		current = current->next;
	}
	current->next = *_LIFO;
	current->prev->next = NULL;
	current->prev = NULL;
	(*_LIFO)->prev = current;
	(*_LIFO) = current;
}
