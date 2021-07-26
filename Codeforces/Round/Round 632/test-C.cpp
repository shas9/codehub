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

ll csum[200005];
map < ll, ll > mp;
map < ll, ll > lastst, lasten;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        for(i = 1; i <= n; i++)
        {
            slld(csum[i]);

            csum[i] += csum[i - 1];
        }

        mp.clear();

        ans = (n * (n + 1)) / 2;

        ll last = n + 1;

        for(i = n; i >= 1; i--)
        {
            ll val = csum[i] - csum[i - 1];

            ll tmp = csum[i] - val;

            if(mp[tmp] != 0)
            {
                ll j = max(0LL,(last - mp[tmp]));

//                cout << i << " " << j << endl;

                ans -= (i * j);

//                cout << ans << endl;

                last = mp[tmp];
            }

            mp[csum[i]] = i;
        }


        cout << ans << endl;
    }


}



