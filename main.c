#include "monty.h"

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_fl(argv[1]);
	free_nodes();
	return (0);
}


stack_t *new_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
    {
		err_4();
    }
    node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}


void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


void push(stack_t **head_ref,  __attribute__((unused))unsigned int n)
{
    stack_t *node = new_node(n);

    if (node == NULL)
    {
        err_4();
        return;
    }

    node->next = *head_ref;
    if (*head_ref != NULL)
        (*head_ref)->prev = node;

    *head_ref = node;
}
