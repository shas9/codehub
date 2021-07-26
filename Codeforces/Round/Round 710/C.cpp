 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

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

ll hsh[2][22][22];
const ll base = 1000068989;
const ll mod = 1000070879;

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> a >> b;

        ll n = a.size();
        ll m = b.size();

        ans = n + m;

        for(ll i = 0; i < n; i++)
        {
            ll hval = 0;

            for(ll j = i; j < n; j++)
            {
                hval = (hval * base) % mod;
                hval = (hval + (a[j] - 'a' + 1)) % mod;

                hsh[0][i][j] = hval;

            }
        }

        for(ll i = 0; i < m; i++)
        {
            ll hval = 0;

            for(ll j = i; j < m; j++)
            {
                hval = (hval * base) % mod;
                hval = (hval + (b[j] - 'a' + 1)) % mod;

                hsh[1][i][j] = hval;

            }
        }

        for(ll i = 0; i < n; i++)
        {
            for(ll j = i; j < n; j++)
            {
                for(ll ii = 0; ii < m; ii++)
                {
                    for(ll jj = ii; jj < m; jj++)
                    {
                        if(hsh[0][i][j] == hsh[1][ii][jj])
                        {
                            ll cost = i + (n - j - 1);
                            cost += (ii + (m - jj - 1));

                            ans = min(ans, cost);

//                            cout << i << " " << j << " " << ii << " " << jj << " " << hsh[0][i][j] << " " << cost << endl;
                        }
                    }
                }

            }
        }

        cout << ans << "\n";
    }


}

