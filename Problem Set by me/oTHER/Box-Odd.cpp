#include <bits/stdc++.h>

#define pi 3.14159265359

using namespace std;

int main()
{
    int i, testcase;

    double a, r, area, n;

    cin >> testcase;

    for(int cs = 1; cs <= testcase; cs++)
    {
        cin >> n;

        a = sqrt(n);

        r = a / 2;

        area = pi * r * r;

        // Or you can directly write area = pi * n / 4;

        printf("Case %d: %lf\n", cs, area);
    }

    return 0;
}


