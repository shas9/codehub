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

vector < ll > a, b;

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        a.resize(n);
        b.resize(n);

        for(auto &it: a) cin >> it;
        for(auto &it: b) cin >> it;

        ans = mxlld;

        for(ll i = 0; i < n; i++)
        {
            for(ll j = i + 1; j < n; j++)
            {
                ll sum = 0;

                for(ll k = 0; k < n; k++)
                {
                    if(k != i && k != j)
                    {
                        sum += abs(a[k] - b[k]);
                    }
                }

                sum += abs(a[i] - b[j]);
                sum += abs(a[j] - b[i]);

                ans = min(ans, sum);
            }
        }

        cout << ans << "\n";
    }


}

