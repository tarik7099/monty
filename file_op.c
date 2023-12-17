#include "monty.h"
void open_fl(char *file_name)
{
    FILE *fd = fopen(file_name , "r");
    if (file_name == NULL || fd == NULL)
    {
        err_2(file_name);
    }
    read_fl(fd);
    fclose(fd);
}
void read_fl(FILE *fd)
{
    int line_number = 0;
    int format;
    char *buffer;
    size_t len;
    while(getline(&buffer, &len, fd) != -1)
    {
        format = handle_text(buffer, format , line_number);
        line_number++;
    }
    free(buffer);
}
int handle_text(char *buffer, int format , int line_number)
{
    char *opcode , *value;
    const char *delim = "\n ";
    if (buffer == NULL)
    {
        err_4();

    }
    opcode = strtok(buffer, delim);
    if (opcode == NULL)
    {
        return format;
    }
    value = strtok(NULL, delim);
    if (strcmp(opcode, "stack") == 0)
    {
        return 0;
    }
    if (strcmp(opcode, "queue") == 0)
    {
        return 1;
    }
    what_func(opcode, value, line_number, format);
    return format;
}
void what_func(char *opcode, char *value, int line_number, int format)
{
	int i;
	int count;

	instruction_t func_list[] = {
		{"push", add_queue},
    };
    /*
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
    */
	if (opcode[0] == '#')
		return;

	for (count = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, line_number, format);
			count = 0;
		}
	}
	if (count == 1)
		err_3(line_number, opcode);
}
void call_fun(op_func func, char *op, char *val, int line_number, int format)
{
	stack_t *node;
	int positive;
	int i;

	positive = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			positive = -1;
		}
		if (val == NULL)
			err_5(line_number);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err_5(line_number);
		}
		node = new_node(atoi(val) * positive);
		if (format == 0)
			func(&node, line_number);
		if (format == 1)
			add_queue(&node, line_number);
	}
	else
		func(&head, line_number);
}