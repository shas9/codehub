 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

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

ll arr[103];

bool asc(ll n, ll x, ll y)
{
    ll last = mxlld;

    for(ll i = 1; i <= n; i++)
    {
        if(i == x) continue;
        if(i == y) continue;

        if(last < arr[i]) return 0;

        last = arr[i];
    }

    return 1;
}

bool dsc(ll n, ll x, ll y)
{
    ll last = mnlld;

    for(ll i = 1; i <= n; i++)
    {
        if(i == x) continue;
        if(i == y) continue;

        if(last > arr[i]) return 0;

        last = arr[i];
    }

    return 1;
}

bool solve(ll n)
{
    if(asc(n,n + 1, n + 1)) return 1;
    if(dsc(n,n + 1, n + 1)) return 1;
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = i + 1; j <= n; j++)
        {
            if(asc(n,i,j)) return 1;
            if(dsc(n,i,j)) return 1;
        }
    }

    return 0;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        for(ll i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        if(solve(n)) cout << "Yes\n";
        else cout << "No\n";
    }


}

