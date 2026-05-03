#include <stdio.h>
#include <ctype.h>
#include <string.h>

void analyze(char *code) {
    int i = 0;
    int tokenCount = 0;

    while (code[i] != '\0') {
        if (isspace(code[i])) {
            i++;
            continue;
        }


        if (isalpha(code[i])) {
            char buffer[50];
            int j = 0;
            while (isalnum(code[i])) {
                buffer[j++] = code[i++];
            }
            buffer[j] = '\0';

            if (strcmp(buffer, "int") == 0 || strcmp(buffer, "float") == 0 || strcmp(buffer, "double") == 0)
                printf("Token %d: '%s' (Keyword)\n", ++tokenCount, buffer);
            else
                printf("Token %d: '%s' (Identifier)\n", ++tokenCount, buffer);
        }


        else if (isdigit(code[i])) {
            char buffer[50];
            int j = 0;
            while (isdigit(code[i])) {
                buffer[j++] = code[i++];
            }
            buffer[j] = '\0';
            printf("Token %d: '%s' (Number)\n", ++tokenCount, buffer);
        }

        // 3. Operators & Separators
        else if (strchr("+-=*;", code[i])) {
            printf("Token %d: '%c' (Operator/Separator)\n", ++tokenCount, code[i++]);
        }
        else {
            i++;
        }
    }

    printf("\nTotal tokens found: %d\n", tokenCount);
}

int main() {
    char userInput[100];
    printf("Enter code: ");

    if (fgets(userInput, sizeof(userInput), stdin)) {
        userInput[strcspn(userInput, "\n")] = 0;
        analyze(userInput);
    }

    return 0;
}
