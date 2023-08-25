#include "monty.h"

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

