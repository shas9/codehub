#include <stdio.h>
#include <math.h>

int main()
{
    int testcase;
    long long int sec, ssq, sq1, range1, range2, mp, row, col;
    double sq;

    int i;

    scanf("%d", &testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanf("%lld", &sec);

        sq = sqrt(sec);

        ssq = sq;

        //printf("sq = %lf\n", sq);

        sq1 = sq;

        sq = (sq - sq1) * 1000;

        sq1 = sq;



        if(sq1 > 0)
        {
            ssq = ssq + 1;
        }

        //printf("ssq = %lld\n", ssq);

        range1 = ((ssq - 1) * (ssq - 1)) + 1;
        range2 = ssq * ssq;

        mp = (range2 + range1) / 2;

        if(ssq % 2 == 0)
        {
            if(sec < mp)
            {
                row = ssq;

                col = sec - mp + ssq;
            }
            else if(sec == mp)
            {
                row = ssq;
                col = ssq;
            }
            else if(sec > mp)
            {
                col = ssq;
                row = mp + ssq - sec;
            }
        }
        else if(ssq % 2 != 0)
        {
            if(sec < mp)
            {
                col = ssq;

                row = sec + ssq - mp;
            }
            else if(sec == mp)
            {
                row = ssq;
                col = ssq;
            }
            else if(sec > mp)
            {
                row = ssq;
                col = mp + ssq - sec;
            }
        }

        printf("Case %d: %lld %lld\n", i, col, row);

    }
    return 0;
}
