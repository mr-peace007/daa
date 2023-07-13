#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define STACK_SIZE 100

// Stack implementation
char stack[STACK_SIZE];
int top = -1;

void push(char symbol) {
    if (top < STACK_SIZE - 1) {
        top++;
        stack[top] = symbol;
        printf("Pushed '%c' onto the stack.\n", symbol);
    }
}

char pop();
void displayStackOperations(); // Function prototype

bool isStackEmpty() {
    return (top == -1);
}

// DPDA simulation
bool isLanguageAccepted(char* input) {
    int len = strlen(input);
    int i;

    // Find the position of 'C'
    int positionC = -1;
    for (i = 0; i < len; i++) {
        if (input[i] == 'C') {
            positionC = i;
            break;
        }
    }

    // If 'C' is not found or it occurs at the start or end of the string, return false
    if (positionC == -1 || positionC == 0 || positionC == len - 1) {
        return false;
    }

    // Check if the first half of the string matches the reverse of the second half
    for (i = 0; i < positionC; i++) {
        if (input[i] != input[len - i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    char input[100];

    printf("Enter a string (containing 0 and 1): ");
    scanf("%s", input);

    // Reset the stack
    top = -1;

    // Perform DPDA simulation
    for (int i = 0; i < strlen(input); i++) {
        char symbol = input[i];
        if (symbol == '0' || symbol == '1') {
            push(symbol);
        } else if (symbol == 'C') {
            if (isStackEmpty()) {
                printf("Error: Stack underflow\n");
                return 0;
            }
            int j;
            for (j = i + 1; j < strlen(input); j++) {
                if (pop() != input[j]) {
                    printf("Error: Stack mismatch\n");
                    return 0;
                }
            }
            break;
        }
        displayStackOperations();  // Display stack elements after each step
    }

    if (isStackEmpty()) {
        printf("String is in the language L!\n");
    } else {
        printf("String is not in the language L.\n");
    }

    return 0;
}

char pop() {
    char symbol = stack[top];
    top--;
    printf("Popped '%c' from the stack.\n", symbol);
    displayStackOperations();  // Display stack elements after each pop
    return symbol;
}

void displayStackOperations() {
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%c ", stack[i]);
    }
    printf("\n\n");
}
