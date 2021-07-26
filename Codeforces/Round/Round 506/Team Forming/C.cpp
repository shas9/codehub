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

#define maxn 200000
using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll arr[maxn];
ll brr[maxn];
map < ll, ll > mp;
vector < ll > a, b;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(1)
    {
        mp.clear();
        a.clear();
        b.clear();

        slld(n);

        if(n == 0) return 0;

        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);
            mp[arr[i]] = 1;
        }

        slld(m);
        for(i = 1; i <= m; i++)
        {
            slld(brr[i]);

            if(mp[brr[i]] == 1)
            {
                mp[brr[i]] = 2;
            }
        }

        flag = 0;
        for(i = 1; i <= n; i++)
        {
           input = arr[i];

           flag += input;

           if(mp[input] == 2)
           {
               a.push_back(flag);
               flag = 0;
           }
           else if(i == n) a.push_back(flag);

        }

        flag = 0;
        for(i = 1; i <= m; i++)
        {
           input = brr[i];

           flag += input;

           if(mp[input] == 2)
           {
               b.push_back(flag);
               flag = 0;
           }
           else if(i == m) b.push_back(flag);

        }

        ll sz = min(a.size(), b.size());


        if(a.size() > sz) b.push_back(0LL), sz++;
        else if(b.size() > sz) a.push_back(0LL), sz++;

//        cout << a.size() << " " << b.size() << endl;

        ans = 0;
        for(i = 0; i < sz; i++)
        {
            ans += max(a[i],b[i]);

//            cout << ans << " " << max(a[i],b[i]) << endl;
        }

        plld(ans);

    }


}

//

