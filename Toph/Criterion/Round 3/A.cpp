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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ll arr[3] = {0,0,0};

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(input);

        if(input < 0) arr[1]++;
        if(input > 0) arr[2]++;
        if(input == 0) arr[0]++;
    }

    ans = 0;

    ll st = 0;

    if(arr[2]) arr[2]--, st = 2;
    else if(arr[1]) arr[1]--, st = 1;
    else if(arr[0]) arr[0] -= 2, st = 0;

    if(st)
    {
        ans += arr[1];

        if(arr[0]) ans++;
    }

    cout << ans << endl;

}


