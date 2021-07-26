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

string a, b;

bool solve()
{
    vector < ll > f(a.size());

    for(ll i = 0; i < a.size(); i++)
    {
        if(a[i] == '0') f[i] = 1;
        else f[i] = -1;

        if(i) f[i] += f[i - 1];
    }

    ll cnt = 0;

    for(ll i = b.size() - 1; i >= 0; i--)
    {
        if(cnt & 1)
        {
            if(a[i] == '1') a[i] = '0';
            else a[i] = '1';
        }

        if(b[i] != a[i])
        {
            if(f[i] != 0) return 0;
            cnt++;
        }
    }

    return 1;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> a >> b;

        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }


}

