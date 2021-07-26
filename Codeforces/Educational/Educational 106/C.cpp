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
        cin >> n;

        ll ans1 = mxlld;
        ll ans2 = mxlld;
        ll ans = mxlld;
        ll t1 = 0;
        ll t2 = 0;
        ll c1 = 0;
        ll c2 = 0;
        ll mn1 = mxlld;
        ll mn2 = mxlld;

        for(ll i = 1; i <= n; i++)
        {
            cin >> in;

            if(i & 1)
            {
                t1 += in;
                c1++;
                mn1 = min(mn1, in);

                ans1 = t1 + (n - c1) * mn1;
            }
            else
            {
                t2 += in;
                c2++;
                mn2 = min(mn2, in);

                ans2 = t2 + (n - c2) * mn2;
            }

            if(i != 1) ans = min(ans, ans1 + ans2);
        }

        cout << ans << "\n";
    }


}


