#include "monty.h"
void err_1()
{
    fprintf(stderr, "USAGE: monty file\n");
    free_nodes();
    exit(EXIT_FAILURE);
}
void err_2(char *file_name)
{
    fprintf(stderr,"Error: Can't open file %s", file_name);
    exit(EXIT_FAILURE);
}
void err_3(int line_number, char *opcode)
{
    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
    free_nodes();
    exit(EXIT_FAILURE);
}
void err_4()
{
    fprintf(stderr, "Error: malloc failed\n");
    free_nodes();
    exit(EXIT_FAILURE);
}
void err_5(int line_number)
{
    fprintf(stderr, "Error 5 at line %d: Invalid or missing value for 'push' operation\n", line_number);
    free_nodes();
    exit(EXIT_FAILURE);
}
void err_7(int line_number)
{
    fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
    free_nodes();
    exit(EXIT_FAILURE);
}
void err_6(unsigned int line_number)
{
    fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
    free_nodes();
    exit(EXIT_FAILURE);

}
void err_8(unsigned int line_number, char *op) {
    fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, op);
    free_nodes();
    exit(EXIT_FAILURE);
}
