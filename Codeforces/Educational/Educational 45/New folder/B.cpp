#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define ull unsigned long long

#define maxn 1000006
using namespace std;

ull power[maxn];
ull table[maxn];

char s1[maxn], s2[maxn];

ull value;
ll cnt;

ull prime = 1657;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    power[1] = 1;

    for(i = 2; i < maxn; i++)
    {
        power[i] = power[i - 1] * prime;
    }

    for(ll cs = 1; cs <= testcase; cs++)
    {
        scanf("%s %s", s2 + 1, s1 + 1);

        ll len1 = strlen(s1 + 1);
        ll len2 = strlen(s2 + 1);

        for(i = 1; i <= len1; i++)
        {
            table[i] = (s1[i] - 'a') * power[i];

            table[i] += table[i - 1];
        }

        value = 0;
        cnt = 0;

        for(i = 1; i <= len2; i++)
        {
            value += (s2[i] - 'a') * power[i];
        }

        for(i = len2, j = 1; i <= len1; i++, j++)
        {
            if(value * power[j] == table[i] - table[i - len2])
            {
                cnt++;
            }
        }

        //printcase(cs,cnt);

        plld(cnt);
    }


}


