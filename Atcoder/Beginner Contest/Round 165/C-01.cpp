// God put a smile upon your face <3

#include <bits/stdc++.h>`

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

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}
vector < ll > vec;
struct node
{
	ll a, b, c, d;
} arr[1000];

ll n, m, q;

ll score()
{
	ll ret = 0;

//	for(auto it: vec) cout << it << " ";

	for(ll i = 0; i < q; i++)
	{
		if(vec[arr[i].b] - vec[arr[i].a] == arr[i].c) ret += arr[i].d;
	}

//	cout << ret << endl;

	return ret;
}

ll ans;

void dfs(ll pos)
{
	if(pos == n) ans = max(ans, score());
	else
	{
//		cout << pos << " " << n << endl;
		ll st = pos == 0 ? 1 : vec.back();

//		cout << pos << " " << st << " " << (pos == 0 ? 1 : vec.back()) << endl;

		for(ll i = st; i <= m; i++)
		{
			vec.push_back(i);

			dfs(pos + 1);

			vec.pop_back();
		}
	}

	return;
}

int main()
{
    ll i, j;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> q)
    {
		vec.clear();

		for(ll i = 0; i < q; i++) cin >> arr[i].a >> arr[i].b >> arr[i].c >> arr[i].d, arr[i].a--, arr[i].b--;

		ans = 0;

		dfs(0);

		cout << ans << '\n';
    }


}



