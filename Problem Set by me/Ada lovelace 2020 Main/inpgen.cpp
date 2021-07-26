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
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

void gen()
{
    ll t = rand() % 11;

    if(t == 0) t++;

    t = 100;
    cout << t << endl;

    for(ll i = 1; i <= t; i++)
    {
        ll n = rand() % 100001;

        if(n == 0) n++;

        n = 100000;

        cout << n << endl;

        for(ll j = 1; j <= n; j++)
        {
            ll x = rand() % 10001;
            ll y = rand() % 10001;
            ll z = rand() % 10001;

            if(x == 0) x++;
            if(y == 0) y++;
            if(z == 0) z++;

            x = y = z = 10000;
            cout << x << " " << y << " " << z << endl;
        }
    }
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    freopen("input.txt", "w", stdout);

//    freopen("output.txt", "w", stdout);

    srand (time(NULL));
        gen();



}

