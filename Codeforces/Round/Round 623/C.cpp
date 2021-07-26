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

ll arr[1000];
ll brr[1000];
ll vis[1000];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        memset(vis,0,sizeof vis);

        slld(n);

        for(i = 1; i <= n; i++) slld(brr[i]), vis[brr[i]] = 1;

        bool poss = 1;

        for(i = 1; i <= n; i ++)
        {
            arr[2*i - 1] = brr[i];

            for(j = brr[i] + 1; j <= (2 * n); j++)
            {
                if(vis[j]) continue;

                break;
            }

            if(j > (2 * n))
            {
                poss = 0;
                break;
            }

            arr[2*i] = j;

            vis[j] = 1;
        }

        if(poss == 0) cout << -1 << endl;
        else
        {
            for(i = 1; i <= (2 * n); i++)
                cout << arr[i] << " ";

            cout << endl;
        }
    }


}


