// God put a smile upon your face <3

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

ll par[200005];
ll arr[200005];
ll wat[200005];
ll n;

ll fnd(ll node)
{
	if(par[node] == node) return node;

	return par[node] = fnd(par[node]);
}

void update(ll idx, ll val)
{
	while(val)
	{
		idx = fnd(idx);

		if(idx == n + 1) return;

//		cout << idx << " " << wat[idx] << " " << val << endl;

		if(wat[idx] + val < arr[idx])
		{
			wat[idx] += val;
			return;
		}

		val -= abs(arr[idx] - wat[idx]);
		wat[idx] = arr[idx];

		par[idx] = fnd(idx + 1);
	}

}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(i = 1; i <= n; i++)
		{
			slld(arr[i]);
			par[i] = i;
			wat[i] = 0;
		}

		par[n + 1] = n + 1;

		slld(m);

		for(i = 1; i <= m; i++)
		{
			ll t, x, p;

			slld(t);
			slld(x);

			if(t == 2) printf("%lld\n", wat[x]);
			else
			{
				slld(p);

				update(x,p);
			}
		}
    }


}


