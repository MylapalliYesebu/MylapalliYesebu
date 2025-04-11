#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct three {
    char data[10], temp[7];
} s[30];

int main() {
    char d1[7], d2[7] = "t";
    int i = 0, j = 1, len = 0;
    FILE *f1, *f2;

    f1 = fopen("sum.txt", "r");
    if (f1 == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    f2 = fopen("out.txt", "w");
    if (f2 == NULL) {
        printf("Error opening output file.\n");
        fclose(f1);
        return 1;
    }

    while (fscanf(f1, "%s", s[len].data) != EOF) {
        len++;
    }
    
    sprintf(d1, "%d", j);
    strcat(d2, d1);
    strcpy(s[j].temp, d2);
    strcpy(d2, "t");

    if (!strcmp(s[3].data, "+")) {
        fprintf(f2, "%s=%s+%s", s[j].temp, s[i + 2].data, s[i + 4].data);
        j++;
    } else if (!strcmp(s[3].data, "-")) {
        fprintf(f2, "%s=%s-%s", s[j].temp, s[i + 2].data, s[i + 4].data);
        j++;
    }

    for (i = 4; i < len - 2; i += 2) {
        sprintf(d1, "%d", j);
        strcat(d2, d1);
        strcpy(s[j].temp, d2);

        if (!strcmp(s[i + 1].data, "+"))
            fprintf(f2, "\n%s=%s+%s", s[j].temp, s[j - 1].temp, s[i + 2].data);
        else if (!strcmp(s[i + 1].data, "-"))
            fprintf(f2, "\n%s=%s-%s", s[j].temp, s[j - 1].temp, s[i + 2].data);

        strcpy(d2, "t");
        j++;
    }

    fprintf(f2, "\n%s=%s", s[0].data, s[j - 1].temp);

    fclose(f1);
    fclose(f2);

    printf("Three-address code generated in 'out.txt'.\n");

    return 0;
}
