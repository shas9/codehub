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

vector < ll > vec;
map < ll, ll > first, last;

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

		{
			vec.clear();
			first.clear();
			last.clear();
		}

		for(i = 0; i < n; i++)
		{
			slld(input);
			vec.push_back(input);

			if(first.find(input) == first.end()) first[input] = i;
		}

		for(i = n - 1; i >= 0; i--)
		{
			input = vec[i];
			if(last.find(input) == last.end()) last[input] = i;
		}

		sort(vec.begin(),vec.end());

//		for(auto it: vec) cout << it << " ";
//
//		cout << endl;

		unique(vec.begin(),vec.end());

		vec.resize(first.size());

//		for(auto it: vec) cout << it << " ";
//
//		cout << endl;

		ans = 1;
		ll cnt = 1;

		for(i = 1; i < vec.size(); i++)
		{
//			cout << first[vec[i]] << " " << last[vec[i - 1]] << endl;

			if(first[vec[i]] > last[vec[i - 1]]) cnt++;
			else cnt = 1;

			ans = max(ans,cnt);
		}

		ans = vec.size() - ans;

		printf("%lld\n", ans);

    }


}



