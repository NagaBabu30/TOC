#include <stdio.h>

int isAccepted(char str[]) {
    int currentState = 0;  
    int i = 0;

    while (str[i] != '\0') {
        if (currentState == 0 && str[i] == 'a') {
            currentState = 1;  
        } else if (currentState == 1 && str[i] == 'a') {
        } else {
            return 0;  
        }

        i++;
    }
    return currentState == 1;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    if (isAccepted(input)) {
        printf("Accepted\n");
    } else {
        printf("Not Accepted\n");
    }

    return 0;
}
