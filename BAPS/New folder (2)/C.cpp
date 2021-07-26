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

#define printcase(indexing,ans,ans2) printf("Case %lld: %lld/%lld\n", indexing, ans, ans2)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

ll x, l, n;

ll pow2[60];



ll bs1()
{
    ll i, j;

    ll ans =  0;

    for(i = 1; pow2[i] <= n; i++)
    {
        if(pow2[i] < x) continue;

        ans++;
    }

    ll temp = n - pow2[i - 1];

    temp *= 2;
    temp--;

    //cout << temp << endl;

    if(temp >= x)
        ans++;

    return ans;
}

ll bs2()
{
    ll i, j;

    ll ans =  0;

    for(i = 1; pow2[i] <= l; i++)
    {
        if(pow2[i] < x) continue;

        ans++;
    }

    ll temp = l - pow2[i - 1];

    temp *= 2;
    temp--;

    if(temp >= x)
        ans++;

    return ans;
}

ll bs()
{
    if(x % 2 == 0)
    {
        return max(0LL,x - l);
    }

    ll ans = 0;

    ans = max(0LL,x - l);

    l--;

    //cout << bs1() << " : " << bs2() << endl;

    ans += (bs1() - bs2());

    l++;

    return ans;
}

int main()
{
    ll i, j, k, m, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    pow2[0] = 1;

    for(i = 1; i <= 57; i++)
    {
        pow2[i] = pow2[i - 1] * 2;
    }

    for(i = 0; i <= 57; i++)
    {
        pow2[i]--;
    }

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(x);
        slld(l);
        slld(n);

        ans = bs();

        if(n == 1) ans = 1;

        if(ans == 0 || n == 1)
        {
            printcase(cs,ans,1LL);
            continue;
        }


        n -= (l);
        n++;



        ll gc = __gcd(ans,n);

        ans /= gc;
        n /= gc;

        printcase(cs,ans,n);
    }


}


