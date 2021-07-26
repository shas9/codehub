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
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll arr[200000];
ll brr[200000];
ll one[200000];
ll zero[200000];

string a, b;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll c1 = 0,c2 = 0,c3 = 0,c4 = 0;

    slld(n);

    cin >> a >> b;

    for(i = 1; i <= n; i++) arr[i] = a[i - 1] - '0', brr[i] = b[i - 1] - '0';
    for(i = n; i >= 1; i--)
    {
        if(arr[i] == 0 && brr[i] == 0) c1++;
        else if(arr[i] == 1 && brr[i] == 1) c2++;
        else if(arr[i] == 1) c3++;
        else c4++;
    }


    ans = (c1 * c2) + (c1 * c3) + (c3 * c4);

    plld(ans);

}


