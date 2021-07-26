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

ll prefixsum[200005];
ll suffixsum[200005];
ll arr[200005];
struct node
{
    ll pos, freq, vl;
}val[200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(k);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);
    }

    sort(arr + 1, arr + 1 + n);

    ll idx = 0;
    for(i = 1; i <= n; i++)
    {
        if(arr[i] == arr[i - 1])
        {
            val[idx].freq++;
            continue;
        }

        val[++idx].freq = 1;
        val[idx].pos = i;
        val[idx].vl = arr[i];
    }

    for(i = 1; i <= n; i++)
    {
        prefixsum[i] = prefixsum[i - 1] + arr[i];
    }

    for(i = n; i >= 1; i--)
    {
        suffixsum[i] = suffixsum[i + 1] + arr[i];
    }

    ans = mxlld;

    for(i = 1; i <= idx; i++)
    {
        ll need = max(0LL, k - val[i].freq);

        ll needl = min(need,val[i].pos - 1);
        ll needr = max(0LL, need-needl);

        ll cost1 = ((val[i].vl - 1) * (val[i].pos - 1)) - prefixsum[val[i].pos - 1];
        ll cost2 = suffixsum[val[i].pos + val[i].freq] - ((val[i].vl + 1) * (n - val[i].pos - val[i].freq + 1));

        ll sum1 = 0, sum2 = 0;

        if(needl) sum1 = cost1 + needl;
        if(needr) sum2 = cost2 + needr;

        ll sum = sum1 + sum2;

        ans = min(ans,sum);
    }

    for(i = 1; i <= idx; i++)
    {
        ll need = max(0LL, k - val[i].freq);

        ll needr = min(need,n - (val[i].pos + val[i].freq - 1));
        ll needl = max(0LL, need-needr);

        ll cost1 = ((val[i].vl - 1) * (val[i].pos - 1)) - prefixsum[val[i].pos - 1];
        ll cost2 = suffixsum[val[i].pos + val[i].freq] - ((val[i].vl + 1) * (n - val[i].pos - val[i].freq + 1));

        ll sum1 = 0, sum2 = 0;

        if(needl) sum1 = cost1 + needl;
        if(needr) sum2 = cost2 + needr;

        ll sum = sum1 + sum2;

        ans = min(ans,sum);
    }

    cout << ans << endl;


}



