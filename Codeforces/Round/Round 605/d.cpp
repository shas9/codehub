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

ll arr[1000000];
ll cnt[1000000];
ll track[1000000];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);
    }

    cnt[1] = 1;

    for(i = 2; i <= n; i++)
    {
        if(arr[i] > arr[i - 1])
        {
            cnt[i] = cnt[i - 1] + 1;
        }
        else
        {
            cnt[i] = 1;
        }
    }

    track[n] = cnt[n];

    ans = track[n];

    for(i = n - 1; i >= 1; i--)
    {
        if(cnt[i + 1] == 1)
        {
            track[i] = cnt[i];
            continue;
        }

        track[i] = track[i + 1];

        ans = max(ans, track[n]);
    }

    for(i = 2; i <= n - 1; i++)
    {
       if(arr[i - 1] < arr[i + 1])
       {
           if(cnt[i] == 1 && cnt[i + 1] == 1)
           {
               ans = max(ans, track[i - 1] + track[i + 1]);
           }
           else if(cnt[i] == 1 || cnt[i + 1] == 1)
           {
               ans = max(ans, track[i - 1] + track[i + 1] - 1);
           }
           else
           {
               ans = max(ans, track[i]);
           }
       }
       else
       {
           ans = max(ans, track[i]);
       }
    }

    cout << ans << endl;
}

