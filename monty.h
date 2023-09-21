#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*func_exec)(stack_t **, unsigned int);
stack_t *newnode(int n);
void freen(void);
void print(stack_t **, unsigned int);
void addtostack(stack_t **, unsigned int);
void addtoqueue(stack_t **, unsigned int);
void file_exec(char *name);
int line_exec(char *buff, int ln, int form);
void read_f(FILE *);
void func_finder(char *, char *, int, int);
void top(stack_t **, unsigned int);
void pop_t(stack_t **, unsigned int);
void nothing(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);
void func_caller(func_exec, char *, char *, int, int);
void add(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void div_s(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);
void print_c(stack_t **, unsigned int);
void str_print(stack_t **, unsigned int);
void rl(stack_t **, unsigned int);
void error(int error_c, ...);
void error2(int error_c, ...);
void str_error(int error_c, ...);
void rr(stack_t **, unsigned int);
#endif
