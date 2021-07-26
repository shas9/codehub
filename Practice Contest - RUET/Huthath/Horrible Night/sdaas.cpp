#include <stdio.h>

int main()
{
    int i, n;
    int last = 1, second_last = 2;


    scanf("%d", &n);

    while(second_last <= n)
    {
        int x = last * second_last;

        last = second_last;
        second_last = x;
    }

    printf("%d", second_last);


}

