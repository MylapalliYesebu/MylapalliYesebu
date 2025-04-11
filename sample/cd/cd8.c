#include <stdio.h>
#include <string.h>

int k = 0, z = 0, i = 0, j = 0, c = 0;
char a[16], ac[20], stk[20], act[20];

void check();

int main() {
    printf("GRAMMAR is:\nE → E+E\nE → E*E\nE → (E)\nE → id\n");
    printf("Enter input string: ");
    scanf("%s", a);

    c = strlen(a);
    strcpy(act, "SHIFT");

    printf("\nStack\t\tInput\t\tAction\n");

    for (k = 0, i = 0, j = 0; j < c; k++, i++, j++) {
        if (a[j] == 'i' && a[j + 1] == 'd') {
            stk[i] = a[j];
            stk[i + 1] = a[j + 1];
            stk[i + 2] = '\0';
            a[j] = ' ';
            a[j + 1] = ' ';
            j++; // skip next since it's part of 'id'
            printf("$%s\t\t%s$\t%s id\n", stk, a, act);
            check();
        } else {
            stk[i] = a[j];
            stk[i + 1] = '\0';
            a[j] = ' ';
            printf("$%s\t\t%s$\t%s symbol\n", stk, a, act);
            check();
        }
    }

    return 0;
}

void check() {
    strcpy(ac, "REDUCE TO E");

    // Reduce id -> E
    for (z = 0; z < c; z++) {
        if (stk[z] == 'i' && stk[z + 1] == 'd') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            printf("$%s\t\t%s$\t%s\n", stk, a, ac);
        }
    }

    // Reduce E*E -> E
    for (z = 0; z < c; z++) {
        if (stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("$%s\t\t%s$\t%s\n", stk, a, ac);
            i = i - 2;
        }
    }

    // Reduce E+E -> E
    for (z = 0; z < c; z++) {
        if (stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("$%s\t\t%s$\t%s\n", stk, a, ac);
            i = i - 2;
        }
    }

    // Reduce (E) -> E
    for (z = 0; z < c; z++) {
        if (stk[z] == '(' && stk[z + 1] == 'E' && stk[z + 2] == ')') {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("$%s\t\t%s$\t%s\n", stk, a, ac);
            i = i - 2;
        }
    }
}
/*
Output: 
/tmp/rVDYCnu0I4.o 
GRAMMAR is E->E+E  
 E->E*E  
 E->(E)  
 E->id 
enter input string  
id+id\id+id 
 
stack         input                 action 
 
$id   +id\id+id$       SHIFT->id 
$E   +id\id+id$       REDUCE TO E 
$E+    id\id+id$      SHIFT->symbols 
$E+id      \id+id$      SHIFT->id 
$E+E      \id+id$     REDUCE TO E 
$E+E\       id+id$     SHIFT->symbols 
$E+E\id         +id$     SHIFT->id 
$E+E\E         +id$     REDUCE TO E 
$E+E\E+        id$                   SHIFT->symbols 
$E+E\E+id       $        SHIFT->id 
$E+E\E+E        $     REDUCE TO E
*/