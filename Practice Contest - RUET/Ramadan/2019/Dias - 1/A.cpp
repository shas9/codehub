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

vector < ll > div__[100];

ll cnt[100];

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

void precalc()
{
    memset(cnt,0,sizeof cnt);

    for(ll i = 1; i <= 90; i++)
        for(ll j = 1; j < i; j++)
            if(i % j == 0)
                div__[i].push_back(j);

    return;
}

ll len_calc(ll x)
{
    for(ll i = 63; i >= 0; i--)
    {
        if(check(x,i)) return i + 1;
    }
}

ll sub_len(ll n,ll len,ll x)
{
    ll ret = 0;

    for(ll i = len - 1, j = x - 1; j >= 0; i--, j--)
    {
        if(check(n,i))
        {
            ret = Set(ret,j);
        }
    }

    return ret;
}

ll Equal(ll n, ll len, ll x)
{
    ll ret = 0;

    for(ll i = len - 1, j = x - 1; j >= 0; i--, j--)
    {
        if(check(n,i))
        {
            for(ll k = i; k >= 0; k -= x)
            {
                ret = Set(ret,k);
            }
        }
    }

    if(ret <= n) return 0;

    else return 1;
}

ll solve(ll n)
{
    if(n <= 1) return 0;

    ll len = len_calc(n);

    ll ans = 0;

    for(ll i = 1; i <= len; i++)
    {
        ll sz = div__[i].size();

        for(ll j = 0; j < sz; j++)
        {
            ll x = div__[i][j];

            ll temp = 0;

            ll sz1 = div__[x].size();

            if(i < len)
            {
                temp += (1LL << (x - 1));

                for(ll k = 0; k < sz1; k++)
                {
                    ll y = div__[x][k];

                    temp -= cnt[y];
                }

                cnt[x] = temp;

                ans += temp;
            }
            else
            {
                temp = (sub_len(n,len,x)) - (1LL << (x - 1)) + 1;

                temp -= Equal(n,len,x);

                for(ll k = 0; k < sz1; k++)
                {
                    ll y = div__[x][k];

                    temp -= cnt[y];
                }

                cnt[x] = temp;

                ans += temp;

            }
        }
    }

    return ans;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    precalc();

    while(cin >> l >> r)
    {
        l = solve(l - 1);

        r = solve(r);

        cout << r - l << endl;
    }


}


