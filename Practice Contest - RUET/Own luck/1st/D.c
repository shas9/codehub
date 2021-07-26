#include<stdio.h>

int main()
{
    char input[200000];
    int flag;
    int data[30];

    int ln;

    long long int k, m;

    int i,j;

    int max;

    int position[30];

    scanf("%s", input);
    scanf("%lld", &k);

    for(ln = 0; input[ln] != '\0'; ln++);

    if(k >= ln)
    {
        printf("0\n\n");
        return 0;
    }

    for(i = 0; i < 30; i++)
    {
        data[i] = 0;
    }

    for(i = 0; i < ln; i++)
    {
        flag = input[i];

        flag = flag - 96;

        data[i]++;
    }

    int countchar;

    for(i = 0; i < 30; i++)
    {
        if(data[i] > 0)
        {
            countchar++;
        }
    }

    if(k == 0)
    {
        printf("%d\n",countchar);
        printf("%s\n",input);
        return 0;
    }


    max = data[0];


}
