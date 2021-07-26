// God put a smile upon your face <3

#include <bits/stdc++.h>`

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

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll mat[55][55];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		slld(m);

		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= m; j++) slld(mat[i][j]);
		}

		ll cnt = 0;

		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= m; j++)
			{
				bool ase = 1;

				for(k = 1; k <= m; k++)
				{
					if(mat[i][k]) ase = 0;
				}

				if(ase == 0) continue;

				for(k = 1; k <= n; k++)
				{
					if(mat[k][j]) ase = 0;
				}

				if(ase == 0) continue;

				cnt++;
				mat[i][j] = 1;
			}
		}

		if(cnt & 1) printf("Ashish\n");
		else printf("Vivek\n");
    }


}


