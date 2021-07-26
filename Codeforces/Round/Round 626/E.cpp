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

ll dp[100005][150];
pll arr[100005];
ll ss[100005][8];
ll n, m, k;

bool comp(pll a, pll b)
{
    if(a.first == b.first)
        return a.second < b.second;

    return a.first > b.first;

}

ll solve(ll pos, ll mask)
{
    ll &ret = dp[pos][mask];

    if(ret != -1) return ret;

    ret = 0;

    if(pos > n)
    {
        for(ll i = 0; i < m; i++)
        {
            if(check(mask,i)) continue;

            return ret = mnlld;
        }

        return ret = 0;
    }

    ll rem = 0;

    for(ll i = 0; i < m; i++)
        if(check(mask,i)) rem++;

    ret = solve(pos + 1, mask);

    if(pos - rem <= k)
    {
        ret += arr[pos].first;
    }

    ll ret1 = 0;

    for(ll i = 1; i <= m; i++)
    {
        if(check(mask,i - 1)) continue;

        ret1 = max(ret1,solve(pos + 1,Set(mask,i - 1)) + ss[arr[pos].second][i]);

    }

//    cout << pos << " " << rem << " " << ret1 << " " << ret << endl;
    ret = max(ret,ret1);


//
    return ret;
}

int main()
{
    ll i, j, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
        memset(dp,-1,sizeof dp);

        for(i = 1; i <= n; i++)
        {
            slld(arr[i].first);
            arr[i].second = i;
        }

        sort(arr + 1, arr + 1 + n, comp);

//        cnt = 0;
////
//        for(i = 1; i <= n; i++)
//        {
//            cout << pk[i] << " ";
//        }
//
//        cout << endl;
//
//        for(i = 1; i <= n; i++)
//        {
//            cout << arr[i].first << " " << arr[i].second << endl;
//        }

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                slld(ss[i][j]);
            }
        }

//        pick = k;

        ans = solve(1,0);

//        cout << "~~" << ans << endl;

//        for(i = 1; i <= n; i++)
//        {
//            if(vis[i]) continue;
//
//            cnt++;
//
//            ans += arr[i].first;
//
//            if(cnt == k) break;
//        }

        cout << ans << endl;
    }
}


