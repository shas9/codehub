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

vector < vector < ll > > vec;
ll arr[200005];
bool vis[200005];

bool poss(ll idx)
{
	vector < ll > aa;

	while(vis[idx] == 0)
	{
		aa.push_back(arr[idx]);
		vis[idx] = 1;

		idx = arr[idx];
	}

	if(aa.size() != 3) return 0;

	ll cnt = 0;

	if(aa[0] > aa[1]) cnt++;
	if(aa[0] > aa[2]) cnt++;

	for(ll i = 0; i < cnt; i++) vec.push_back(aa);

	return 1;
}

bool solve(ll n, ll k)
{
	vec.clear();

	for(ll i = 1; i <= n; i++)
	{
		if(arr[i] == i) continue;

		if(vis[i]) continue;

//		cout << i << endl;
		if(!poss(i)) return 0;

		if(vec.size() > k) return 0;
	}

	return 1;
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
		slld(n);
		slld(k);

		for(i = 1; i <= n; i++)
		{
			slld(arr[i]);
			vis[i] = 0;
		}

		if(!solve(n,k)) printf("-1\n");
		else
		{
			cout << vec.size() << "\n";

			for(auto it: vec)
			{
				cout << it[0] << " " << it[1] << " " << it[2] << "\n";
			}
		}
    }


}



