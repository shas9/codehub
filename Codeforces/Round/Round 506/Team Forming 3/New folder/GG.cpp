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

    ll mm = 1000000000;

    slld(n);

    ll a = 1, b = 1;

    bool on1 = 0, on2 = 0;
    for(i = 1; i <= n; i++)
    {
        slld(input);

        a *= input;

        if(a > mm)
        a %= mm, on1 = 1;
    }

    slld(m);

    for(i = 1; i <= m; i++)
    {
        slld(input);

        b *= input;

        if(b > mm)
        b %= mm, on2 = 1;
    }

    ans = __gcd(a,b);
    string xx = "";

    while(ans > 0)
    {
        ll id = ans % 10;

        xx += id + '0';

        ans /= 10;
    }

    reverse(xx.begin(),xx.end());

    if(on1 == 0 && on2 == 0) cout << xx << endl;
    else
    {
        ll sz = xx.size();

        ll temp = 10 - sz;

        for(i = 1; i < temp; i++)
        {
            cout << 0;
        }

        if(xx.size())
        cout << xx;

        cout << endl;
    }


}




