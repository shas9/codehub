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

map < string, ll > mp;
vector < string > vec;

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
		vec.clear();
		mp.clear();

		slld(n);

		while(n--)
		{
			string s;
			cin >> s;

			vec.pb(s);
			mp[s]++;
		}

		ans = 0;
		for(k = 0; k < vec.size(); k++)
		{
			string it = vec[k];

			if(mp[it] == 1) continue;

			string tt = it;

			for(i = 0; i < 4; i++)
			{
				string t = it;

				for(j = 0; j < 9; j++)
				{
					t[i] = (j + '0');

					if(mp[t] == 0) break;
				}

				if(mp[t] == 0)
				{
					tt = t;
				}
			}

			mp[tt] = 1;

			ans++;

			mp[vec[k]]--;

			vec[k] = tt;
		}

		cout << ans << "\n";

		for(auto it:vec) cout << it << "\n";
    }


}



