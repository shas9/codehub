#include <stdio.h>

int main()
{
    int testcase, input, i, result;

    scanf("%d", &testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanf("%d", &input);
        result = 1;

        int j;

        for(j = 1; input >= j; input--)
        {
            if(result % input != 0)
            {
                printf("DBUG %d\n", input);
                result = result * input;
            }

        }
        printf("%d\n", result);

    }
    return 0;
}
