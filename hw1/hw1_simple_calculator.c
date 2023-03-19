#include <stdio.h>

int main(void)
{
    double numbers[2] = {0};
    char operation = 0;

    scanf("%lf %c %lf", &numbers[0], &operation, &numbers[1]);

    if(operation == '+')
    {
        printf("%0.3f\n", numbers[0]+numbers[1]);
    }
    if(operation == '-')
    {
        printf("%0.3f\n", numbers[0]-numbers[1]);
    }
    if(operation == '*')
    {
        printf("%0.3f\n", numbers[0]*numbers[1]);
    }
    if(operation == '/' && numbers[1] != 0)
    {
        printf("%0.3f\n", numbers[0]/numbers[1]);
    }
    if(operation == '/'&& numbers[1] == 0)
    {
        printf("Error\n");
    }


    return 0;
}
