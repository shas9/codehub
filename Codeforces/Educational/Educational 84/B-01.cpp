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

ll mark[100005];
ll arr[100005];
ll marry[100005];

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
        slld(n);

        for(i = 1; i <= n; i++) mark[i] = 0, arr[i] = 0, marry[i] = 0;

        for(i = 1; i <= n; i++)
        {
            slld(m);

            for(j = 1; j <= m; j++)
            {
                slld(input);

                if(marry[i]) continue;
                if(mark[input]) continue;

                mark[input] = i;
                marry[i] = input;

            }
            arr[i] = m;
        }

        bool ok = 0;

        for(i = 1; i <= n; i++)
        {
            if(marry[i]) continue;
            if(arr[i] == n) continue;

            for(j = 1; j <= n; j++)
            {
                if(mark[j] == 0)
                {
                    cout << "IMPROVE" << endl;
                    cout << i << " " << j << endl;
                    ok = 1;
                    break;
                }
            }

            if(ok) break;
        }

        if(ok) continue;

        cout << "OPTIMAL" << endl;


    }


}



