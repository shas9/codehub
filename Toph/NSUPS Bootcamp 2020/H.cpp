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

char grid[505][505];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(m);

    for(i = 1; i <= n; i++) scanf("%s", grid[i] + 1);

    ans = 0;

    for(i = 1; i <= n; i++)
    {
		for(j = 1; j <= m; j++)
		{
			if(grid[i][j] != '=') continue;

			for(k = i - 1; k >= 1; k--)
			{
//				cout << grid[k][j] << " ";

				if(grid[k][j] == 'O') ans++;
			}
		}
    }

    cout << ans << '\n';


}



