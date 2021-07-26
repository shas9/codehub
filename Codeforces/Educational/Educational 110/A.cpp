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
        vector < ll > v1(2), v2(2);

        for(auto &it: v1) cin >> it;
        for(auto &it: v2) cin >> it;

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        if(v1.front() > v2.back() || v2.front() > v1.back())
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }


}

