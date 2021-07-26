// God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll int
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1 << pos);
}

vector < vector < ll > > v;
vector < ll > masksave;
map < ll, bool > av;
bool dp[(1 << 20)][2];
bool vis[(1 << 20)][2];
char grid[20];

ll flip(ll x)
{
	ll ret = 0;

	for(ll i = 0; i < 20; i++)
	{
		if(check(x,i) == 0) ret = Set(ret,i);
	}

	return ret;
}

bool solve(ll mask, ll node)
{
    if(vis[mask][node])
    {
        return dp[mask][node];
    }
    vis[mask][node] = 1;
    dp[mask][node] = 0;

    if(mask == 0)
    {
        return dp[mask][node];
    }


    for(auto it: masksave)
    {
        if((mask & it) == it)
        {
            ll smask = (~(~mask | it));

            if(solve(smask, node ^ 1) == 0) dp[mask][node] = 1;
        }
    }

    return dp[mask][node];
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    v.push_back({1,4,8});
    v.push_back({2,5,9,13});
    v.push_back({3,6,10,14,17});
    v.push_back({7,11,15,18});
    v.push_back({12,16,19});

    v.push_back({3,7,12});
    v.push_back({2,6,11,16});
    v.push_back({1,5,10,15,19});
    v.push_back({4,9,14,18});
    v.push_back({8,13,17});

    v.push_back({1,2,3});
    v.push_back({4,5,6,7});
    v.push_back({8,9,10,11,12});
    v.push_back({13,14,15,16});
    v.push_back({17,18,19});

    for(auto &it: v) for(auto &jt: it) jt--;

    for(ll i = 0; i < v.size(); i++)
    {
        for(ll j = 0; j < v[i].size(); j++)
        {
            ll mask = 0;

            for(ll k = j; k < v[i].size(); k++)
            {
                mask = Set(mask, v[i][k]);
                av[mask] = 1;
            }
        }
    }

    for(auto it: av) masksave.push_back(it.first);

    {
        for(ll i = 0; i < 19; i++) cin >> grid[i];

        memset(vis,0,sizeof vis);

        ll mask = 0;

        for(ll i = 0; i < 19; i++)
        {
            if(grid[i] == 'O') mask = Set(mask, i);
        }

        bool anss = solve(mask,0);

        if(anss) cout << "Karlsson\n";
        else cout << "Lillebror\n";
    }


}


