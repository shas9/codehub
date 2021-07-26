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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ll a, b;

    while(cin >> n >> m >> k >> l >> a >> b)
    {
        ll first = n;
        ll second = min(m,k);

        ans = 0;

        ll ans1 = mnlld;
        flag = l;

//        if(b > a)
        {
            ans += min(l,second) * b;

            l -= min(l,second);

            ans += min(l,n) * a;
            l -= min(l,n);
        }

        ans1 = max(ans1,ans);

        ans = 0;

        l = flag;
//        if(a > b)
        {
            ans += min(l,n) * a;

            l -= min(l,n);

            ans += min(l,second) * b;

            l -= min(l,second);
        }

        ans1 = max(ans1,ans);

        cout << ans1 << endl;
    }

}


