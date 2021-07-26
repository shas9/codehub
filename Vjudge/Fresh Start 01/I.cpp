// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

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

map < ll, ll > mp;
vector < ll > v;

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    ll now = 8;
    v.push_back(now);
    mp[now] = 1;

    while(1)
    {
        now *= 1378;
        now %= 10;

        if(mp[now]) break;

        v.push_back(now);
    }

    while(cin >> n)
    {
        if(n == 0)
        {
            cout << 1 << "\n";
            continue;
        }

        ll idx = (n - 1) % v.size();

        cout << v[idx] << "\n";
    }


}

