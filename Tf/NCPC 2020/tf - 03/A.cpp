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

ll arr[500005];
ll mark[500005];
ll ans[500005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        memset(mark,0,sizeof mark);
        memset(ans,0,sizeof ans);

        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);
        }

        j = 1;

        for(i = 1; i <= n; i++)
        {
            if(arr[i] < 0)
            {
                mark[abs(arr[i])]++;
                ans[j]++;
            }
            else
            {
                if(mark[arr[i]] == 0)
                {
                    ans[j]++;
                }
                else
                {
                    j++;
                    ans[j] = ans[j - 1] - 1;
                    if(arr[j - 1] < 0)
                    {
                        mark[abs(arr[j - 1])]--;
                    }

                    i--;
                }
            }
        }

        j++;
        for(; j <= n; j++)
            ans[j] = ans[j - 1] - 1;


        for(i = 1; i <= n; i++) cout << ans[i] << " ";

        cout << endl;
    }


}


