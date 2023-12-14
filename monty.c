#include "monty.h"
#define MAX_LINE_LENGTH 100

arg_t *arguments = NULL;

void initialize_args() {
    arguments = malloc(sizeof(arg_t));
    if (arguments == NULL) {
        printf("Error: malloc failed");
        exit(EXIT_FAILURE);
    }
    arguments->file = NULL;
    arguments->line = NULL;
     // Initialize file pointer to NULL
    arguments->token = 0;
    arguments->line_number = 0; // Initialize line pointer to NULL
}
void tokenzier(void)
{
    int i = 0;
    char *token = NULL, *linecopy = NULL;
    linecopy = malloc(sizeof(char) * (strlen(arguments->line) + 1));
    strcpy(linecopy , arguments->line);
    arguments->ntoken = 0;
    token = strtok(linecopy," \n");
    while (token)
    {
        arguments->ntoken += 1;
        token = strtok(NULL , " \n");
    }
    arguments->token = malloc(sizeof(char *) * (arguments->ntoken + 1));
    strcpy(linecopy , arguments->line);
    token = strtok(linecopy , " \n");
    while (token)
    {
        arguments->token[i] = malloc(sizeof(char) * (strlen(token) + 1));
    }
    if (arguments->token[i] == NULL)
        {
        printf("Error: malloc failed");
        exit(EXIT_FAILURE);
        }
        strcpy(arguments->token[i] , token);
        token = strtok(NULL , " \n");
        i++;
        arguments->token[i];
        free(linecopy);
    
}

void get_file(char *filename) {
    arguments->file = fopen(filename, "r");
    if (arguments->file == NULL) {
        printf("Error: Can't open file");
        free(arguments);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    size_t n = 0;
    int i = 0;
    (void)argv;
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    initialize_args();
    get_file(argv[1]);

    while (getline(&arguments->line, &n, arguments->file) != -1) {
            arguments->line_number +=1;
            tokenzier();
            get_instruction();
            execute();
        //if (arguments-> token == NULL)
        //{
        //    return;
        //}
        while (arguments->token[i])
        {
            free(arguments->token[i]);
            i++;
        }
        free(arguments->token);
        arguments->token = NULL;
    
    }
    //close_stream();
    //free_argume():

    fclose(arguments->file); // Close the file after reading
    free(arguments->line);   // Free allocated memory for line
    free(arguments);         // Free allocated memory for arguments

    return 0;
}
void get_instruction(void)
{
    int i = 0;
    instruction_t instruction[] = {{"push", &push}, {"pop", &pop}, {"pint", &pint},};// {"swap",&swap},{"nop",&nop},{"add",&add},{"pall", &pall}, {"sub",&sub}{NULL,NULL}};
    if (arguments->token == 0)
        return;
    for  (;instruction[i].opcode != NULL; i++)
    {
        if (strcmp(instruction[i].opcode , arguments->token[0]) == 0)
        {
            arguments->instruction->opcode = instruction[i].opcode;
            arguments->instruction->f = instruction[i].f;
            return;
        }
        
    printf("%d : unknown instruction %s\n", arguments->line_number, arguments->token[0]);
    fclose(arguments->file);
    if (arguments-> token == NULL)
        return;
    while (arguments->token[i])
    {
        free(arguments->token[i]);
        i++;
    }
    free(arguments->token);
    arguments->token = NULL;
    
    exit(EXIT_FAILURE);


    }
}
void execute(void)
{
    stack_t *stack = NULL;
    if (arguments->token == 0)
        return;
    arguments->instruction->f(&stack, arguments->line_number);

}
void push(stack_t **stack , unsigned int line_number)
{
    int i = 0;
    if (arguments->ntoken <= 1 || !(my_number(arguments->token[1])))
    {
    while (arguments->token[i])
    {
        free(arguments->token[i]);
        i++;
    }
    free(arguments->token);
    arguments->token = NULL;
    printf("%d:usage: push integer\n", line_number);
    }
    exit(EXIT_FAILURE);
    *stack = malloc(sizeof(stack_t));
    if (stack == NULL)
    {
        printf("Error: malloc failed");
        exit(EXIT_FAILURE);
    }
    (*stack)->next = (*stack)->prev = NULL;
    (*stack)->n = (int) atoi(arguments->token[1]);
    if (arguments->head != NULL)
    {
        (*stack)->next = arguments->head;
        arguments->head->prev = *stack;
    }
    arguments->head = *stack;
    arguments->stack_length += 1;
}
int my_number(char * str)
{
    int i = 0 ;
    while (str[i])
    {
        if (i == 0 && str[i] == '-' && str[i + 1])
        {
            i++;
            continue;
        }
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp;
    if (arguments->head == NULL)
        return;

(void)line_number;
(void)stack;
tmp = arguments->head;
while(tmp != NULL){
    printf("%d\n", tmp->n);
    tmp = tmp->next;
}

}
void pop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    if (arguments->head == NULL)
    {
        printf("L%d: can`t pop an empty stack \n",line_number);

        exit(EXIT_FAILURE);

    }
    stack_t *tmp;
    tmp = arguments->head;
    arguments->head = tmp->next;
    free(tmp);
}

void close_file(void)
{
    if (arguments->file == NULL)
        return;
    fclose(arguments->file);
    arguments->file = NULL;
}
void pint(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    if (arguments->head == NULL)
    {
        printf("L%d: cant`t pint, stack empty\n",line_number);
        exit(EXIT_FAILURE);
    }
    printf("d%n", arguments->head->n);
}