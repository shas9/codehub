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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

    freopen("input.txt", "w", stdout);

    cout << 100000 <<endl;

    for(ll i = 1; i <= 100000; i++) cout << i - 1 << " ";

    cout << endl;

    cout << 100000 << endl;

    for(ll i = 1; i <= 100000; i++)
    {
		cout << rand() % 100000 + 1 << " " << rand() % 100000 + 1 << endl;
    }


}


