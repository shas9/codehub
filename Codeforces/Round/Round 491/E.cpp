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
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

string num;

ll cnt[15];
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    memset(cnt,0,sizeof cnt);

    cin >> num;

    ll sz = num.size();

    bool zero = 0;
    for(i = 0; i < sz; i++)
    {
        ll id = num[i] - '0';

        if(id == 0) zero = 1;

        cnt[id]++;
    }

    ll dist = 0;

    for(i = 0; i <= 9; i++)
    {
        if(cnt[i]) dist++;
    }

    ans = 1;

    if(zero)
    {
        for(i = 1 i <= dist - 1; i++) ans *= i;

        ans *= dist - 1;
    }
    else
    {
        for(i = 1; i <= dist; i++) ans *= i;
    }




}


