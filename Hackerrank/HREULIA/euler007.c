#include <stdio.h>

int main()
{
    int testcase;

    scanf("%d", &testcase);

    int i, a, prime;
    int input;
    int position;

    for(i = 1; i <= testcase; i++)
    {
        scanf("%d", &input);
        position = 1;
        prime = 3;

        if(input == 1)
        {
            printf("2\n");
        }
        else
        {
             while(position != input)
            {
            for(a = 2; a < prime; a++)
            {
                if(prime % a == 0)
                {
                    break;
                }

            }
            if(a == prime)
            {
                position = position + 1;
                if(position == input)
                {
                    printf("%d\n", prime);
                    break;
                }
            }
            prime = prime + 1;
            }
        }


    }
    return 0;
}
