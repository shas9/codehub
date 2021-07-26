#include <stdio.h>

int main()
{
    int n,r,p,q

    scanf("%d%d%d%d", &n, &r, &p, &q);

    long long int faq_n[n + 1];
    long long int faq_r[r + 1];
    long long int faq_nr[n - r + 1];

    int i,j,k;

    for(i = 1; i <= n; i++)
    {
        faq_n[i] = i;
    }
    for(i = 1; i <= r; i++)
    {
        faq_r[i] = i;
    }
}
