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

ll mat[101][2][2];

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
        cin >> n >> m;

        bool on = 0;

        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 0; j < 2; j++)
            {
                for(ll k = 0; k < 2; k++)
                {
                    cin >> mat[i][j][k];
                }
            }

            if(mat[i][1][0] == mat[i][0][1]) on = 1;
        }

        if(m & 1) on = 0;

        if(on) cout << "YES\n";
        else cout << "NO\n";
    }


}

