#include <stdio.h>
#include <string.h>
int isBelongToCFG(char *str, int start, int end);
int isS(char *str, int start, int end) {
    if (start > end) {
        return 1; 
    }

    if (str[start] == '0' && str[end] == '0') {
        return isBelongToCFG(str, start + 1, end - 1);
    }

    return 0;
}
int isA(char *str, int start, int end) {
    if (start > end) {
        return 1; // A can produce an empty string
    }

    if (str[start] == '1') {
        return isA(str, start + 1, end);
    }

    return 0;
}
int isBelongToCFG(char *str, int start, int end) {
    if (isS(str, start, end)) {
        return 1;
    } else if (str[start] == '1') {
        return isA(str, start + 1, end);
    }

    return 0;
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


