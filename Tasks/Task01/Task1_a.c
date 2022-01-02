#include <stdio.h>
#include <stdlib.h>

int main()
{
    int exp, n;
    printf("Enter the exponent:\n");
    scanf("%d", &exp);
    printf("Enter the number of iterations:\n");
    scanf("%d", &n);
    double result = 0.0;
    long int fact = 1;
    long int x = 1;
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            fact *= i;
        result += (double)x / fact;
        x *= exp;
    }
    printf("The exponential result = %lf\n", result);
    return 0;
}