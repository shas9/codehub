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

ll arr[100005];
ll dep[1004];
ll getmax(ll l, ll r)
{
	ll ret = l;
	ll val = 0;

	for(ll i = l; i <= r; i++)
	{
		if(arr[i] > val)
		{
			val = arr[i];
			ret = i;
		}
	}

	return ret;
}

void dfs(ll node, ll d, ll l, ll r)
{
	dep[node] = d;

	if(l < node)
	{
		dfs(getmax(l,node - 1), d + 1, l, node - 1);
	}

	if(node < r)
	{
		dfs(getmax(node + 1, r), d + 1, node + 1, r);
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
		cin >> n;

		for(ll i = 1; i <= n; i++)
		{
			slld(arr[i]);
		}

		dfs(getmax(1,n),0,1,n);

		for(ll i = 1; i <= n; i++)
		{
			cout << dep[i] << " ";
		}

		cout << "\n";
    }


}



