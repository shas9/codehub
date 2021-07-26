#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll int
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


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll pref[200005][28];
char str[200005];

bool solve(ll l, ll r)
{
    ll cnt = 0;

    for(ll i = 0; i < 26; i++)
    {
        ll x = pref[r][i] - pref[l - 1][i];

        if(x) cnt++;
    }

    return (cnt >= 3);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    scanf("%s", str);
    {
//        memset(pref,0,sizeof pref);

        n = strlen(str);
        for(i = 0; i < n; i++)
        {
            ll x = str[i] - 'a';

            pref[i + 1][x]++;
        }

        for(i = 0; i < 26; i++)
        {
            for(j = 1; j <= 200000; j++)
            {
                pref[j][i] += pref[j - 1][i];
            }
        }


        slld(q);

        for(i = 1; i <= q; i++)
        {
            slld(l);
            slld(r);

            if(r - l + 1 == 1) printf("YES\n");
            else if(str[l - 1] != str[r - 1]) printf("YES\n");
            else if(solve(l,r)) printf("YES\n");
            else printf("NO\n");
        }
    }


}


