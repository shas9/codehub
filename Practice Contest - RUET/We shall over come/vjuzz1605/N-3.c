#include <stdio.h>
#include <math.h>

long long int five(long long int num)
{
    long long int i = 1;

    long long int div;

    long long int count = 0;

    while(1)
    {
        div = (num / pow(5,i));

        count = count + div;

        i++;

        if(div == 0)
        {
            break;
        }

    }

    return count;
}

long long int two(long long int num)
{
    long long int count = 1;

    if(num % 2 != 0)
    {
        return 0;
    }

    while(1)
    {
        num = (num / 2);

        if((num == 0) || (num % 2 != 0))
        {
           break;
        }
        else
        {
            count++;
        }
    }
    return count;
}

long long int ftwo(long long int num)
{
    long long int i = 1;

    long long int div;

    long long int count = 0;

    while(1)
    {
        div = (num / pow(2,i));

        count = count + div;

        i++;

        if(div == 0)
        {
            break;
        }

    }

    return count;
}

long long int norfive(long long int num)
{
    long long int count = 1;

    if(num % 5 != 0)
    {
        return 0;
    }

    while(1)
    {
        num = (num / 5);

        if((num == 0) || (num % 5 != 0))
        {
           break;
        }
        else
        {
            count++;
        }
    }
    return count;
}

int main()
{
    long long int n, r, p, q;

    long long int faq_n, faq_r, faq_nr;

    long long int testcase;
    long long int i,j;
    long long int five1;
    long long int five2;
    long long int ans;

    long long int twof;
    long long int fivef;

    long long int twon, twor, twonr;

    scanf("%lld", &testcase);

    for(i = 1; i <= testcase; i++)
    {
    scanf("%lld%lld%lld%lld", &n, &r, &p, &q);

    faq_n = five(n);
    faq_r = five(r);
    faq_nr = five(n - r);

    five1 = (faq_n - (faq_r + faq_nr));

    five2 = norfive(p);

    five2 = five2 * q;

    faq_n = ftwo(n);
    faq_r = ftwo(r);
    faq_nr = ftwo(n - r);

    //printf("two of n= %lld, r = %lld, nr = %lld, p = %lld\n", faq_n, faq_r, faq_nr, two(p));

    twof = (faq_n - (faq_r + faq_nr)) + (two(p) * q);
    fivef = five1 + five2;

    //printf("DBUG\ntwo = %lld, fivef = %lld\nfaq_n = %lld, faq_r = %lld, faq_nr = %lld\n", twof,fivef,faq_n,faq_r,faq_nr);

    if(twof <= fivef)
    {
        ans = twof;
    }
    else
    {
        ans = fivef;
    }

    printf("Case %lld: %lld\n", i, ans);
    }

    return 0;

}
