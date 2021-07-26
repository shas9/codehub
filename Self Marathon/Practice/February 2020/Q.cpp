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

string str;

ll cnt[30];

ll ans[200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        cin >> str;
        memset(cnt,-1,sizeof cnt);

        ll mxx = 0;

        for(i = 0; i < n; i++)
        {
            ll xx = str[i] - 'a';

            ll mx = -1;

            for(j = xx + 1; j < 26; j++)
            {
                mx = max(mx, cnt[j]);
            }

            ans[i] = mx + 1;

            cnt[xx] = mx + 1;

            mxx = max(mxx, mx + 1);
        }

        if(mxx >= 2)
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;

        for(i = 0; i < n; i++)
        {
            cout << ans[i];
        }

        cout << endl;
    }


}


