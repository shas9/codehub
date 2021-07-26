// God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld 3e18
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


const ll msz =101;
struct matexpo
{
    ll mat[msz][msz];
    ll tmp[msz][msz];
    ll res[msz][msz];

    ll cn = msz, rn = msz;

    void init()
    {
		for(ll i = 0; i < msz; i++)
		{
			for(ll j = 0; j < msz; j++)
			{
				mat[i][j] = mxlld;
			}
		}
    }

    void mult(ll p)
    {
        for(ll i = 0; i < rn; i++) for(ll j = 0; j < cn; j++) tmp[i][j] = res[i][j];

        for(ll i = 0; i < rn; i++)
        {
            for(ll j = 0; j < cn; j++)
            {
                res[i][j] = mxlld;

                for(ll k = 0; k < cn; k++)
                {
                    res[i][j] = min(res[i][j], (tmp[i][k] + tmp[k][j]));
                }
            }
        }

//        for(ll i = 0; i < msz && cout << endl; i++) for(ll j = 0; j < msz && cout << " ~ "; j++) cout << res[i][j];

        if(p & 1)
        {

            for(ll i = 0; i < rn; i++) for(ll j = 0; j < cn; j++) tmp[i][j] = res[i][j];
            for(ll i = 0; i < rn; i++)
            {
                for(ll j = 0; j < cn; j++)
                {
                    res[i][j] = mxlld;
                    for(ll k = 0; k < cn; k++)
                    {
                        res[i][j] = min(res[i][j], (mat[i][k] + tmp[k][j]));
                    }
                }
            }
        }
    }

    void expo(ll pwr)
    {
        if(pwr == 1)
        {
            for(ll i = 0; i < rn; i++)
            {
                for(ll j = 0; j < cn; j++)
                {
                    res[i][j] = mat[i][j]; // identity matrix
                }
            }

            return;
        }

        expo(pwr / 2);

        mult(pwr);

//        cout << endl << pwr << ": ";
//		for(ll i = 0; i < rn && printf("\n"); i++) for(ll j = 0; j < cn; j++) cout << res[i][j] << " ";
//		cout << endl;
    }
};


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
		matexpo me;

		me.init();


		for(ll i = 1; i <= m; i++)
		{
			ll u, v, c;

			slld(u);
			slld(v);
			slld(c);

			me.mat[u - 1][v - 1] = c;
		}

//		for(ll i = 0; i < n && cout << endl; i++) for(ll j = 0; j < n && cout << " "; j++) cout << me.mat[i][j];

		me.expo(k);

		ll mn = mxlld;

		for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) mn = min(mn, me.res[i][j]);

		if(mn > 1e18)
		{
			cout << "IMPOSSIBLE\n";
		}
		else cout << mn << "\n";
    }


}



