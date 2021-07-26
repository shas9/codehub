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

struct num
{
    ll nn;

    bool bit[35];
};

num arr[100005];

bool comp(num a, num b)
{
    ll x = (a.nn | b.nn) - b.nn;
    ll y = (a.nn | b.nn) - a.nn;

    if(x == y) return a.nn > b.nn;

    if(x > y) return 1;

    return 0;
}

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
        slld(arr[i].nn);

        for(j = 32; j >= 0; j--)
        {
            if(check(arr[i].nn,j))
            {
                arr[i].bit[j] = 1;
            }
            else
            {
                arr[i].bit[j] = 0;
            }
        }
    }

    sort(arr + 1, arr + 1 + n, comp);

    for(i = 1; i <= n; i++)
    {
        cout << arr[i].nn << " ";
    }



}


