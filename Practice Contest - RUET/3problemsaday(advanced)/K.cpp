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

ll vis[103];
vector < pair < pll, ll > > vec;
ll n, m;
string s;

bool place(ll pos)
{
	bool inside = 1, outside = 1;

	if(pos == 38) cout << vec[pos].first.first << " + " << vec[pos].first.second << endl;

	for(ll i = 0; i < pos; i++)
	{
		if(vec[pos].first.first < vec[i].first.first && vec[i].first.first < vec[pos].first.second && vec[i].first.second > vec[pos].first.second)
		{
			if(pos == 38) cout << vec[i].first.first << " * " << vec[i].first.second << " " << vis[vec[i].second] << endl;
			if(vis[vec[i].second] == 1) inside = 0;
			else if(vis[vec[i].second] == 2) outside = 0;
		}
		else if(vec[pos].first.first < vec[i].first.second && vec[i].first.second < vec[pos].first.second && vec[i].first.first < vec[pos].first.first)
		{
			if(pos == 38) cout << vec[i].first.first << " - " << vec[i].first.second << " " << vis[vec[i].second] << endl;
			if(vis[vec[i].second] == 1) inside = 0;
			else if(vis[vec[i].second] == 2) outside = 0;
		}
	}

	if(inside && outside)
	{
		vis[vec[pos].second] = 0;
		for(ll i = 0; i < pos; i++)
		{
			if(vec[pos].first.first < vec[i].first.first && vec[i].first.first < vec[pos].first.second && vec[i].first.second > vec[pos].first.second)
			{
				if(vis[vec[i].second] == 0)
				{
					vis[vec[i].second] = 1;
					vis[vec[pos].second] = 2;
				}
			}
			else if(vec[pos].first.first < vec[i].first.second && vec[i].first.second < vec[pos].first.second && vec[i].first.first < vec[pos].first.first)
			{
				if(vis[vec[i].second] == 0)
				{
					vis[vec[i].second] = 1;
					vis[vec[pos].second] = 2;
				}
			}
		}
		return 1;
	}
	else if(inside)
	{
		for(ll i = 0; i < pos; i++)
		{
			if(vec[pos].first.first < vec[i].first.first && vec[i].first.first < vec[pos].first.second && vec[i].first.second > vec[pos].first.second)
			{
				if(vis[vec[i].second] == 0) vis[vec[i].second] = 2;
			}
			else if(vec[pos].first.first < vec[i].first.second && vec[i].first.second < vec[pos].first.second && vec[i].first.first < vec[pos].first.first)
			{
				if(vis[vec[i].second] == 0) vis[vec[i].second] = 2;
			}
		}
		vis[vec[pos].second] = 1;
		return 1;
	}
	else if(outside)
	{
		for(ll i = 0; i < pos; i++)
		{
			if(vec[pos].first.first < vec[i].first.first && vec[i].first.first < vec[pos].first.second && vec[i].first.second > vec[pos].first.second)
			{
				if(vis[vec[i].second] == 0) vis[vec[i].second] = 1;
			}
			else if(vec[pos].first.first < vec[i].first.second && vec[i].first.second < vec[pos].first.second && vec[i].first.first < vec[pos].first.first)
			{
				if(vis[vec[i].second] == 0) vis[vec[i].second] = 1;
			}
		}
		vis[vec[pos].second] = 2;
		return 1;
	}

	return 0;

}

bool solve()
{
	s = "";

	sort(vec.begin(),vec.end());

	for(ll i = 0; i < m; i++)
	{
		if(place(i) == 0)
		{
			cout << i << endl;
			return 0;
		}
	}

	for(ll i = 0; i < m; i++)
	{
		if(vis[i] == 1) s += 'i';
		else s += 'o';
	}

	return 1;
}

int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		memset(vis,0,sizeof vis);
		vec.clear();

		for(ll i = 0; i < m; i++)
		{
			ll a, b;
			cin >> a >> b;

			if(a > b) swap(a, b);

			vec.push_back({{a,b}, i});
		}

		if(solve()) cout << s << endl;
		else cout << "Impossible" << endl;
    }


}



