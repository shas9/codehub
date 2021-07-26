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
        cin >> n >> m >> k;

        string s;

        cin >> s;

        ans = (m * n);

        if(k >= 0) ans += (k * n);
        else
        {
            ll z = 0;
            ll o = 0;

            if(s.front() == '1') o++;
            else z++;

            for(ll i = 1; i < n; i++)
            {
                if(s[i] != s[i - 1])
                {
                    if(s[i] == '1') o++;
                    else z++;
                }
            }

            ans += (k * (min(o,z) + 1));
        }

        cout << ans << "\n";
    }


}

