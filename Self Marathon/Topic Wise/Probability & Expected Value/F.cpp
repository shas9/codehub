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

double exp_val[103];
ll arr[105];
bool vis[103];

double solve(ll node)
{
	queue < ll > qq;

	qq.push(100);

	memset(vis,0,sizeof vis);

	while(!qq.empty())
	{
		ll top = qq.front();
		qq.pop();


	}
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
		memset(exp_val,0,sizeof exp_val);
		memset(arr,-1,sizeof arr);

		slld(n);

		for(i = 1; i <= n; i++)
		{
			slld(input);
			slld(arr[input]);
		}

		double ans = solve(1);

		printf("Case %lld: %.10f\n", cs, ans);
    }


}


