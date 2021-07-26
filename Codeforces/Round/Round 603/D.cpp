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

vector < ll > vec[28];
bool vis[200005];
bool vis2[27];
vector < string > vecs;
string str;

void dfs(ll num)
{
	vis[num] = 1;

	for(auto it: vecs[num])
	{
		if(vis2[it - 'a']) continue;

		vis2[it - 'a'] = 1;

 		for(auto jt: vec[it - 'a'])
		{
			if(vis[jt]) continue;

			dfs(jt);
		}
	}
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(i = 0; i <= 26; i++) vec[i].clear();
		vecs.clear();

		for(i = 0; i < n; i++)
		{
			cin >> str;
			vecs.push_back(str);

			for(auto it: str)
			{
				vec[it - 'a'].pb(i);
			}
		}

		memset(vis,0,sizeof vis);
		memset(vis2,0,sizeof vis2);

		ans = 0;

		for(i = 0; i < n; i++)
		{
			if(vis[i]) continue;

			dfs(i);
			ans++;
		}

		printf("%lld\n", ans);
    }


}



