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

vector < ll > v1, v2;
string s[200005];
vector < ll > v3;
map < string, bool > mp;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		mp.clear();
		v1.clear();
		v2.clear();
		v3.clear();
		bool mark[2];
		mark[1] = mark[0] = 0;


		for(i = 1; i <= n; i++)
		{
			cin >> s[i];

			if(s[i].front() == s[i].back()) mark[s[i].front() - '0'] = 1;
			else
			{
				if(s[i].front() - '0' == 0) v1.push_back(i);
				else v2.push_back(i);
			}

			mp[s[i]] = 1;
		}

		ll diff = abs((int)v1.size() - (int)v2.size());

		if(mark[0] && mark[1] && v1.empty() && v2.empty())
		{
			cout << -1 << "\n";
			continue;
		}

//		cout << diff << endl;

		while(diff > 1)
		{
			if(v1.size() > v2.size())
			{
				for(ll it: v1)
				{
					string tmp = s[it];

					reverse(tmp.begin(),tmp.end());

					if(mp.find(tmp) != mp.end()) continue;

					diff -= 2;

					mp[tmp] = 1;

					v3.push_back(it);

					if(diff <= 1) break;
				}
			}
			else
			{
				for(ll it: v2)
				{
					string tmp = s[it];

					reverse(tmp.begin(),tmp.end());

					if(mp.find(tmp) != mp.end()) continue;

					diff -= 2;

					mp[tmp] = 1;

					v3.push_back(it);

					if(diff <= 1) break;
				}
			}
		}

		cout << v3.size() << "\n";

		for(auto it: v3) cout << it << " ";

		cout << "\n";
    }


}



