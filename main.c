#include "monty.h"
void print_stack(stack_t *stack);
void monty_arg(char **tmp, stack_t **stack, int line, FILE *file);
void free_func(char **arg);
int main(int argc, char **argv)
{
	FILE *file = NULL;
	stack_t *stack = NULL;
	char line[1024], *token = NULL, *tmp[3];
	int i = 0, k = 0;
	if (argc != 2)
		print_error(0, NULL, NULL, 0);
	file = fopen(argv[1], "r");
	if (file == NULL)
		print_error(1, argv[1], NULL, 0);
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line[strcspn(line, "\n")] = '\0';
		token = strtok(line, " \t\n");
		if (token == NULL)
			continue;
		while (token != NULL)
		{
			if (i < 2)			
				tmp[i] = token;
			token = strtok(NULL, " \t\n");
			i++;
		}
		tmp[2] = NULL;
		monty_arg(tmp, &stack, k, file);
		k++;
	}

	fclose(file);

	while (stack != NULL)
	{
		stack_t *temp = stack;
		stack = stack->next;
		free(temp);
	}

	return EXIT_SUCCESS;
}
void monty_arg(char **tmp, stack_t **stack, int line, FILE *file)
{
	int j = 0;
	char *opcodee = NULL;
	void (*func)(stack_t **stack, unsigned int line_number) = NULL;
	instruction_t instructions[] = INSTRUCTIONS;


	while (instructions[j].opcode != NULL)
	{

		if (strcmp(instructions[j].opcode,tmp[0]) == 0)
		{
			if (tmp[1] != NULL)
				args[0] = strdup(tmp[1]);
			else
				args[0] = NULL;
			func = instructions[j].f;
			break;
		}
		j++;


	}
	if (func)
		func(stack, line + 1);
	else
	{

		opcodee = strdup(tmp[0]);
		fclose(file);
		print_error(2, NULL, opcodee, line + 1);
	}

}

void free_func(char **arg)
{
	int i = 0;

	while (arg[i] != NULL)
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}

