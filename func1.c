#include "monty.h"
void push(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}
void display(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
void po_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack)
		err_7(line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
void peek(stack_t **stack, unsigned int line_number)
{
	if (!stack)
		err_6(line_number);
	printf("%d\n", (*stack)->n);
}
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
void add_n(stack_t **stack, unsigned int line_number)
{
	int rev;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_8(line_number, "add");

	(*stack) = (*stack)->next;
	rev = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = rev;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
void swap_n(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_8(line_number, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}
