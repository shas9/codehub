#include <bits/stdc++.h>

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld", longvalue)
#define printnewline printf("\n")
#define ll long long

using namespace std;

int main()
{

    ll int i, j, k, l, m;
    ll int testcase;
    ll int size;
    ll int ans;
    ll int MOD = 1000000007;
    ll int b;

    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        ans = 1;

        scanlld(size);

        for(j = 0; j < size; j++)
        {
            scanlld(b);

            ans = (((ans % MOD) * (b % MOD)) % MOD);
        }

        printlld(ans);
        printnewline;
    }

    return 0;
}


