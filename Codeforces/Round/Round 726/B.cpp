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
        ll x, y;

        cin >> n >> m >> x >> y;

        ll dx[] = {n,n,1,1};
        ll dy[] = {1,m,1,m};

        ll x1, x2, y1, y2;
        ll d = mnlld;

        for(ll i = 0; i < 4; i++)
        {
            for(ll j = 0; j < 4; j++)
            {
                for(ll k = 0; k < 4; k++)
                {
                    for(ll l = 0; l < 4; l++)
                    {
                        ll dd = abs(x - dx[i]) + abs(x - dx[k]) + abs(y - dy[j]) + abs(y - dy[l]);
                        dd += abs(dx[i] - dx[k]) + abs(dy[j] - dy[l]);

                        if(dd > d)
                        {
                            x1 = dx[i];
                            x2 = dx[k];
                            y1 = dy[j];
                            y2 = dy[l];

                            d = dd;
                        }
                    }
                }
            }
        }

        cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
    }


}


