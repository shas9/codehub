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

ll arr[103];
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        ll tot = 0;

        for(i = 1; i <= n; i++) slld(arr[i]), tot += arr[i];

        sort(arr + 1, arr + 1 + n);

        ll vote = tot / (4 * m);

        if(tot % (4 * m)) vote++;

        ll cnt = 0;

        for(i = n; i >= 1; i--)
        {
            if(arr[i] >= vote) cnt++;

            if(cnt == m) break;
        }

        if(cnt == m) cout << "Yes" << endl;
        else cout << "No" << endl;


    }


}

