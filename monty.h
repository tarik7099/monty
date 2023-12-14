#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
typedef struct  arg_s
{

    FILE *file;
    char *line;
    unsigned int line_number;
    char **token;
    int ntoken;
    instruction_t *instruction;
    stack_t *head;
    int stack_length;
}arg_t;
extern arg_t * arguments;

void initialize_args();

void get_file(char *filename);
void get_instruction(void);
void execute(void);
void push(stack_t ** stack , unsigned int line_number);
int my_number(char * str);
void pall(stack_t **stack, unsigned int line_number);
void close_file(void);




void push(stack_t ** stack , unsigned int line_number);
void pop(stack_t ** stack , unsigned int line_number);
void pint(stack_t ** stack , unsigned int line_number);
void pall(stack_t ** stack , unsigned int line_number);
void swap(stack_t ** stack , unsigned int line_number);
void add(stack_t ** stack , unsigned int line_number);

#endif 