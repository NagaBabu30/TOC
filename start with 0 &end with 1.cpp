#include <stdio.h>
#include <stdbool.h>

// Define states
enum State { Q0, Q1, Q2 };

// Function to check if the input string is accepted
bool isAccepted(const char* str) {
    enum State currentState = Q0;
    int index = 0;

    while (str[index] != '\0') {
        switch (currentState) {
            case Q0:
                if (str[index] == '0') {
                    currentState = Q1;
                } else {
                    currentState = Q0;
                }
                break;

            case Q1:
                if (str[index] == '0') {
                    currentState = Q1;
                } else if (str[index] == '1') {
                    currentState = Q2;
                } else {
                    currentState = Q0;
                }
                break;

            case Q2:
                currentState = Q0; // Once in Q2, stay in Q0 to reject further input
                break;
        }

        index++;
    }

    return currentState == Q2;
}

int main() {
    // Example usage
    const char* inputString = "001";

    if (isAccepted(inputString)) {
        printf("Accepted\n");
    } else {
        printf("Not Accepted\n");
    }

    return 0;
}
