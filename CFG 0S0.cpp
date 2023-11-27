#include <stdio.h>
#include <string.h>
int isCFGString(char *str, int start, int end) {
    if (start > end) {
        return 1; 
    }
    if (str[start] == '0' && str[end] == '0') {
        return isCFGString(str, start + 1, end - 1);
    } else if (str[start] == '1' && str[end] == '1') {
        return isCFGString(str, start + 1, end - 1);
    } else if (str[start] == '0') {
        return isCFGString(str, start + 1, end);
    } else if (str[start] == '1') {
        return isCFGString(str, start, end - 1);
    }

    return 0; 
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if (isCFGString(str, 0, strlen(str) - 1)) {
        printf("The string belongs to the CFG language.\n");
    } else {
        printf("The string does not belong to the CFG language.\n");
    }

    return 0;
}
