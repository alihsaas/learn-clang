#include <stdio.h>

void CLEAN(char *str) {
    int i, j;
    int space_flag = 0;

    i = 0;
    while (str[i] == ' ') {
        i++;
    }
    if (i > 0) {
        j = 0;
        while (str[i]) {
            str[j++] = str[i++];
        }
        str[j] = '\0';
    }

    i = 0;
    while (str[i]) {
        i++;
    }
    i--;
    while (str[i] == ' ') {
        i--;
    }
    str[++i] = '\0';

    i = 0;
    j = 0;
    while (str[i]) {
        if (str[i] == ' ') {
            if (!space_flag) {
                space_flag = 1;
                str[j++] = ' ';
            }
        } else {
            space_flag = 0;
            str[j++] = str[i];
        }
        i++;
    }

    str[j] = '\0';
}

int main() {
    char string[250];
    gets(string);
    printf("Before: [%s]\n", string);
    CLEAN(string);
    printf("After: [%s]\n", string);
    return 0;
}
