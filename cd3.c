#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Grammar:
    E → T + E | T
    T → F * T | F
    F → (E) | i
*/

char input[100];
int inde = 0;
int error = 0;

// Function declarations
void E();
void T();
void F();

void match(char expected) {
    if (input[inde] == expected) {
        inde++;
    } else {
        error = 1;
    }
}

void E() {
    T();
    if (input[inde] == '+') {
        match('+');
        E();
    }
}

void T() {
    F();
    if (input[inde] == '*') {
        match('*');
        T();
    }
}

void F() {
    if (input[inde] == '(') {
        match('(');
        E();
        match(')');
    } else if (input[inde] == 'i') {
        match('i');
    } else {
        error = 1;
    }
}

int main() {
    printf("Enter an arithmetic expression: ");
    fgets(input, 100, stdin);
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    E();

    // If parsing finished exactly at the end and no error
    if (error == 0 && inde == strlen(input)) {
        printf("Valid expression\n");
    } else {
        printf("Invalid expression\n");
    }

    return 0;
}
/*
Output: 
Enter an arithmetic expression: (i+i)*i 
Valid expression
*/