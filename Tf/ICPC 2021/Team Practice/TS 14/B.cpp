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

vector < ll > v1, v2;

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
        v1.clear();
        v2.clear();

        cin >> n >> k;

        v1.resize(n);
        v2.resize(n);

        for(auto &it: v1) cin >> it;
        for(auto &it: v2) cin >> it;

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());


        ll ans = 0;

        for(ll i = 0, j = n - 1; i < n && j >= 0; i++)
        {
            if(v1[i] + v2[j] >= k)
            {
                ans++;
                j--;
            }
        }

        cout << ans << "\n";
    }


}

