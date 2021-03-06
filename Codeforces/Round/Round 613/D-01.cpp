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

ll check(ll n, ll pos)
{
	if(n & (1LL << pos)) return 1;
	return 0;
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll tree[3000006][2];
ll node;

void ins(ll num)
{
    ll curr = 0;

    for(ll i = 30; i >= 0; i--)
    {
        ll x = check(num,i);

        if(tree[curr][x] == -1)
        {
            tree[curr][x] = ++node;
        }

        curr = tree[curr][x];
    }
}

ll srch(ll curr, ll bit)
{
    if(curr < 0) return 0;

    ll val = 1LL << bit;

    if(tree[curr][0] != -1 && tree[curr][1] != -1) return min(srch(tree[curr][0],bit-1), srch(tree[curr][1],bit-1)) + val;

    if(tree[curr][0] != -1) return srch(tree[curr][0],bit-1);

    if(tree[curr][1] != -1) return srch(tree[curr][1],bit-1);

    return 0;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        memset(tree,-1,sizeof tree);
        node = 0;

        for(i = 1; i <= n; i++)
        {
            slld(input);

            ins(input);
        }

        ans = srch(0,30);

        cout << ans << endl;
    }


}



