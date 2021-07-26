#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

typedef long double ld;

ld a[105][105][105];

int main()
{
    int R, S, P;

    freopen("input.txt", "r", stdin);

    cin >> R >> S >> P;

    a[R][S][P] = 1;
    for (int p = P; p >= 0; p--)
    {
        for (int s = S; s >= 0; s--)
        {
            for (int r = R; r >= 0; r--)
            {
                if (r == 0 && s == 0) continue;
                if (r == 0 && p == 0) continue;
                if (s == 0 && p == 0) continue;
                ld cur = a[r][s][p];
                int waysR = r * s;
                int waysS = s * p;
                int waysP = p * r;
                int totalWays = waysR + waysS + waysP;
                if (r > 0) a[r - 1][s][p] += cur * waysP / totalWays;
                if (s > 0) a[r][s - 1][p] += cur * waysR / totalWays;
                if (p > 0) a[r][s][p - 1] += cur * waysS / totalWays;
            }
        }
    }

     for(int pp = P; pp >= 0; pp--)
    {
        for(int ss = S; ss >= 0; ss--)
        {
            for(int rr = R; rr >= 0; rr--)
            {
                cout << a[rr][ss][pp] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    ld ansR = 0;
    ld ansS = 0;
    ld ansP = 0;
    for (int r = 1; r <= R; r++) ansR += a[r][0][0];
    for (int s = 1; s <= S; s++) ansS += a[0][s][0];
    for (int p = 1; p <= P; p++) ansP += a[0][0][p];

    printf("%.12f %.12f %.12f\n", (double)ansR, (double)ansS, (double)ansP);
}
