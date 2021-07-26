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

void brute(ll n)
{
    ll a = 1, b = n;
    for(ll i =1; i <= n; i++)
    {
        for(ll j = 1; j <= n; j++)
        {
            ll lcm = (i * j) / __gcd(i,j);

            if(lcm == n)
            {
                if(max(a,b) > max(i,j))
                {
                    a = i;
                    b = j;
                }
            }
        }
    }

    cout << a << " " << b << endl;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        l = 1;
        r = n;

        for(i = 1; i * i <= n; i++)
        {
            if(n % i) continue;

            ll x = i;
            ll y = n / i;

            if(__gcd(x,y) != 1) continue;

            if(max(x,y) < max(l,r))
            {
                l = x;
                r = y;
            }
        }

        cout << l << " " << r << endl;

//        brute(n);
    }


}



