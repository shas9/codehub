// God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
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

const ll msz = 2;
struct matexpo
{
    double mat[msz][msz];
    double tmp[msz][msz];
    double res[msz][msz];

    ll cn = msz, rn = msz;

    void mult(ll p)
    {
		for(ll i = 0; i < rn; i++) for(ll j = 0; j < cn; j++) tmp[i][j] = res[i][j];

        for(ll i = 0; i < rn; i++)
        {
            for(ll j = 0; j < cn; j++)
            {
                res[i][j] = 0;
                for(ll k = 0; k < cn; k++)
                {
                    res[i][j] = (res[i][j] + (tmp[i][k] * tmp[k][j]));
                }
            }
        }

        if(p & 1)
        {
			for(ll i = 0; i < rn; i++) for(ll j = 0; j < cn; j++) tmp[i][j] = res[i][j];
            for(ll i = 0; i < rn; i++)
            {
                for(ll j = 0; j < cn; j++)
                {
                    res[i][j] = 0;
                    for(ll k = 0; k < cn; k++)
                    {
                        res[i][j] = (res[i][j] + (mat[i][k] * tmp[k][j]));
                    }
                }
            }
        }
    }

    void expo(ll pwr)
    {
        if(pwr == 0)
        {
            for(ll i = 0; i < rn; i++)
            {
                for(ll j = 0; j < cn; j++)
                {
					res[i][j] = (i == j); // identity matrix
                }
            }

            return;
        }

        expo(pwr / 2);

        mult(pwr);
    }
};

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	double p;

    while(cin >> n >> p)
    {
		matexpo me;

		for(ll i = 0; i < 2; i++)
		{
			for(ll j = 0; j < 2; j++)
			{
				if(i == j) me.mat[i][j] = (1 - p);
				else me.mat[i][j] = p;
			}
		}

		me.expo(n);

		printf("%.10f\n", me.res[0][0]);
    }


}



