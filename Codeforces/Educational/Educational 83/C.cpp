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

ll arr[50];
vector < ll > coins;

bool solve(ll num)
{
    sort(coins.begin(),coins.end());

//    cout << num << endl;

    if(num == 0) return 1;

    for(ll i = 0; i < coins.size(); i++)
    {
        if(coins[i] > num)
        {
            i--;
            for(ll j = i; j >= 0; j--)
            {
                if(num == 0) return 1;

                num -= coins[j];

//                cout << coins[j] << endl;

                coins[j] = 0;

                if(num == 0) return 1;
            }

            break;
        }
    }

    return 0;

}

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
        slld(k);

        coins.clear();

        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);
        }

        sort(arr + 1, arr + 1 + n);

        coins.push_back(1);

        for(i = 1; ; i++)
        {
            coins.push_back(coins[coins.size() - 1] * k);

            if(coins[coins.size() - 1] > 10000000000000000) break;
        }

//        for(i = 0; i < coins.size(); i++)
//        {
//            cout << coins[i] << endl;
//        }
//
//        cout << endl;

        bool ok = 0;
        for(i = 1; i <= n; i++)
        {
            if(solve(arr[i])) continue;

            ok = 1;
            break;
        }


        if(ok) cout << "NO" << endl;
        else cout << "YES" << endl;
    }


}



