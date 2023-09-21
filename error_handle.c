#include "monty.h"
/**
 * error - check the code
 * @error_c: error_c
*/
void error(int error_c, ...)
{
	int line_number;
	char *ptr;
	va_list args;

	va_start(args, error_c);
	if (error_c == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
	}
	else if (error_c == 2)
	{
		fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
	}
	else if (error_c == 3)
	{
		line_number = va_arg(args, int);
		ptr = va_arg(args, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, ptr);
	}
	else if (error_c == 4)
	{
		fprintf(stderr, "Error: malloc failed\n");
	}
	else if (error_c == 5)
	{
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
	}
	else
	{}
	freen();
	exit(EXIT_FAILURE);
}
/**
 * error2 - check the code
 * @error_c: error_c
*/
void error2(int error_c, ...)
{
	int line_number;
	va_list args;
	char *ptr;

	va_start(args, error_c);
	if (error_c == 6)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
	}
	else if (error_c == 7)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
	}
	else if (error_c == 8)
	{
		line_number = va_arg(args, unsigned int);
		ptr = va_arg(args, char *);
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, ptr);
	}
	else if (error_c == 9)
	{
		fprintf(stderr, "L%d: division by zero\n", va_arg(args, unsigned int));
	}
	else
	{}

	freen();
	exit(EXIT_FAILURE);
}
/**
 * str_error - check the code
 * @error_c: error_c
*/
void str_error(int error_c, ...)
{
	int line_number;
	va_list args;

	va_start(args, error_c);
	line_number = va_arg(args, int);
	if (error_c == 10)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
	}
	else if (error_c == 11)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
	}
	else
	{}
	freen();
	exit(EXIT_FAILURE);
}
