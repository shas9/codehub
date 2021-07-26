#include <stdio.h>

int main()
{
    int team;

    scanf("%d", &team);

    int id[team];
    int solved[team];

    int max;

    int i,j,k,l;

    for(i = 0; i < team; i++)
    {
        scanf("%d", &id[i]);
        scanf("%d", &solved[i]);
    }

    max = solved[0];

    for(i = 1; i < team; i++)
    {
        if(max < solved[i])
        {
            max = solved[i];
        }
    }

    for(i = max; i >= 0; i--)
    {
        for(j = 0; j < team; j++)
        {
            if(solved[j] == i)
            {
                printf("%d %d\n", id[j],solved[j]);
            }
        }
    }

    return 0;
}
