#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

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
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> n)
    {
        ll a = 0, b = 0;

        for(i = 1; i <= n; i++)
        {
            slld(input);

            a = __gcd(a,input);
        }

        slld(m);

        for(i = 1; i <= m; i++)
        {
            slld(input);

            b = __gcd(b,input);
        }

        ans = a * b;

        string x = "";

        while(ans > 0)
        {
            ll id = ans % 10;

            x += id + '0';

            ans /= 10;
        }

        reverse(x.begin(),x.end());

        ll sz = x.size();

        for(i = max(0LL, sz - 9); i < sz; i++) cout << x[i];

        cout << endl;
    }


}



