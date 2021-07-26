 // God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll int
#define ull unsigned long long
#define pll pair < int,int >

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

const ll lim = 2500000;
vector < ll > f[lim + 6];
pll idx[2 * lim + 6];
vector < ll > v;
vector < ll > vec;

bool solve(ll n)
{
	v.clear();

	for(ll i = 1; i <= lim; i++)
	{
		if(f[i].size() >= 4)
		{
			for(ll j = 0; j < 4; j++)
			{
				v.push_back(f[i][j]);
			}

			return 1;
		}
	}

	vector < ll > tmp;
	ll num = -1;

//	bug;

	for(ll i = 1; i <= lim; i++)
	{
		if(f[i].size() >= 2)
		{
			if(tmp.empty())
			{
				num = i;
				tmp.pb(f[i].front());
				tmp.pb(f[i].back());
			}
			else
			{
//				cout << num << " " << i << endl;
				v.push_back(f[i].front());
				v.push_back(tmp.front());

				v.push_back(f[i].back());
				v.push_back(tmp.back());

				return 1;
			}
		}
	}

//	bug;

	if(!tmp.empty())
	{
		for(ll i = 1; i <= lim; i++)
		{
			if(i == num) continue;

			if(f[i].empty()) continue;

			if(i >= (2 * num)) break;

			if((2 * num - i) > lim) continue;

			if(f[2 * num - i].empty()) continue;

			v.push_back(tmp.front());
			v.push_back(tmp.back());
			v.push_back(f[i].front());
			v.push_back(f[2 * num - i].front());

			return 1;
		}
	}

	for(ll i = 1; i <= lim * 2; i++) idx[i] = {-1,-1};

	map < ll, ll > mp;

	for(auto &it: vec)
	{
		if(mp[it]) it = -1;
		else mp[it] = 1;
	}

	for(ll i = 0; i < n; i++)
	{
		if(vec[i] == -1) continue;
		for(ll j = i + 1; j < n; j++)
		{
			if(vec[j] == -1) continue;
			if(idx[vec[i] + vec[j]].first != -1)
			{
//				cout << vec[i] + vec[j] << '\n';
				v.push_back(i);
				v.push_back(j);
				v.push_back(idx[vec[i] + vec[j]].first);
				v.push_back(idx[vec[i] + vec[j]].second);

				return 1;
			}

			idx[vec[i] + vec[j]] = {i,j};

		}
	}

	return 0;

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
		for(ll i = 1; i <= lim; i++) f[i].clear();
		vec.resize(n);

		for(ll i = 0; i < n; i++)
		{
			cin >> input;
			f[input].push_back(i);
			vec[i] = input;
		}

		if(solve(n) == 0) cout << "NO\n";
		else
		{
			cout << "YES\n";
			for(auto it: v) cout << it + 1 << " ";
			cout << "\n";
		}
    }


}



