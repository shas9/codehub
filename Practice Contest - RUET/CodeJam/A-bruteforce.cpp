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

#define printcase(indexing,ans) printf("Case #%lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n)
{
    while(n > 0)
    {
        ll temp = n % 10;
        n /= 10;

        if(temp % 2 != 0)
        {
            return false;
        }
    }

    return true;
}
ll inc(ll n)
{
    ll cnt = 0;

    while(!check(n))
    {
        n++;
        cnt++;
    }

    //cout << cnt << endl;
    return n;
}

ll dec(ll n)
{
    ll cnt = 0;

    while(!check(n))
    {
        n--;
        cnt++;
    }

    //cout << cnt << endl;
    return n;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;
    freopen("in.txt", "r", stdin);
    freopen("outbrute.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;

        k = inc(n);
        l = dec(n);

        ll a = abs(n - k);
        ll b = abs(n - l);

        if(a < b)
        {
            cout << n << " " << k << " " << l << endl;
            ans = a;
        }
        else
        {
            cout << n << " " << l << " " << k << endl;
            ans = b;
        }

        printcase(cs,ans);
    }


}



