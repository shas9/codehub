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

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000007


using namespace std;

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

ll modinverse(ll a, ll m)
{
    return power(a,m-2,m);
}
vector < ll > v;

ll fact[100005];

int main()
{
    ll i, j, k, l, m, n, o,a,b;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    ll x, y;
    fact[0]=1;
    fact[1] = 1;
    for(i = 2; i <= 100000; i++)
    {
        fact[i] = i * fact[i - 1];
        fact[i] %= mod;
    }

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);

        v.clear();


        for(i = 1; i <= n; i++)
        {
            slld(x);
            slld(y);

            if(y == 1) v.push_back(x);
        }

        if(v.size() < m)
        {
            cout << 0 << endl;
            continue;
        }

        sort(v.begin(),v.end());
        ll len,tanu;
        len=v.size();
        for(i=len-m,tanu=v[len-m],a=0;i<len&&v[i]==tanu;i++,a++);
        //cout<<a<<endl;
        for(i=len-m-1,b=0;i>=0&&v[i]==tanu;i--,b++);
        //cout<<b<<endl;
        tanu=a+b;
        ll sum;

        sum=fact[tanu]%mod;;
        tanu=modinverse(fact[a],mod);
        sum=(sum*(tanu%mod))%mod;
        tanu=modinverse(fact[b],mod);

        sum=(sum*(tanu%mod))%mod;
        printf("%lld\n",sum);

    }


}


