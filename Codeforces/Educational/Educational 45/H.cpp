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

ll prime = 2707;
char str[100005];
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);

    while(scanf("%s", str + 1) != EOF)
    {
        ll len = strlen(str + 1);

        ull cnt1 = 0;
        ull cnt2 = 0;
        ull base = 1;
        ull ans = 0;

        for(i = len, j = 1; i >= 1; j++, i--)
        {
            cnt1 = (cnt1 * prime) + str[i];

            cnt2 = (base * str[i])  + cnt2;

            base *= prime;

            if(cnt1 == cnt2) ans = j;
        }

        //cout << ans << endl;
        printf("%s", str + 1);

        ans = len - ans;

        for(i = ans; i >= 1; i--) printf("%c", str[i]);

        printf("\n");
    }


}


