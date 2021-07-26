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

vector < pll > v;

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        v.resize(n);

        for(auto &it: v) cin >> it.first >> it.second;

        ll cnt1 = 0, cnt2 = 0;

        for(ll i = 1; i < n; i++)
        {
            if(v[i].first <= v.front().first) cnt1++;
        }

        for(ll i = 1; i < n; i++)
        {
            if(v[i].second <= v.front().second) cnt2++;
        }
    }


}

