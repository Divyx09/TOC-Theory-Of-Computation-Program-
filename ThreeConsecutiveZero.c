#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char str[100];
    char state = 'A';

    printf("Enter a String over {0,1}: ");
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++)
    {
        char ch = str[i];
        switch (state)
        {
        case 'A':
            if (ch == '0')
            {
                state = 'B';
            }
            else
            {
                state = 'A';
            }
                break;

        case 'B':
            if (ch == '0')
            {
                state = 'C';
            }
            else
            {
                state = 'A';
            }
                break;
        case 'C':
            if (ch == '0')
            {
                state = 'D';
            }
            else
            {
                state = 'A';
            }
                break;

        case 'D':
            if (ch == '0')
            {
                state = 'D';
            }
            else
            {
                state = 'D';
            }
                break;
        default:
            break;
        }
    }

    if (state == 'D')
    {
        printf("String Accepted");
    }
    else
    {
        printf("String Rejected");
    }
}


