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

ll arr[200005];

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

        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);
        }

        l = r = -1;

        for(i = 1; i < n; i++)
        {
            ll mx = max(arr[i],arr[i + 1]);
            ll mn = min(arr[i],arr[i + 1]);

            if(abs(mx - mn) >= 2)
            {
                l = i;
                r = i + 1;
                break;
            }
        }

        if(l == -1) cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            cout << l << " " << r << endl;
        }
    }


}



