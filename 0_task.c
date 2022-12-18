#include "monty.h"

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
}
