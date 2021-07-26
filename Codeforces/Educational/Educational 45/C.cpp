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

ll ei[300005];
ll oi[300005];

char str[300005];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    ll len = 0, ans = 0;

    bool on, off;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        scanf(" %s", str + 1);

        len = strlen(str + 1);

        ll cnt = 0;
        //ll mx = mnlld;

        on = off = 0;

        tag = 0;

        for(i = 1; i <= len; i++)
        {
            if(str[i] =='(') cnt++;
            else cnt--;

            if(cnt < 0)
            {
                on = 1;
            }
        }

        cnt = 0;

        for(i = len; i >= 1; i--)
        {
            if(str[i] =='(') cnt++;
            else cnt--;


            if(cnt > 0 && on)
            {
                off = 1;
                break;
            }
        }

        if(off && on) continue;

        if(cnt == 0) ans++;

        if(cnt < 0) ei[abs(cnt)]++;
        else oi[cnt]++;

        //cout << cnt << endl;
    }

    ans = ans * ans;

    for(i = 1; i <= 300000; i++)
    {
        ans += ei[i] * oi[i];
    }

    cout << ans << endl;


}


