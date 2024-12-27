// 1 - 1
// 10 - 2
// 11 - 0
// 100 - 1
// 101 - 2
// 110 - 0
// 111 - 1
// 1000 - 2
// 1001 - 0
// 1010 - 1 


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
                state = 'A';
                break;
            }
            else
            {
                state = 'B';
                break;
            }

        case 'B':
            if (ch == '0')
            {
                state = 'C';
                break;
            }
            else
            {
                state = 'A';
                break;
            }
        case 'C':
            if (ch == '0')
            {
                state = 'B';
                break;
            }
            else
            {
                state = 'C';
                break;
            }

        default:
            break;
        }
    }

    if (state == 'A')
    {
        printf("String Accepted \n");
    }
    else
    {
        printf("String Rejected \n");
    }
}


