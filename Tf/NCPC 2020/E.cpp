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

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define maxn 10005

using namespace std;

bool vis[maxn+10];
unordered_map < ll, bool > mp;

string num;
ll n;

void sieve()
{
    vis[0] = 1;
    vis[1] = 1;

    for(ll i = 4; i <= maxn; i += 2)
    {
        vis[i] = 1;
    }

    for(ll i = 3; i * i <= maxn; i += 2)
    {
        if(vis[i] == 0)
        for(ll j = i * i; j <= maxn; j += i)
        {
            vis[j] = 1;
        }
    }

    for(ll i = 2; i <= maxn; i++)
    {
        if(vis[i] == false)
        {
            mp[i] = 1;
        }
    }

}

int main()
{
    ll i, j, k, l, m, o, x;
    ll testcase;
    ll input, flag, tag, ans;

    sieve();

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> num;

        ans = 0;

        for(i = 0; i < n; i++)
        {
            ll xx = 0;
            for(j = 0; j < 5; j++)
            {
                xx *= 10;
                xx += num[i + j] - '0';

                if(xx > 10000) break;

                if(mp.find(xx) == mp.end()) continue;

                ans = max(ans,xx);
            }
        }

        printf("Case %lld: ", cs);

        if(ans == 0) cout << "This is a junk!" << endl;
        else cout << ans << endl;
    }


}



