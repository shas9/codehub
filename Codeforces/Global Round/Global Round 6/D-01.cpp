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

ll pos[100005];
ll neg[100005];
vector < pair < ll, pair < ll, ll > > > vec;
ll arr[100005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		memset(arr,0,sizeof arr);
		memset(pos,0,sizeof pos);
		memset(neg,0,sizeof neg);
		vec.clear();

		for(i = 1; i <= m; i++)
		{
			ll u, v, c;

			cin >> u >> v >> c;

			arr[u] -= c;
			arr[v] += c;
		}

		for(i = 1; i <= n; i++)
		{
			if(arr[i] < 0) neg[i] = abs(arr[i]);
			else pos[i] = arr[i];
		}

		i = j = 1;

		while(i <= n && j <= n)
		{
			ll mn = min(neg[i],pos[j]);

			if(mn)
			{
				vec.push_back({i,{j,mn}});
			}

			neg[i] -= mn;
			pos[j] -= mn;

			if(neg[i] == 0) i++;
			if(pos[j] == 0) j++;
		}

		cout << vec.size() << "\n";

		for(auto it: vec) cout << it.first << " " << it.second.first << " " << it.second.second << "\n";

    }


}



