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

ll csum[26][100005];
string s;

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        cin >> s;
        memset(csum,0,sizeof csum);

        for(ll i = 0; i < n; i++) csum[s[i] - 'a'][i + 1] = 1;

        for(ll i = 0; i < 26; i++) for(ll j = 1; j <= n; j++) csum[i][j] += csum[i][j - 1];

        for(ll i = 1; i <= m; i++)
        {
            ans = 0;

            cin >> l >> r;

            for(ll j = 0; j < 26; j++)
            {
                ll tot = csum[j][r] - csum[j][l - 1];

                ans += tot * (j + 1);
            }

            cout << ans << "\n";
        }
    }


}
