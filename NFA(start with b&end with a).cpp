#include <stdio.h>

// Function to simulate the NFA
int simulateNFA(char *str) {
    int currentState = 0; // Initial state

    for (int i = 0; str[i] != '\0'; i++) {
        switch (currentState) {
            case 0:
                if (str[i] == 'b') {
                    currentState = 1;
                }
                break;
            case 1:
                if (str[i] == 'a') {
                    currentState = 2;
                } else if (str[i] != 'b') {
                    currentState = 0; // Reset to the initial state if 'b' is not followed by 'a'
                }
                break;
            default:
                break;
        }
    }

    return currentState == 2; // Accept if the final state is reached
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (simulateNFA(input)) {
        printf("The string is accepted by the NFA.\n");
    } else {
        printf("The string is not accepted by the NFA.\n");
    }

    return 0;
}
