#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


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

//    freopen("output.txt", "w", stdout);

    ll cnt = 0;
    for(i = 1; i <= 100000000; i++)
    {
        ll prv = -1;

        ll tmp = i;
        bool ok = 1;

        while(tmp)
        {
            ll x = tmp % 10;

            tmp /= 10;
            if(prv == -1)
            {
                prv = x;
                continue;
            }

            if(abs(prv - x) > 1)
            {
                ok = 0;
                break;
            }

            prv = x;
        }

        if(ok) cnt++;

        if(i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000 || i == 10000000 || i == 100000000)
        {
            cout << i << " " << cnt << endl;
        }
    }


}

