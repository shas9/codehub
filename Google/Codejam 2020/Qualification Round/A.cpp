#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

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

ll arr[100][100];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
                slld(arr[i][j]);
        }

        ll trace = 0, rr = 0, cc = 0;

        for(i = 1; i <= n; i++) trace += arr[i][i];

        for(i = 1; i <= n; i++)
        {
            map < ll, ll > mp;

            for(j = 1; j <= n; j++)
            {
                if(mp.find(arr[i][j]) != mp.end())
                {
                    rr++;
                    break;
                }

                mp[arr[i][j]] = 1;
            }
        }

        for(i = 1; i <= n; i++)
        {
            map < ll, ll > mp;

            for(j = 1; j <= n; j++)
            {
                if(mp.find(arr[j][i]) != mp.end())
                {
                    cc++;
                    break;
                }

                mp[arr[j][i]] = 1;
            }
        }

        printf("Case #%lld: %lld %lld %lld\n", cs, trace, rr, cc);


    }


}


