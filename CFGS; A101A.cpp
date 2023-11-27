#include <stdio.h>
#include <string.h>

// Function to check if the given string belongs to the CFG
int isBelongToCFG(char *str, int start, int end);

// Function to implement the production rules for A
int isA(char *str, int start, int end) {
    if (start > end) {
        return 1; // A can produce an empty string
    }

    if (str[start] == '0' || str[start] == '1') {
        return isA(str, start + 1, end);
    }

    return 0;
}

// Function to implement the production rules for S
int isS(char *str, int start, int end) {
    if (start > end) {
        return 0; // Empty string is not accepted
    }

    if (str[start] == '1' && str[start + 1] == '0' && str[start + 2] == '1') {
        return isA(str, start + 3, end);
    }

    return 0;
}

// Function to check if the given string belongs to the CFG
int isBelongToCFG(char *str, int start, int end) {
    return isS(str, start, end);
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (isBelongToCFG(input, 0, strlen(input) - 1)) {
        printf("The string belongs to the CFG.\n");
    } else {
        printf("The string does not belong to the CFG.\n");
    }

    return 0;
}
