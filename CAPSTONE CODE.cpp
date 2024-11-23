#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EQ_LENGTH 100

// Function to generate three-address code
void generateThreeAddressCode(char *equations[], int num_equations) {
    char variables[MAX_EQ_LENGTH][MAX_EQ_LENGTH];
    char operation[MAX_EQ_LENGTH];
    int var_count = 0;

    for (int i = 0; i < num_equations; i++) {
        char *equation = equations[i];
        char *token = strtok(equation, " ");

        // Get the left-hand side variable
        strcpy(variables[var_count], token);
        var_count++;

        while (token != NULL) {
            token = strtok(NULL, " ");
            if (token != NULL) {
                if (strcmp(token, "=") != 0) {
                    // Check if token is an operation
                    if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0 ||
                        strcmp(token, "&&") == 0 || strcmp(token, "||") == 0) {
                        strcpy(operation, token);
                    } else {
                        // Store operands into variables array
                        strcpy(variables[var_count], token);
                        var_count++;
                    }
                }
            }
        }

        // Generate machine code
        if (strcmp(operation, "+") == 0) {
            printf("MOV %s, %s\n", variables[1], variables[0]);
            printf("ADD %s, %s", variables[1], variables[2]);
            printf("STOR %s, %s\n\n", variables[0], variables[1]);
        } 
		else if (strcmp(operation, "-") == 0) {
            printf("MOV %s, %s\n", variables[1], variables[0]);
            printf("SUB %s, %s", variables[1], variables[2]);
            printf("STOR %s, %s\n\n", variables[0], variables[1]);
        } 
		else if (strcmp(operation, "*") == 0) {
            printf("MOV %s, %s\n", variables[1], variables[0]);
            printf("MUL %s, %s", variables[1], variables[2]);
            printf("STOR %s, %s\n\n", variables[0], variables[1]);
        } 
		else if (strcmp(operation, "/") == 0) {
            printf("MOV %s, %s\n", variables[1], variables[0]);
            printf("DIV %s, %s", variables[1], variables[2]);
            printf("STOR %s, %s\n\n", variables[0], variables[1]);
        }
		else if (strcmp(operation, "&&") == 0) {
            printf("MOV %s, %s\n", variables[1], variables[0]);
            printf("AND %s, %s", variables[1], variables[2]);
            printf("STOR %s, %s\n\n", variables[0], variables[1]);
        }
		else if (strcmp(operation, "||") == 0) {
            printf("MOV %s, %s\n", variables[1], variables[0]);
            printf("OR %s, %s", variables[1], variables[2]);
            printf("STOR %s, %s\n\n", variables[0], variables[1]);
        }
        else if (strcmp(operation, "<=") == 0) {
            printf("MOV %s, %s\n", variables[1], variables[0]);
            printf("OR %s, %s", variables[1], variables[2]);
            printf("STOR %s, %s\n\n", variables[0], variables[1]);
        }
        else if (strcmp(operation, "") == 0) {
            printf("MOV %s, %s\n", variables[1], variables[0]);
            printf("OR %s, %s", variables[1], variables[2]);
            printf("STOR %s, %s\n\n", variables[0], variables[1]);
        }

        // Reset var_count and operation for next equation
        var_count = 0;
        memset(operation, 0, sizeof(operation));
    }
}

int main() {
    char *equations[MAX_EQ_LENGTH];
    char input[MAX_EQ_LENGTH];
    int num_equations = 0;

    printf("Enter equations in the format 'left = right' (or 'quit' to exit):\n");

    while (1) {
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "quit\n") == 0) {
            break;
        }
        equations[num_equations] = strdup(input);
        num_equations++;
    }

    printf("\nThe output of this program is based on the input equations.\n");
    printf("One thing to notice is that in each equation, there is only one variable on the left side.\n");
    printf("The operators and operands used on the right side must be space-separated from each other.\n\n");

    // Generate machine code
    generateThreeAddressCode(equations, num_equations);

    return 0;
}

