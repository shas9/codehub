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


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

map < ll, ll > mp;
ll arr[100005];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(k);
        ll mn = mxlld;
        ll mx = mnlld;
        ll t, x, y;

        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);

            mp[arr[i]] = 0;

            mn = min(mn,arr[i]);
            mx = max(mx,arr[i]);
        }

        for(i = 1; i <= k; i++)
        {
            slld(t);
            slld(x);
            slld(y);

            if(t == 1)
            {
                mp[mn] -= y;
                mp[x + 1] += y;
            }
            else
            {
                mp[x] += y;
                mp[mx] -= y;
            }
        }

        map < ll, ll > :: iterator it;

        ll prev = 0;

        for(it = mp.begin(); it != mp.end(); it++)
        {
            ll ind = it -> first;

            prev += it -> second;

            mp[ind] = prev;
        }

        for(i = 1; i <= n; i++)
        {
            input = arr[i];

            input += mp[input];

            printf("%lld", input);

            if(i != n)
            {
                printf(" ");
            }
        }

        printf("\n");
    }


}


