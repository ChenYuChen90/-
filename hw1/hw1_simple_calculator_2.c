#include <stdio.h>

int main(void)
{
    double a=0, b=0;
    char operation;

    scanf("%lf %c %lf", &a, &operation, &b);

    if(operation == '+')
    {
        printf("%0.3lf\n", a+b);
    }
    if(operation == '-')
    {
        printf("%0.3lf\n", a-b);
    }
        if(operation == '*')
    {
        printf("%0.3lf\n", a*b);
    }
        if(operation == '/')
    {
        printf("%0.3lf\n", a/b);
    }
    return 0;
}