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

ll anns[500005];

void brute()
{

    ll mn = mxlld;
    for(ll i = 1; i <= 50; i++)
    {
        ll mx = 0;
        for(ll j = 1; j <= 50; j++)
        {
            for(ll k = 1; k <= 50; k++)
            {
                if(j == k || j == i || k == i) continue;

                mx = max(mx, __gcd(j,k));

                if(__gcd(j,k) == 24)
                {
                    cout << j << " " << k << endl;
                }
            }
        }

        mn = min(mn,mx);


    }

    cout << mn << endl;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    brute();
    while(cin >> n)
    {
        for(i = n, j = 2; i >= 2; i--, j++)
        {
            anns[i] = n / j;
        }

        for(i = 2; i <= n; i++)
        {
            cout << anns[i] << " ";
        }

        cout << "\n";
    }

}

