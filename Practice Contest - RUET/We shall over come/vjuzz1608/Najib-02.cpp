#include <stdio.h>
#include <string.h>

int compare(char s1[], char s2[])
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int limit;

    if(len1 < len2)
    {
        limit = len1;
    }
    else
    {
        limit = len2;
    }

    for(int i = 0; i < limit; i++)
    {
        if(s1[i] <= s2[i])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    char s1[100], s2[100];

    scanf("%s %s", s1, s2);

    int ans = compare(s1,s2);

    printf("%d\n", ans);
}
