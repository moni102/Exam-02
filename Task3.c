#include <stdio.h>

#define LEN 500

int main()
{
    char number[LEN];
    int index = 0;

    do
    {
        char currSym;
        scanf("%c", &currSym);
        if (currSym != '\n')
        {
            continue;
        }
        else
        {
            number[index++] = currSym;
        }
    } while (index < LEN);

    for (int i = 0; i < index; i++)
    {
        if (i % 2 == 0)
        {
            number[i] = 'A' + number[i];
        }
        else
        {
            switch (number[i])
            {
            case 0:
                number[i] = '!';
                break;
            case 1:
                number[i] = '#';
                break;
            case 2:
                number[i] = '/';
                break;
            case 3:
                number[i] = '~';
                break;
            case 4:
                number[i] = '=';
                break;
            case 5:
                number[i] = '`';
                break;
            case 6:
                number[i] = '\\';
                break;
            case 7:
                number[i] = '>';
                break;
            case 8:
                number[i] = '.';
                break;
            case 9:
                number[i] = ',';
                break;
            }
        }
        printf("%c", number[i]);
    }
    printf("\n");
    return 0;
}