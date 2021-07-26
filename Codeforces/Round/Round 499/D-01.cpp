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

bool seq[55];

ll ask(ll num)
{
    plld(num);

    fflush(stdout);

    ll x;

    slld(x);

    return x;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(m);
    slld(n);

    for(i = 1; i <= n; i++)
    {
        input = ask(m + 1);

        if(input) seq[i] = 0;
        else seq[i] = 1;
    }

    ll low = 1;
    ll high = m;

    i = 1;

    while(low <= high)
    {
        ll mid = (low + high) / 2;
        i %= n;

        if(i == 0) i = n;

        flag = ask(mid);

        if(flag == 0) exit(0);
        if(flag == -2) exit(0);

        if(!seq[i]) flag *= -1;

        if(flag == -1)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }

    }


}
