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

map < string, ll > mp;
ll in[100005];
vector < ll > gf[100005];

vector < ll > g[100005];
vector < ll > sq;

string str;

void build(ll idx, string s)
{
//	cout << s.size() << " " << str.size() << "\n";

//	if(s.size() > str.size()) return;

	if(s.size() == str.size())
	{
		if(mp.find(s) != mp.end())
		{
			g[idx].push_back(mp[s]);
		}

		return;
	}

	build(idx, s + '_');
	build(idx, s + str[s.size()]);
}

vector < pair < string, ll > > mtj;
vector < string > vv;

bool solve(ll n)
{
//	bug;
	for(auto it: mtj)
	{
		for(ll j = 0; j < it.first.size(); j++)
		{
			if(vv[it.second - 1][j] == '_') continue;
			if(it.first[j] != vv[it.second - 1][j]) return 0;
		}
	}


	sq.clear();

	for(ll i = 1; i <= n; i++) gf[i].clear();

	for(ll i = 0; i < mtj.size(); i++)
	{
		for(auto it: g[i + 1])
		{
			if(it != mtj[i].second)
			{
				in[it]++;
				gf[mtj[i].second].push_back(it);
			}
		}
	}

	queue < ll > qq;

	for(ll i = 1; i <= n; i++)
	{
		if(in[i] == 0) qq.push(i);
	}

//	bug;

	while(!qq.empty())
	{
		ll top = qq.front();
		sq.push_back(top);
		qq.pop();

		for(auto it: gf[top])
		{
			in[it]--;

			if(in[it] == 0)
			{
				qq.push(it);
			}

			if(in[it] < 0) return 0;
		}
	}

	return sq.size() == n;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
		mtj.clear();
		mp.clear();
		vv.clear();

		for(ll i = 1; i <= n; i++)
		{
			cin >> str;

			in[i] = 0;

			mp[str] = i;

			vv.push_back(str);
		}

		for(ll i = 1; i <= m; i++)
		{
			g[i].clear();

			cin >> str;

			build(i, "");

			ll x;

			cin >> x;

			mtj.push_back({str,x});
		}

//		bug;

		if(solve(n))
		{
			cout << "YES\n";

			for(auto it: sq) cout << it << " ";

			cout << "\n";
		}
		else
		{
			cout << "NO\n";
		}
    }


}




