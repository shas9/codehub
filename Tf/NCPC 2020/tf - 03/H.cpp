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

struct node
{
    ll x, y, z;
};
vector < ll > vec;

ll ans[500005];
ll arr[500005];
node inp[500005];

ll solve(ll num)
{
    ll lo = 0;
    ll hi = vec.size() - 1;
    ll pos = 0;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(vec[mid] <= num)
        {
            pos = mid + 1;
            lo = mid + 1;
        }
        else
        {
            hi = mid -1;
        }
    }

    return pos;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(i = 1; i <= n; i++)
    {
        vector < ll > in;

        in.clear();

        for(j = 0; j < 3; j++)
        {
            slld(input);

            in.push_back(input);
        }

        sort(in.begin(),in.end());

        vec.push_back(in[0] + in[1] + 2);

        arr[i] = in[0] + in[1] + in[2];

        inp[i].x = in[0];
        inp[i].y = in[1];
        inp[i].z = in[2];
    }

    sort(vec.begin(),vec.end());

    for(i = 1; i <= n; i++)
    {
        ans[i] = solve(arr[i]);

        if((inp[i].x + inp[i].y + 2) <= arr[i])
            ans[i]--;
    }

    for(i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;


}


