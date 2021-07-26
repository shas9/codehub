#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%llu", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll unsigned long long
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

unordered_map < ll, ll > rem[20];
ll arr[200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//     freopen("in.txt", "r", stdin);

    while(cin >> n >> k)
    {
        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);
        }

        for(i = 1; i <= 10; i++)
        {
            rem[i].clear();
        }

        ans = 0;

        for(i = 1; i <= n; i++)
        {
            flag = arr[i];
            for(j = 1; j <= 10; j++)
            {
                flag *= 10;

                ll md = flag % k;

                rem[j][md]++;

//                if(arr[i] == 1000000000) cout << flag << endl;
            }


        }

        for(i = 1; i <= n; i++)
        {
            flag = arr[i];
            ll sz = 0;

            while(flag > 0) flag /= 10, sz++;

            ll md = arr[i] % k;

            ll need = k - md;

            need %= k;

            if(rem[sz].find(need) != rem[sz].end())
            ans += rem[sz][need];

            flag = arr[i];

            for(j = 1; j <= sz; j++) flag *= 10;

            if(flag % k == need) ans--;

        }

        plld(ans);
    }
}
