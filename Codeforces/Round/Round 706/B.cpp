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
		mp.clear();
		ll now = 0;
		ll mx = 0;

		cin >> n >> m;

		for(ll i = 1; i <= n; i++)
		{
			cin >> input;
			mp[input] = 1;
			mx = max(mx, input);
		}

		while(mp.find(now) != mp.end()) now++;

		if(now > mx)
		{
			cout << mp.size() + m << "\n";
			continue;
		}

		for(ll i = 1; i <= m; i++)
		{
			ll add = (mx + now) / 2;

			if((mx + now) & 1) add++;

			mx = max(mx, add);

//			cout << now << " " << mx << " " << add << endl;

			if(mp.find(add) != mp.end()) break;

			mp[add] = 1;

			while(mp.find(now) != mp.end()) now++;
		}

		cout << mp.size() << "\n";
    }


}



