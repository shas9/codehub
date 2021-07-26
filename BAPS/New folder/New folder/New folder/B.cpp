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

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    ll a, b;
    ll oa, ob;
    for(ll cs = 1; cs <= testcase; cs++)
    {
        oa = ob = 0;

        cin >> a >> b;

        if(a == b)
        {
            cout << 0 << endl;
            continue;
        }

        for(i = 0; i <= 15; i++)
        {
            if(check(a,i))oa++;
            if(check(b,i))ob++;
        }

        if(b == 0 || b == 2)
        {
            cout << -1 << endl;
            continue;
        }

        ans = 0;

        if(oa > ob || ob > oa)
        {
            ans += abs(oa - ob);

            a = b;
            oa = ob;
        }

        if(oa == ob)
        {
            for(i = 0; i <= 15; i++)
            {
                if(check(b,i))
                {
                    cout << (1 << i - 1) << endl;
                    continue;
                }
            }
        }
    }


}

