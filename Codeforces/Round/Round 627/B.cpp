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

ll arr[5005];
ll cnt[5005];
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

        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);
        }

        memset(cnt,0,sizeof cnt);

        cnt[arr[1]] = 1;

        bool ok = 0;

        //check for size 3
        for(i = 2; i < n; i++)
        {
            for(j = i + 1; j <= n; j++)
            {
                if(cnt[arr[j]] == 1)
                {
                    ok = 1;
                    break;
                }
            }

            cnt[arr[i]] = 1;

            if(ok) break;
        }

        if(ok)
        {
            cout << "YES" << endl;
            continue;
        }

        memset(cnt,0,sizeof cnt);

        cnt[arr[1]] = 1;

        //checking for size 4
        for(i = 2; i <= n; i++)
        {
            ll prevj = n;
            for(j = n - 1; j > i; j--)
            {
                if(arr[i] == arr[j])
                {
                    for(k = j + 1; k <= prevj; k++)
                    {
                        if(cnt[arr[k]] == 1)
                        {
                            ok = 1;
                            break;
                        }
                    }
                    prevj = j;
                }

                if(ok) break;
            }

            cnt[arr[i]] = 1;

            if(ok) break;
        }

        if(ok)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }


}



