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

void brute()
{
	ll n;

	cin >> n;

	ll a[n][n];

	for(ll i = 0; i < n; i++)
	{
		for(ll j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	ll mn = n * n;

	for(ll i = 0; i < n; i++)
	{
		for(ll j = 0; j < n; j++)
		{
			if(i == j) continue;
			ll cnt = 0;

			for(ll k = 0; k < n; k++)
			{
				for(ll l = 0; l < n; l++)
				{
					if(a[i][k] > a[j][l]) cnt++;
				}
			}

//			cout << i << " " << j << " " << cnt << endl;

			mn = min(mn,cnt);
		}
	}

	cout << mn << endl;

}

ll mat[305][305];
ll ans[305][305];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	while(1) brute();

    slld(n);

    ll idx = 1;

    for(i = 1; i <= n; i++)
    {
		for(j = 1; j <= n; j++)
		{
			mat[i][j] = idx++;
		}
    }

    for(i = 1; i <= n / 2; i++)
    {
		for(j = 1; j <= n; j++)
		{
			if(j % 2) ans[i][j] = mat[j][i];
			else ans[i][j] = mat[j][n - i + 1];

			if(j % 2) ans[n - i + 1][j] = mat[j][n - i + 1];
			else ans[n - i + 1][j] = mat[j][i];
		}
    }


    if(n % 2)
    {
		for(i = 1; i <= n; i++)
		{
			ans[n / 2 + 1][i]= mat[i][n / 2 + 1];
		}
    }

    for(i = 1; i <= n; i++)
    {
		for(j = 1; j <= n; j++)
		{
			printf("%lld ", ans[i][j]);
		}

		printf("\n");
    }


}


