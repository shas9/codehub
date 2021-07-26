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

    while(cin >> n >> m)
    {
        vector < ll > v(n);

        ll last = m;
        ans = 0;

        for(auto &it: v)
        {
            cin >> it;

            ll sum = last + it - m;

            if(sum < 0)
            {
                it -= sum;
                ans -= sum;
            }

            last = it;
        }

        cout << ans << "\n";

        for(auto it: v) cout << it << " ";

        cout << "\n";
    }


}

