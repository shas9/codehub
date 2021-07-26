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

vector < pair < ll, pair < ll, char > > > pos, neg;

string str;

bool comp(pair < ll, pair < ll, char > > a, pair < ll, pair < ll, char > > b)
{
	return a.first - a.second.first < b.first - b.second.first;
}

bool solve()
{
	ll tot = 0;

	for(auto it: pos) tot += it.second.first;
	for(auto it: neg) tot += it.second.first;

	if(tot) return 0;

	sort(pos.rbegin(),pos.rend());

	tot = 0;

	for(auto it: pos)
	{
		if(tot + it.first < 0) return 0;

		tot += it.second.first;
	}

//	cout << tot << endl;

	sort(neg.begin(),neg.end(),comp);

	for(auto it: neg)
	{
		if(tot + it.first < 0) return 0;

		tot += it.second.first;
	}

	return 1;
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
		pos.clear();
		neg.clear();

		for(i = 1; i <= n; i++)
		{
			cin >> str;

			ll mn = str.size();
			ll sum = 0;

			for(auto it: str)
				if(it == '(') sum++, mn = min(mn,sum);
				else sum--, mn = min(mn, sum);

			if(sum > 0) pos.push_back({mn,{sum,str.back()}});
			else neg.push_back({mn,{sum,str.back()}});
		}

		if(solve()) printf("Yes\n");
		else printf("No\n");
    }


}


