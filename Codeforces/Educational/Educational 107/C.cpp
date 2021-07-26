 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll mn[55];

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        memset(mn, -1,sizeof mn);

        for(ll i = 1; i <= n; i++)
        {
            cin >> in;

            if(mn[in] == -1) mn[in] = i;
        }

        for(ll i = 1; i <= m; i++)
        {
            cin >> in;

            cout << mn[in] << " ";

            for(ll j = 1; j <= 50; j++)
            {
                if(mn[j] != -1 && mn[j] < mn[in]) mn[j]++;
            }

            mn[in] = 1;
        }

        cout << '\n';
    }


}


