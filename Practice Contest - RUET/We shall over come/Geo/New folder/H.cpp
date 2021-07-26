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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//     freopen("in.txt", "r", stdin);
    slld(testcase);

    ll d, x, y;
    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(x);
        slld(y);
        slld(d);

        ans = -1;
        if(abs(x - y) % d == 0)
        {
            ans = abs(x- y) / d;
        }
        else
        {
            if(abs(n - y) % d == 0 && abs(1 - y) % d == 0)
            {
                ll ans1 = 0;
                ans1 += abs(1 - y) / d;
                flag = abs(1 - x) / d;

                if(abs(1 - x) % d) flag++;
                ans1 += flag;

                ll ans2 = 0;
                ans2 += abs(n - y) / d;
                flag = abs(n - x) / d;

                if(abs(n - x) % d) flag++;
                ans2 += flag;

                ans = min(ans1,ans2);
            }
            else if(abs(n - y) % d == 0)
            {
                ans = 0;
                ans += abs(n - y) / d;
                flag = abs(n - x) / d;

                if(abs(n - x) % d) flag++;
                ans += flag;
            }
            else if(abs(1 - y) % d == 0)
            {
                ans = 0;
                ans += abs(1 - y) / d;
                flag = abs(1 - x) / d;

                if(abs(1 - x) % d) flag++;
                ans += flag;
            }
        }

        printf("%lld\n", ans);
    }


}



