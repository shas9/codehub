// God put a smile upon your face <3

#include <bits/stdc++.h>

//#define slld(longvalue) scanf("%d", &longvalue)

#define ll long long
#define ull unsigned int
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

const ll msz = 65;
struct matexpo
{
    ull mat[msz][msz];
    ull tmp[msz][msz];
    ull res[msz][msz];

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

ll dirx[] = {2,2,-2,-2,1,1,-1,-1};
ll diry[] = {1,-1,1,-1,2,-2,2,-2};

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	for(auto it: {-2,-1,1,2})
//	for(auto jt: {-2,-1,1,2})
//	{
//		if(abs(it) != abs(jt))
//		{
//			cout << it << " " << jt << endl;
//
//			for(ll k = 0; k < 8; k++)
//			{
//				if(dirx[k] == it && diry[k] == jt)
//				{
//					cout << "FOUND\n";
//				}
//			}
//		}
//	}
    while(cin >> n)
    {
		n++;
		matexpo me;

		for(ll i = 0; i < 65; i++)for(ll j = 0; j < 65; j++) me.mat[i][j] = 0;

		for(ll i = 0; i < 8; i++)
		{
			for(ll j = 0; j < 8; j++)
			{
				for(ll k = 0; k < 8; k++)
				{
					ll nr = i + dirx[k];
					ll nc = j + diry[k];

					if(nr >= 8 || nr < 0) continue;
					if(nc >= 8 || nc < 0) continue;

//					cout << nr << " " << nc << endl;

					me.mat[i * 8 + j][nr * 8 + nc] = 1;
				}
			}
		}

		for(ll i = 0; i <= 64; i++) me.mat[i][64] = 1;

		me.expo(n);

		cout << me.res[0][64] << endl;
    }


}



