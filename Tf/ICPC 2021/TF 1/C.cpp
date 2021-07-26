 // God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll int
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

const ll N = 100005;
ll arr[N];
ll savelft[N];
ll savergt[N];

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
		cin >> n;
		set < ll > st;

		for(ll i = 1; i <= n; i++)
		{
			cin >> input;
			st.insert(input);
		}

		n = 0;

		for(auto it: st)
		{
			arr[++n] = it;
		}

		savelft[0] = 0;

		for(ll i = 1; i <= n; i++)
		{
			savelft[i] = __gcd(savelft[i - 1], arr[i]);
		}

		savergt[n + 1] = 0;

		for(ll i = n; i >= 1; i--)
		{
			savergt[i] = __gcd(savergt[i + 1], arr[i]);
		}

		ans = 0;

		for(ll i = 1; i <= n; i++)
		{
			ll lft = __gcd(savelft[i - 1], savergt[i + 1]);

			ans = max(ans, lft + arr[i]);
		}

		if(n == 1) ans = arr[n] * 2;

		cout << ans << "\n";
    }


}



