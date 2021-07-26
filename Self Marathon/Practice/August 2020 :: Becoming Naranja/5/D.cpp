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

vector < pll > neg, pos;
vector < ll > z;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		neg.clear();
		z.clear();
		pos.clear();

		for(ll i = 0; i < n; i++)
		{
			cin >> input;

			if(input == 0) z.push_back(i + 1);
			else if(input < 0) neg.push_back({input,i+1});
			else pos.push_back({input,i+1});
		}

		sort(neg.begin(),neg.end());
		sort(pos.begin(),pos.end());

		for(ll i = 1; i < z.size(); i++) cout << 1 << " " << z[i - 1] << " " << z[i] << "\n";

		if(neg.size() & 1)
		{
			if(z.size()) cout << 1 << " " << z.back() << " " << neg.back().second << "\n";

			if(!pos.empty() || neg.size() > 1) cout << 2 << " " << neg.back().second << '\n';

			neg.pop_back();

		}
		else if(z.size())
		{
			if(!pos.empty() || neg.size() > 1) cout << 2 << " " << z.back() << "\n";
		}

		for(ll i = 1; i < pos.size(); i++) cout << 1 << " " << pos[i - 1].second << " " << pos[i].second << "\n";
		for(ll i = 1; i < neg.size(); i++) cout << 1 << " " << neg[i - 1].second << " " << neg[i].second << "\n";

		if(!neg.empty() && !pos.empty())
		{
			cout << 1 << " " << neg.back().second << " " << pos.back().second << "\n";
		}
    }


}



