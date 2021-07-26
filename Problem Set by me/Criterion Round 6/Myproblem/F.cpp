#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

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

bool vis[500005];
ll cnt[500005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        memset(vis,0,sizeof vis);
        memset(cnt,0,sizeof cnt);

        ll tot = 0;

        for(i = n / 2; i >= 2; i--)
        {
            for(j = i + i; j <= n; j += i)
            {
                if(vis[j]) continue;

                cnt[i]++;

                vis[j] = 1;
            }

            tot += cnt[i];
        }

        cnt[1] = n - 1 - tot;

//        cout << cnt[1] << " " << tot << endl;

        i = 1;

        while(i <= n)
        {
            while(cnt[i]--)
            {
                cout << i << " ";
            }

            i++;
        }

        cout << "\n";

    }


}


