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

ll order[30];
string str[105];

bool isprefix(ll x, ll y)
{
	if(str[x].size() > str[y].size()) return 0;

	for(ll i = 0; i < str[x].size(); i++)
	{
		if(str[x][i] != str[y][i]) return 0;
	}

	return 1;
}

vector < ll > g[30];
ll indegree[30];

bool topsort()
{
	queue < ll > q;

	for(ll i = 0; i < 26; i++)
	{
		if(indegree[i] == 0) q.push(i);
	}

	ll num = 0;

	while(!q.empty())
	{
		ll top = q.front();
		q.pop();

		order[top] = num++;

		for(auto it: g[top])
		{
			indegree[it]--;

			if(indegree[it] == 0) q.push(it);
		}
	}

	return (num != 26);
}

bool solve(ll n)
{
	ll num = 0;
	memset(indegree,0,sizeof indegree);

	for(ll i = 0; i < 26; i++) g[i].clear();

	for(ll i = 1; i < n; i++)
	{
		if(str[i] == str[i - 1]) continue;
		if(isprefix(i - 1, i)) continue;
		if(isprefix(i, i - 1)) return 1;

		for(ll j = 0; j < min(str[i - 1].size(), str[i].size()); j++)
		{
			if(str[i - 1][j] == str[i][j]) continue;

			ll x = str[i - 1][j] - 'a';
			ll y = str[i][j] - 'a';

			g[x].push_back(y);
			indegree[y]++;

			break;
		}
	}

	return topsort();
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
		memset(order, -1, sizeof order);

		for(ll i = 0; i < n; ++i) cin >> str[i];

		if(solve(n))
		{
			cout << "Impossible\n";
			continue;
		}

		for(ll i = 0; i < 26; i++)
		{
			for(ll j = 0; j < 26; j++)
			{
				if(order[j] == i)
				{
					cout << (char)(j + 'a');
					break;
				}
			}
		}

		cout << "\n";

    }


}


