// God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}

ll arr[3003];

bool isvalid(ll val, ll sz, ll n)
{
	if(sz > n) return 0;

	ll sum = 0;

	for(ll i = 1; i <= n; i++)
	{
		sum += arr[i];

		if(sum > val) return 0;

		if(sum == val) sum = 0;
	}

	return 1;
}

ll solve(ll n, ll sum)
{
	ll ret = mxlld;

    for(ll i = 1; i * i <= sum; i++)
    {
        if(sum % i == 0)
        {
			if(isvalid(i, sum / i, n)) ret = min(ret, n - (sum / i));
			if(isvalid(sum / i, i, n)) ret = min(ret, n - i);
        }
    }

    return ret;
}

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
        ll sum = 0;
        cin >> n;

        for(ll i = 1; i <= n; i++)
        {
            slld(arr[i]);

            sum += arr[i];
        }

        ans = solve(n, sum);

        cout << ans << "\n";
    }


}



