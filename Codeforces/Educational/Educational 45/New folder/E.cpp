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

vector < ll > mon;
vector < ll > bike;

bool comp(ll x, ll y)
{
    return x > y;
}

ll solve(ll mid, ll pers)
{
    ll i, j, k, l;
    ll n = mon.size();
    ll m = bike.size();

    ll st = m - mid;

    ll tot = 0;
    ll flag = 0;
    for(i = 0, j = st; i < n && j < m; j++, i++)
    {
        if(mon[i] < bike[j])
        {
            tot += abs(mon[i] - bike[j]);
            flag += mon[i];
        }
        else
        {
            flag += bike[j];
        }
    }

    if(tot > pers) return -1;

    return max(flag - (pers - tot),0LL);
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    //freopen("in.txt", "r", stdin);

    ll pers;

    char c;
    while(scanf("%c", &c))
    {
        printf("%d", c);
    }

}


