#include <stdio.h>
#include <string.h>
int isBelongToCFG(char str[]);
int isA(char str[], int *index);

int main() {
    char inputString[100];
    printf("Enter the string to check: ");
    scanf("%s", inputString);
    if (isBelongToCFG(inputString)) {
        printf("The string belongs to the CFG.\n");
    } else {
        printf("The string does not belong to the CFG.\n");
    }

    return 0;
}

int isBelongToCFG(char str[]) {
    int index = 0;
    if (str[index] == '0') {
        index++;
        if (isA(str, &index)) {
            if (str[index] == '1' && str[index + 1] == '\0') {
                return 1;
            }
        }
    }

    return 0; 
}

int isA(char str[], int *index) {
    if (str[*index] == '\0') {
        return 1;
    }
    if (str[*index] == '0') {
        (*index)++;
        return isA(str, index);
    }
    if (str[*index] == '1') {
        (*index)++;
        return isA(str, index);
    }

    return 0; 
}
