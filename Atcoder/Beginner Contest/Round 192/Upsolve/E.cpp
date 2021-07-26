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

vector < ll > seq;
vector < vector < ll > > db;
vector < pll > tochange;
vector < pll > tochange2;

bool match(ll lim)
{
	for(auto it: db)
	{
		ll diff = 0;

		for(ll i = 0; i < it.size(); i++)
		{
			diff += seq[i] != it[i];
		}

		if(diff == lim && lim == 4 && tochange.empty())
		{
			for(ll i = 0; i < it.size(); i++)
			{
				if(seq[i] != it[i]) tochange.push_back({i,it[i]});
			}
		}

		if(diff == lim && lim == 3 && tochange.empty())
		{
			for(ll i = 0; i < it.size(); i++)
			{
				if(seq[i] != it[i]) tochange.push_back({i,it[i]});
			}
		}

		if(diff == 3 && lim == 2 && tochange2.empty())
		{
			for(ll i = 0; i < it.size(); i++)
			{
				if(seq[i] != it[i]) tochange2.push_back({i,it[i]});
			}
		}

		if(diff > lim) return 0;
	}

	return 1;
}

bool solve4()
{
	for(ll i = 0; i < 4; i++)
	{
		for(ll j = i + 1; j < 4; j++)
		{
			seq[tochange[i].first] = tochange[i].second;
			seq[tochange[j].first] = tochange[j].second;

			if(match(2)) return 1;

			seq[tochange[i].first] = db.front()[tochange[i].first];
			seq[tochange[j].first] = db.front()[tochange[j].first];
		}
	}

	return 0;
}


bool solve2()
{
	if(tochange2.empty()) return 0;

	assert(tochange2.size() == 3);

	for(auto it: tochange2)
	{
		ll x = seq[it.first];
		seq[it.first] = it.second;

		if(match(2)) return 1;

		seq[it.first] = x;
	}

	return 0;
}

bool solve3()
{
	assert(tochange.size() == 3);

	for(auto it: tochange)
	{
		seq[it.first] = it.second;
		tochange2.clear();

		if(match(2)) return 1;

		if(solve2()) return 1;

		seq[it.first] = db.front()[it.first];
	}

	return 0;
}

bool solve()
{
	seq = db.front();
	tochange.clear();

	if(match(2)) return 1;
	if(match(4) == 0) return 0;

	if(!tochange.empty()) return solve4();

	assert(match(3));

	return solve3();

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
		db.clear();
		seq.clear();

		for(ll i = 0; i < n; i++)
		{
			db.push_back({});

			for(ll j = 0; j < m; j++)
			{
				cin >> input;
				db.back().push_back(input);
			}
		}

		if(solve())
		{
			cout << "Yes\n";
			for(auto it: seq) cout << it << " ";
			cout << "\n";
		}
		else
		{
			cout << "No\n";
		}
    }


}


