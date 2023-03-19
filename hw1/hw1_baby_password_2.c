#include <stdio.h>

int main(void)
{
    char C, operation;
    int D;

    scanf("%c %c %d", &C, &operation, &D);

    if('A' <= C && C <= 'Z')
    {
        C += 32;
        if(operation == '+')
        {
            if(C-D < 'a')
            {
                C += 26;
            }
            C -= D;
            printf("%c\n", C);
        }
        if(operation == '-')
        {
            if(C+D > 'z')
            {
                C -= 26;
            }
            C += D;
            printf("%c\n", C);
        }
        return 0;
    }
    if('a' <= C && C <= 'z')
    {
        C -= 32;
        if(operation == '+')
        {
            if(C-D < 'A')
            {
                C += 26;
            }
            C -= D;
            printf("%c\n", C);
        }
        if(operation == '-')
        {
            if(C+D > 'Z')
            {
                C -= 26;
            }
            C += D;
            printf("%c\n", C);
        }
        return 0;
    }
}