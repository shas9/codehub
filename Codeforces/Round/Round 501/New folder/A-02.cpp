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

#define mod 100000000


using namespace std;

pair < ll, ll > vec[100005];
priority_queue < pair < ll, ll > > pq;
ll dp[100005];

bool comp(pair < ll , ll > x, pair < ll, ll > y)
{
    if(x.first == y.first) return x.second > y.second;

    return x.first > y.first;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(1)
    {
        slld(n);

        if(n == -1) return 0;

        while(!pq.empty()) pq.pop();

        for(i = 1; i <= n; i++)
        {
            slld(vec[i].first);
            slld(vec[i].second);
            dp[i] = 1;
        }

        sort(vec + 1, vec + 1 + n, comp);

        for(i = 1; i <= n; i++) cout << vec[i].first << " " << vec[i].second << endl;

        i = 0;
        ll carry = 0;

        while(++i <= n)
        {
            while(!pq.empty())
            {
                pair < ll, ll > top = pq.top();

                cout << top.first << " " << vec[i].first << endl;

                if(top.first <= vec[i].first) break;

                bug;

                pq.pop();

                carry += top.second;
            }

            cout << carry << endl;

            dp[i] += carry;

            pq.push(make_pair(vec[i].first, dp[i]));
        }

        ans = 0;

        for(i = 1; i <= n; i++) ans += dp[i], ans %= mod;

        cout << ans << endl;
    }


}



