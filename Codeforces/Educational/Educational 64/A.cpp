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

ll arr[200];
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    ll prev = 0;
    ans = 0;

    for(ll i = 1; i <= testcase; i++)
    {
        slld(arr[i]);

        if(i == 1) continue;

        if(arr[i] + arr[i - 1] == 5) ans = -1;

        if(ans == -1) continue;

        if(arr[i] == 1 && arr[i - 1] == 3)
        {
            ans += 4;

            if(i <= 2) continue;

            if(arr[i - 2] == 2) ans -= 2;
        }

        if(arr[i] == 2 && arr[i - 1] == 1)
        {
            ans += 3;
            if(i <= 2) continue;

            if(arr[i - 2] == '3') ans--;
        }

        if(arr[i] == 3 && arr[i - 1] == 1)
        {
            ans += 4;
        }

        if(arr[i] == 1 && arr[i - 1] == 2)
        {
            ans += 3;
        }

    }

    if(ans == -1) cout << "Infinite" << endl;
    else
    {
        cout << "Finite" << endl;
        cout << ans << endl;
    }


}


