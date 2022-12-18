#include "monty.h"

<<<<<<< HEAD
#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int stack_top = -1;

void push(int value) {
if (stack_top < MAX_STACK_SIZE - 1) {
stack_top++;
stack[stack_top] = value;
}
else {
printf("Error: Stack is full\n");
}
}

void pall() {
for (int i = stack_top; i >= 0; i--) {
printf("%d\n", stack[i]);
}
}

int main(int argc, char* argv[]) {
char* opcode = argv[1];
int value = 0;

if (argc == 3) {
value = atoi(argv[2]);
}

if (strcmp(opcode, "push") == 0) {
push(value);
}
else if (strcmp(opcode, "pall") == 0) {
pall();
}
else {
printf("Error: Invalid opcode\n");
return EXIT_FAILURE;
}

return 0;
=======
/**
 * push - pushes an element to the stack
 * @stack: the stack
 * @line_number: the line number of the push instruction
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n = 0;
	stack_t *new;

	if (!stack)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(*new));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: the stack
 * @line_number: the line number of the pall instruction (unused)
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	if (!stack || !*stack)
		return;

	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
>>>>>>> c0f94fea3728778b743d0a236d61bf20f5e7a1fd
}

