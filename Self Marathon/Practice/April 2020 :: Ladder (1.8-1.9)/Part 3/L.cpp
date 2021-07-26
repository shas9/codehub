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

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

vector < set < ll > > vec;
pll freq[103];
vector < ll > perp;
ll n;

bool solve(ll st)
{
	vector < set < ll > > tmp;
	map < ll,ll > mp;

	tmp = vec;

	perp.clear();

	perp.push_back(st);

//	bug;

//	cout << "!! " << st << endl;

	mp[st] = 1;
	for(ll i = 1; i < n; i++)
	{
		for(ll j = 0; j < tmp.size(); j++)
		{
			for(set < ll > :: iterator jt = tmp[j].begin(); jt != tmp[j].end(); jt++)
			{
				if(*jt == st)
				{
					tmp[j].erase(jt);
					break;
				}
			}
		}

//		for(auto it: tmp)
//		{
//			for(auto jt:it) cout << jt << "~~";
//
//			cout << endl;
//		}

		bool no = 1;

		for(auto it: tmp)
		{
			if(it.size() == 1)
			{
				st = *it.begin();
				no = 0;
				break;
			}
		}

		if(no) return 0;

//		cout << st << " ~~ ";

		perp.push_back(st);

		mp[st] = i + 1;

//		cout << st << " ";
	}

	tmp = vec;


	for(auto it: tmp)
	{
		ll mn = mxlld;
		ll mx = 0;
		ll sz = it.size();

		for(auto jt: it)
		{
			mn = min(mn, mp[jt]);
			mx = max(mx, mp[jt]);
		}

		if((mx - mn + 1) != sz) return 0;
	}


	return 1;

}
int main()
{
    ll testcase;
    ll input, flag, tag, ans;

    ll i, j, k, l, m, o, r, q;
//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);

		vec.clear();

		for(i = 1; i < n; i++)
		{
			vec.push_back({});

			slld(input);

			while(input--)
			{
				slld(flag);
				vec.back().insert(flag);
			}
		}

//		for(auto it: vec)
//		{
//			for(auto jt:it) cout << jt << " ";
//
//			cout << endl;
//		}

		for(i = 1; i <= n; i++)
		{
			if(solve(i)) break;
		}

		for(auto it: perp) cout << it << " ";

		cout << "\n";


    }


}



