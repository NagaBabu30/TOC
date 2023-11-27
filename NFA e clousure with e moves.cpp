#include <stdio.h>
int simulateNFA(char *str) {
    int currentState = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        switch (currentState) {
            case 0:
                if (str[i] == 'o') {
                    currentState = 1;
                }
                break;
            case 1:
                if (str[i] == '1') {
                    currentState = 2;
                } else if (str[i] != 'o') {
                    currentState = 0; 
                }
                break;
            default:
                break;
        }
    }

    return currentState == 2; 
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
