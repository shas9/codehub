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

#define maxn 200005
using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll arr[maxn];
ll pow10[20];
unordered_map < ll, ll > rem[15];

ll getsz(ll x)
{
    ll ret = 0;

    while(x > 0) x /= 10, ret++;

    return ret;
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    long long input, flag, tag, ans;

//     freopen("in.txt", "r", stdin);

    while(cin >> n >> k)
    {
        pow10[0] = 1;
        for(i = 1; i <= 10; i++)
        {
            pow10[i] = pow10[i - 1] * 10;
            pow10[i] %= k;
        }

        for(i = 1; i <= 10; i++) rem[i].clear();

        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);
            rem[getsz(arr[i])][arr[i] %k]++;
        }

        ans = 0;
        for(i = 1; i <= n; i++)
        {
            rem[getsz(arr[i])][arr[i] % k]--;
            for(j = 1; j <= 10; j++)
            {
                flag = arr[i] * pow10[j];
                flag %= k;
                ll need = (k - flag) % k;

                if(rem[j].find(need) != rem[j].end())
                ans += rem[j][need];
            }
            rem[getsz(arr[i])][arr[i] % k]++;
        }

        plld(ans);
    }


}


