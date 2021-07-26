#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

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
    ll num, id;
};

bool comp(node a, node b)
{
    return a.num > b.num;
}

node arr[100005];
ll ans[100005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

////    slld(testcase);
//
//    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);

        ll sum = 0;

        for(i = 1; i <= m; i++)
        {
            slld(arr[i].num);

            arr[i].id = i;

            sum += arr[i].num;
        }

        if(sum < n)
        {
            cout << -1 << endl;
            return 0;
        }

        sort(arr + 1, arr + 1 + n, comp);



        ll last = 0;

        for(i = 1; i <= m; i++)
        {
            ll x = (n - last) / (m - i + 1);
            ll y = (n - last) % (m - i + 1);

            ll lim = last + x;

            if(y) lim++;

            lim = min(lim, n - arr[i].num + 1);

            ans[arr[i].id] = min(last + 1, n - arr[i].num + 1);
            last = lim;


        }

        for(i = 1; i <= m; i++)
        {
            cout << ans[i] << " ";
        }

        cout << endl;
    }


}



