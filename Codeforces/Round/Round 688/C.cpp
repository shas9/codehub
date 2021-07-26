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

char grid[2003][2003];

vector < pll > vec[10];

ll row(ll num, pll idx)
{
	ll lo = 0;
	ll hi = vec[num].size() - 1;
	ll bam = 0;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(vec[num][mid].second < idx.second) lo = mid + 1;
		else
		{
			hi = mid - 1;
			bam = mid;
		}
	}

	lo = 0;
	hi = vec[num].size() - 1;
	ll dan = 0;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(vec[num][mid].second > idx.second) hi = mid - 1;
		else
		{
			lo = mid + 1;
			dan = mid;
		}
	}

	return max(idx.second - vec[num][bam].second, vec[num][dan].second - idx.second);
}

ll roww(ll num, pll idx)
{
	ll lo = 0;
	ll hi = vec[num].size() - 1;
	ll bam = 0;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(vec[num][mid].first < idx.second) lo = mid + 1;
		else
		{
			hi = mid - 1;
			bam = mid;
		}
	}

	lo = 0;
	hi = vec[num].size() - 1;
	ll dan = 0;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(vec[num][mid].second > idx.second) hi = mid - 1;
		else
		{
			lo = mid + 1;
			dan = mid;
		}
	}

	return max(idx.second - vec[num][bam].second, vec[num][dan].second - idx.second);
}

bool comp(pll a, pll b)
{
	if(a.second == b.second) return a.first < b.first;

	return a.second < b.second;
}

ll n;

ll solve1(ll idx)
{
	vector < pll > v1, v2;

	for(auto it: vec[idx])
	{
		if(it.first == vec[idx].front().first) v1.push_back(it);
		if(it.first == vec[idx].back().first) v2.push_back(it);
	}

	ll ret = 0;

	for(auto it: v1)
	{
		for(auto jt: v2)
		{
			ll area = (jt.second - it.second) * max(max(it.first - 1, n - it.first), max(jt.first - 1, n - jt.first));
			ret = max(ret, area);
		}
	}

	return ret;
}

ll solve2(ll idx)
{
	vector < pll > v1, v2;

	for(auto it: vec[idx])
	{
		if(it.second == vec[idx].front().second) v1.push_back(it);
		if(it.second == vec[idx].back().second) v2.push_back(it);
	}

	ll ret = 0;

	for(auto it: v1)
	{
		for(auto jt: v2)
		{

			ll area = (jt.first - it.first) * max(max(it.second - 1, n - it.second), max(jt.second - 1, n - jt.second));


//			if(idx == 9) cout << it.first << " " << it.second << " & " << jt.first << " " << jt.second << " " << area << "\n";
			ret = max(ret, area);
		}
	}

	return ret;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		for(ll i = 0; i <= 9; i++) vec[i].clear();

		cin >> n;

		for(ll i = 1; i <= n; i++) cin >> grid[i] + 1;

//		bug;

		for(ll i = 1; i <= n; i++)
		{
			for(ll j = 1; j <= n; j++)
			{
				vec[grid[i][j] - '0'].push_back({i,j});
			}
		}

		for(ll i = 0; i <= 9; i++)
		{
			ll mx = 0;

			if(vec[i].size() < 2)
			{
				cout << 0 << " ";
				continue;
			}

			sort(vec[i].begin(), vec[i].end());

			ll h1 = solve1(i);

			sort(vec[i].begin(), vec[i].end(), comp);

			ll h2 = solve2(i);

			cout << max(h1, h2) << " ";
		}

		cout << "\n";
    }


}


