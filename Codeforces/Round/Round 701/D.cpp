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

vector < ll > vec;
ll mat[505][505];
ll ans[505][505];

void test()
{
	for(ll a = 1; a <= 16; a++)
	{
		for(ll b = 1; b <= 16; b++)
		{
			bool on = 0;
			for(ll i = 1; i <= 100000; i++)
			{
				ll x = a * i;

				for(ll k = 1; k <= 10; k++)
				{
					ll y = k * k * k * k + x;

					if(y % b == 0 && y <= 1000000 && x <= 1000000) on = 1;

					y = k * k * k * k - x;

					if(y % b == 0 && y > 0 && y <= 1000000 && x <= 1000000) on = 1;
				}
			}

			if(on == 0) cout << a << " " << b << endl;
		}
	}
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	test();

	vec.clear();

	for(ll i = 1; i <= 32; i++)
	{
		vec.push_back(i * i * i * i);
	}

	while(cin >> n >> m)
	{
		memset(ans,0,sizeof ans);
		for(ll i = 1; i <= n; i++) for(ll j = 1; j <= m; j++) cin >> mat[i][j];

		ll num = 720720;

		for(ll i = 1; i <= n; ++i)
		{
			for(ll j = 1; j <= m; j++)
			{
				if((i + j) & 1) cout << num << " ";
				else cout << num - vec[mat[i][j] - 1] << " ";
			}

			cout << "\n";
		}



	}



}


