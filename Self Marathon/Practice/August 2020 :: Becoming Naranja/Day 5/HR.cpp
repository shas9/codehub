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

ll mat[3][3][3];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    for(ll i = 0; i < 2; i++) for(ll j = 0;j < 3; j++) for(ll k = 0; k < 3; k++) cin >> mat[i][j][k];
    for(ll i = 0; i < 3; i++) for(ll j = 0;j < 3; j++) for(ll k = 0; k < 3; k++) mat[2][i][j] += mat[0][i][k] * mat[1][k][j];
    for(ll i = 0; i < 3; i++) for(ll j = 0;j < 3 && cout << endl; j++) cout << mat[2][i][j];




}


