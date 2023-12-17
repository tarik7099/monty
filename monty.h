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
typedef void (*op_func)(stack_t **, unsigned int);
/* file operation*/
void open_fl(char *file_name);

/* error */
void err_1();
void err_5(int line_number);
void err_4();
void err_3(int line_number, char *opcode);
void err_2(char *file_name);
void err_7(int line_number);

/*func*/
void call_fun(op_func func, char *op, char *val, int line_number, int format);
void what_func(char *opcode, char *value, int line_number, int format);
int handle_text(char *buffer, int format , int line_number);
void read_fl(FILE *fd);
void push(stack_t **new_node, __attribute__((unused))unsigned int ln);
void free_nodes(void);
void add_push(stack_t **head_ref,  __attribute__((unused))unsigned int n);
stack_t *new_node(int n);
void display(stack_t **stack, unsigned int line_number);
void po_top(stack_t **stack, unsigned int line_number);
void peek(stack_t **stack, unsigned int line_number);
#endif