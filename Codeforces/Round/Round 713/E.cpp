// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n")
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

vector < ll > v, perp;
map < ll, ll > mark;
ll l, m, n, r;

void solve()
{
    v.clear();
    mark.clear();
    perp.clear();
    ll sum = 0;

    for(ll i = 1; i <= (r - l + 1); i++)
    {
        v.push_back(i);
        sum += i;
        mark[i] = 1;
    }

    if(sum > m)
    {
        perp = {-1};
        return;
    }

    ll now = n;
    ll sz = v.size();

    for(ll i = sz - 1; i >= 0; i--)
    {
        ll diff = (m - sum);
        if(diff == 0) break;

        ll mn = min(now - v[i], diff);
        sum += mn;

        mark[v[i]] = 0;

        v[i] += mn;
        mark[v[i]] = 1;
        now--;
    }

    if(sum != m)
    {
        perp = {-1};
        return;
    }

    ll ptr = 1;

    for(ll i = 1; i < l; i++)
    {
        while(mark[ptr]) ptr++;

        perp.push_back(ptr);

        ptr++;
    }

    for(auto it: v) perp.push_back(it);

    for(ll i = r + 1; i <= n; i++)
    {
        while(mark[ptr]) ptr++;

        perp.push_back(ptr);

        ptr++;
    }

    return;
}
int main()
{
    ll i, j, k, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> l >> r >> m;

        solve();

        for(auto it: perp)
        {
            cout << it << " ";
        }

        cout << "\n";
    }


}

