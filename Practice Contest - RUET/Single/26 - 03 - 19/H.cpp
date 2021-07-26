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

set < ll > mp;

ll arr[2005];
ll _arr[2005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> n)
    {
        mp.clear();

        for(i = 1; i <= n; i++)
        {
            cin >> arr[i];

            mp.insert(arr[i]);
        }

        for(i = 1; i <= n; i++)
        {
            cin >> _arr[i];

            mp.insert(_arr[i]);
        }

        ll cnt = 0;

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                ll x = arr[i] ^ _arr[j];

                if(mp.find(x) != mp.end()) cnt++;
            }
        }

        if(cnt % 2) cout << "Koyomi" << endl;
        else cout << "Karen" << endl;
    }


}



