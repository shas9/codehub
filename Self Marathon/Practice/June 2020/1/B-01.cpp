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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

vector < ll > vec;
map < ll, vector < ll > > mp;
vector < ll > g[1003];

void reconstruct()
{
	mp.clear();

	for(ll i = 0; i < vec.size(); i++) mp[vec[i]].push_back(i);

	ll num = 0;

	for(auto it: mp)
	{
		for(auto jt: it.second)
		{
			vec[jt] = ++num;
		}
	}

//	for(auto it: vec) cout << it << "--";
//
//	cout << endl;
}

void inversion()
{
	for(ll i = 1; i <= vec.size(); i++) g[i].clear();

	for(ll i = 0; i < vec.size(); i++)
	{
		for(ll j = i + 1; j < vec.size(); j++)
		{
			if(vec[j] < vec[i]) g[j].pb(i);
		}
	}
}

vector < pll > ans;

bool sorted()
{
	vector < ll > svec;

	svec = vec;

	sort(svec.begin(),svec.end());

	return svec == vec;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		vec.clear();

		vec.resize(n);

		for(ll i = 0; i < n; i++) cin >> vec[i];

		reconstruct();

		inversion();

		ans.clear();

		for(ll i = n - 1; i >= 0; i--)
		{
			vector < pll > tmp;

			tmp.clear();

			for(auto it: g[i])
			{
				tmp.push_back({vec[it],it});
			}

			sort(tmp.begin(),tmp.end());

			for(auto it: tmp)
			{
				swap(vec[it.second],vec[i]);

				ans.push_back({it.second + 1,i + 1});
			}
		}

		assert(sorted());

		cout << ans.size() << '\n';

		for(auto it : ans)
		{
			cout << it.first << " " << it.second << '\n';
		}
    }


}


