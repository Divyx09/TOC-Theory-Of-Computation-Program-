#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100];
    char state = 'A';

    printf("Enter a String of digits (0-9): ");
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i];
        switch (state) {
        case 'A': 
            if (ch >= '0' && ch <= '9') {
                state = (ch - '0') % 3 == 0 ? 'A' : (ch - '0') % 3 == 1 ? 'B' : 'C';
            }
            break;

        case 'B': 
            if (ch >= '0' && ch <= '9') {
                state = (ch - '0') % 3 == 0 ? 'B' : (ch - '0') % 3 == 1 ? 'C' : 'A';
            }
            break;

        case 'C': 
            if (ch >= '0' && ch <= '9') {
                state = (ch - '0') % 3 == 0 ? 'C' : (ch - '0') % 3 == 1 ? 'A' : 'B';
            }
            break;
        }
    }

    if (state == 'A') {
        printf("String Accepted (Divisible by 3)\n");
    } else {
        printf("String Rejected (Not Divisible by 3)\n");
    }

    return 0;
}