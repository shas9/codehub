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

vector < ll > v;
map < ll, ll > mp;
vector < pll > seq;

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
		v.clear();
		mp.clear();
		seq.clear();

		cin >> n;

		ll x = n;

		while(x > 2)
		{
			v.push_back(x);
			mp[x] = 1;

			ll y = x / 10;

			if(x % 10) y++;

			x = y;
		}

		cout << v.size() << "\n";

		for(ll i = n - 1; i >= 3; i--)
		{
			if(mp[i]) continue;

			seq.push_back({i,n});
		}

//		cout << seq.size() << " " << v.size() << " " << v.front() << "\n";

		for(ll i = v.size() - 2; i >= 0; i--)
		{
			seq.push_back({v[i + 1], v[i]});
		}

//		cout << seq.size() << " " << v.size() << " " << v.front() << "\n";

		for(ll i = v.size() - 2; i >= 1; i--)
		{
			seq.push_back({v[i + 1], v[i]});
		}

//		cout << seq.size() << " " << v.size() << " " << v.front() << "\n";

		x = -1;
		if(!v.empty()) x = v.back();

		while(x > 1)
		{
			ll y = x / 2;
			if(x & 1) y++;
			x = y;

			seq.push_back({v.back(),2LL});
		}

		cout << seq.size() << "\n";

		for(auto it: seq) cout << it.first << " " << it.second << "\n";


    }


}


