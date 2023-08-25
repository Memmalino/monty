#include "monty.h"
/**
 * print_error - function that prints the necessary errors
 * @code: the nuber to specify the error to print
 * @argv_0: the name of the file to read
 * @opcode: the function which send a failure message
 * @line_n: the index of the current line
 */
void print_error(int code, char *argv_0, char *opcode, int line_n)
{
	switch (code)
	{
		case 0:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 1:
			fprintf(stderr, "Error: Can't open file %s\n", argv_0);
			break;
		case 2:
			fprintf(stderr, "L%d: unknown instruction %s\n", line_n, opcode);
			free(opcode);
			break;
		case 3:
			fprintf(stderr, "L%d: usage: %s integer\n", line_n, opcode);
			break;
	}

	exit(EXIT_FAILURE);
}

