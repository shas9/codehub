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

ll concat(ll a, ll b)
{
//    cout << a << " " << b << " ";

    ll sz = 0;
    ll tmp = b;

    while(tmp)
    {
        sz++;
        tmp /= 10;
    }

    for(ll i = 1; i <= sz; i++)
    {
        a *= 10;
    }

//    cout << a + b << endl;

    return a + b;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    for(i = 1; i <= 1000; i++)
    {
        for(j = 1; j <= 1000; j++)
        {
            ll a = i;
            ll b = j;

            if(concat(a,b) == (a*b + a + b))
            {
                cout << a << " " << b << endl;
            }
        }
    }


}



