#include <stdio.h>

int main()
{
    int testcase;
    long int input;

    long int prime;

    scanf("%d", &testcase);

    int i, j, k;

    for(i = 1; i <= testcase; i++)
    {
        scanf("%ld", &input);

        //k = sqrt(input);

        prime = 2;
        j = 2;

        while(input != 1)
        {
            if(input % j == 0)
            {
                input = input / j;
                prime = j;
            }
            j = j + 1;
        }


        printf("%ld\n", prime);
    }
    return 0;
}
