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

ll cnt = 0;


ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;   // Update x if it is more than or
                // equal to p

    cnt = 0;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x);

            if(res >= p)
            {
                res %= p;
                cnt++;
            }

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x);

        if(x >= p)
        {
            x %= p;
            cnt++;
        }
    }
    return res;
}

int main()
{
    ll i, j, k, l, m, n;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);


    pair < ll, ll > o, p;
    ll x, y;

    cin >> x>> y;

    //cout << power(x,y,mod) << " " << power(y,x,mod) << endl;

    o.first = power(x,y,mod);
    o.second = cnt;
    p.first = power(y,x,mod);
    p.second = cnt;

    cout << o.first << " " << o.second << endl;
    cout << p.first << " " << p.second << endl;

    if(o.second > p.second)
    {
        cout << ">" << endl;
        return 0;
    }

    if(o.second < p.second)
    {
        cout << "<" << endl;
        return 0;
    }

    if(o.first > p.first)
    {
        cout << ">" << endl;
        return 0;
    }

    if(o.first < p.first)
    {
        cout << "<" << endl;
        return 0;
    }

    cout << "=" << endl;


}


