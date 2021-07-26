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

map < ll, ll > mp;

ll arr[1000];

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
        slld(m);

        for(i = 1; i <= n; i++) slld(arr[i]);

        mp.clear();

        for(i = 1; i <= m; i++)
        {
            slld(input);
            mp[input] = 1;
        }

        for(i = 1; i <= (n * n); i++)
        {
            for(j = 1; j < n; j++)
            {
                if(arr[j] > arr[j + 1])
                {
                    if(mp.find(j) != mp.end())
                    {
                        swap(arr[j],arr[j + 1]);
                    }
                }
            }
        }

        for(i = 1; i < n; i++)
        {
            if(arr[i] > arr[i + 1])
            {
                cout << "NO" << endl;
                break;
            }
        }

        if(i == n)
        {
            cout << "YES" << endl;
        }


    }


}



