#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char word[20];
    gets(word);
    char circ[10] = "circle";
    int i = 0, p = 0;
    if (strncmp(word, circ, 6) == 0)
        ;
    else {
        printf("\n^\nError at column 0: expected 'circle'");
        return -1;
    }
    printf("circle");
    i = 6;
    if (word[6] == '(')
        printf("(");
    else {
        printf("%c\n", word[6]);
        for (int g = 0; g < i; g++) {
            printf(" ");
        }
        printf("^\nError at column 1: expected '('");
        return -2;
    }
    i = 7;
    while (word[i] != ',') {
        if (isdigit(word[i]) == 1 or (word[i] == '-' && isdigit(word[i + 1]))
            or (word[i] == '.' && isdigit(word[i + 1]) && isdigit(word[i - 1])))
            printf("%c", word[i]);
        else if (
                p == 0 && word[i] == ' '
                && (isdigit(word[i + 1]) or isdigit(word[i - 1]))) {
            printf("%c", word[i]);
            p = 1;
        } else {
            printf("%c\n", word[i]);
            for (int g = 0; g < i; g++) {
                printf(" ");
            }
            printf("^\nError at column 2: expected <double>");
            return -2;
        }
        i++;
    }
    printf("%c", word[i]);
    i++;
    while (word[i] != ')') {
        if (isdigit(word[i]) == 1 or (word[i] == '-' && isdigit(word[i + 1])))
            printf("%c", word[i]);
        else if (word[i] == ' ' && isdigit(word[i + 1]) && word[i - 1] == ',')
            printf("%c", word[i]);
        else if (
                word[i] == '.'
                && (isdigit(word[i + 1]) or isdigit(word[i - 1])))
            printf("%c", word[i]);
        else {
            printf("%c\n", word[i]);
            for (int g = 0; g < i; g++) {
                printf(" ");
            }
            printf("^\nError at column 2: expected <double>");
            return -2;
        }
        i++;
    }
    if (word[i] == ')')
        printf(")");
    else {
        printf("%c\n", word[6]);
        for (int g = 0; g < i; g++) {
            printf(" ");
        }
        printf("^\nError at column 3: expected ')'");
        return -2;
    }
    i++;
    for (i = i; i < strlen(word); i++) {
        printf("%c", word[i]);
        if (word[i] != ' ') {
            printf("\n");
            for (int g = 0; g < i; g++) {
                printf(" ");
            }
            printf("^\nError at column 4: expected unexpected token");
            return -3;
        }
    }
}
