#include<stdio.h>

int fib(int x)
{
    if(x == 1) return 0; // Base Case 1
    if(x == 2) return 1; // Base Case 2

    return fib(x - 1) + fib(x - 2);
}

int main()
{
    int numberoffib;

    scanf("%d", &numberoffib);

    int ans = fib(numberoffib);

    printf("%d", ans);
}

