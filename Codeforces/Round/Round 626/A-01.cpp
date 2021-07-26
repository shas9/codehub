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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        slld(n);

        for(j = 1; j <= n; j++)
        {
            slld(arr[i]);
        }

        if(n == 1 && arr[1] % 2)
        {
            cout << -1 << endl;
            continue;
        }

        ll temp = 0;

        for(j = 1; j <= n; j++)
        {
            if(arr[j] % 2 == 0)
            {
                cout << arr[j] << endl;
                cout << 1 << endl << j << endl;
                break;
            }

            if(temp)
            {
                cout << 2 << endl << temp << " " << j << endl;
                break;
            }

            if(arr[j] % 2) temp = j;
        }
    }

    return 0;
}


