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

ll mat[3][3];
ll res[3][3];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    for(ll i = 0; i < 3; i++) for(ll j = 0; j < 3; j++) cin >> mat[i][j];
    for(ll i = 0; i < 3; i++) res[i][i] = 1;

    for(ll i = 1; i <= 100; i++)
    {
		ll temp[3][3];

		for(ll j = 0; j < 3; j++) for(ll k = 0; k < 3; k++) temp[j][k] = res[j][k];
		memset(res,0,sizeof res);

		for(ll j = 0; j < 3; j++) for(ll k = 0; k < 3; k++) for(ll l = 0; l < 3; l++) res[j][l] += temp[j][k] * mat[k][l];

    }


		for(ll i = 0; i < 3; i++)
		{
			for(ll j = 0; j < 3; j++) cout << res[i][j] << " ";

			cout << endl;
		}


}


