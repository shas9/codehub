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

map < string, ll > mp1, mp2;

vector < pair < string, ll > > vec;

string name;
ll score;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		mp1.clear();
		vec.clear();

		while(n--)
		{
			cin >> name >> score;

			mp1[name] += score;

			vec.pb({name,score});
		}

		ll mx = mnlld;

		for(auto it: mp1)
		{
			mx = max(mx, it.second);
		}

		mp2.clear();

		for(auto it: vec)
		{
			mp2[it.first] += it.second;

			if(mp1[it.first] == mx)
			{
				if(mp2[it.first] >= mx)
				{
					name = it.first;
					break;
				}
			}
		}

		cout << name << "\n";
    }


}


