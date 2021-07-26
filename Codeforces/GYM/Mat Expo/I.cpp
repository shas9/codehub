// God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}


const ll msz = 201;
const ll mod = 1000000007;
struct matexpo
{
    ll mat[msz][msz];
    ll tmp[msz][msz];
    ll res[42][msz][msz];
    ll basemat[msz];

    ll cn = msz, rn = msz;

    void mult(ll p)
    {
		for(ll i = 0; i < rn; i++) for(ll j = 0; j < cn; j++) tmp[i][j] = res[p - 1][i][j];

        for(ll i = 0; i < rn; i++)
        {
            for(ll j = 0; j < cn; j++)
            {
                res[p][i][j] = 0;
                for(ll k = 0; k < cn; k++)
                {
                    res[p][i][j] = (res[p][i][j] + (tmp[i][k] * 1LL * tmp[k][j])) % mod;
                }
            }
        }
    }

    void expo()
    {
        for(ll i = 0; i < msz; i++)
        {
			for(ll j = 0; j < msz; j++) res[0][i][j] = mat[i][j];
        }

        for(ll now = 1; now <= 40; now++)
        {
			mult(now);
        }
    }

    void gun(ll p)
    {
		ll bse[msz];

		for(ll i = 0; i < msz; i++) bse[i] = basemat[i];

		for(ll i = 0; i < msz; i++)
		{
			basemat[i] = 0;

			for(ll j = 0; j < msz; j++)
			{
				basemat[i] = (basemat[i] + bse[j] * 1LL * res[p][j][i]) % mod;
			}
		}
    }
};


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    while(cin >> n >> m >> q)
    {
		matexpo me;

		for(ll i = 1; i <= m; i++)
		{
			ll u, v;

			slld(u);
			slld(v);

			me.mat[u][v] = 1;
		}

		me.expo();

		for(ll i = 1; i <= q; i++)
		{
			ll u, v, k;

			slld(u);
			slld(v);
			slld(k);

			memset(me.basemat, 0, sizeof me.basemat);

			me.basemat[u]++;

			for(ll i = 0; (1 << i) <= k; i++)
			{
				if(check(k, i))
				{
					me.gun(i);
				}
			}

			printf("%d\n", me.basemat[v]);

		}
    }


}



