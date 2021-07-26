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

ll arr[200005];
vector < ll > avail[200005];
ll cnt[200005];
pll choice[200005];

vector < ll > vec;
bool vis[200005];
bool solve(ll n, ll m)
{
	queue < ll > qq;

	for(ll i = 1; i <= n; i++) cnt[i] = avail[i].size();

	for(ll i = 1; i <= n; i++) if(arr[i] >= cnt[i] && cnt[i]) qq.push(i);

	memset(vis,0,sizeof vis);
	vec.clear();

	while(!qq.empty())
	{
		ll top = qq.front();
		qq.pop();

		for(auto it: avail[top])
		{
			if(vis[it] == 0)
			{
				vis[it] = 1;
				vec.push_back(it);

				cnt[choice[it].first]--;
				cnt[choice[it].second]--;

				if(cnt[choice[it].first] == arr[choice[it].first]) qq.push(choice[it].first);
				if(cnt[choice[it].second] == arr[choice[it].second]) qq.push(choice[it].second);
			}
		}
	}

	reverse(vec.begin(),vec.end());

	return vec.size() == m;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		for(i = 1; i <= n; i++) avail[i].clear();
		for(i = 1; i <= n; i++) slld(arr[i]);

		for(i = 1; i <= m; i++)
		{
			slld(choice[i].first);
			slld(choice[i].second);

			avail[choice[i].first].pb(i);
			avail[choice[i].second].pb(i);
		}

		if(solve(n,m) == 0) printf("DEAD\n");
		else
		{
			printf("ALIVE\n");

			for(auto it: vec) cout << it << ' ';

			cout << '\n';
		}
    }


}



