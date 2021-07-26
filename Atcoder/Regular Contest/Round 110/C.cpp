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

map < ll, ll > mp;
vector < ll > vec;
map < ll, bool > mark;
vector < ll > ans;

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
		mp.clear();
		mark.clear();
		ans.clear();

		vec.resize(n + 3);

		for(ll i = 1; i <= n; i++)
		{
			cin >> vec[i];

			mp[vec[i]] = i;
		}

		bool no = 0;

		for(ll i = 1; i <= n; i++)
		{
			ll pos = mp[i];

//			cout << i << ": " << pos << "\n";

			while(pos != i)
			{
				if(mark.find(pos) != mark.end())
				{
					no = 1;
					break;
				}

				ans.push_back(pos);
				mark[pos] = 1;
				swap(vec[pos], vec[pos - 1]);
				mp[vec[pos]] = pos;
				mp[vec[pos - 1]] = pos - 1;

				pos--;
			}

			if(no) break;
		}

		for(ll i = 2; i <= n; i++) if(mark[i] == 0) no = 1;

		if(no) cout << -1 << "\n";
		else
		{
			for(auto it: ans) cout << it - 1 << "\n";
		}

    }


}



