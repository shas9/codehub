#include<stdio.h>

int main()
{
    long long int words, sentence;

    scanf("%lld%lld", &words, &sentence);

    char inword[words][20];
    char insent[2000g];

    int value[words];

    char dot;

    int i, j, k, l, m;

    long long int sum;

    int ln[words];

    int senln, flag = 0;

    for(i = 0; i < words; i++)
    {
        scanf("%s", inword[i]);
        scanf("%d", &value[i]);

        for(ln[i] = 0; inword[i][ln[i]] != '\0'; ln[i]++);
    }

    for(i = 0; i < sentence; i++)
    {
        scanf("%[^.]s", insent);

        printf("DBUG = %s\n", insent);

        for(senln = 0; insent[senln] != '\0'; senln++);

        sum = 0;

        for(j = 0; j < senln; j++)
        {
            //printf("----D");
            for(k = 0; k < words; k++)
            {
                //printf("-----DD");
                flag = 1;
                for(l = j; insent[l] != ' '; l++)
                {
                    if(inword[k][l] != insent[l])
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1)
                {
                    //printf("----t");
                    sum = sum + value[k];
                    break;
                    j = l;
                }
            }
        }

        printf("%lld\n", sum);
    }

    return 0;
}
