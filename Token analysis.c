#include <stdio.h>
#include <ctype.h>
#include <string.h>

void analyze(char *code) {
    int i = 0;
    while (code[i] != '\0') {

        if (isspace(code[i])) {
            i++;
            continue;
        }


        if (isalpha(code[i])) {
            char buffer[20];
            int j = 0;
            while (isalnum(code[i])) {
                buffer[j++] = code[i++];
            }
            buffer[j] = '\0';

            if (strcmp(buffer, "int") == 0 || strcmp(buffer, "float") == 0 || strcmp(buffer, "double") == 0)
                printf("%s \t is a keyword\n", buffer);
            else
                printf("%s \t is an identifier\n", buffer);
        }


        else if (isdigit(code[i])) {
            char buffer[20];
            int j = 0;
            while (isdigit(code[i])) {
                buffer[j++] = code[i++];
            }
            buffer[j] = '\0';
            printf("%s \t is a number\n", buffer);
        }


        else if (strchr("+-=*", code[i])) {
            printf("%c \t is an operator\n", code[i++]);
        }


        else if (code[i] == ';') {
            printf("%c \t is a separator\n", code[i++]);
        }

        else {
            i++;
        }
    }
}

int main() {
    char userInput[100];

    printf("Enter a line of code (e.g., int x = 10;): ");

    // Using fgets to safely take string input including spaces
    if (fgets(userInput, sizeof(userInput), stdin)) {
        // Remove trailing newline character if present
        userInput[strcspn(userInput, "\n")] = 0;

        printf("\n--- Analysis Results ---\n");
        analyze(userInput);
    }

    return 0;
}
