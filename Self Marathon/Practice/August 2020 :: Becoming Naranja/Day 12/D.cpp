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

vector < ll > vec;

vector < pll > exam;

bool comp(pll a, pll b)
{
	if(a.second != b.second) return a.second < b.second;
	return a.first < b.first;
}

multiset < ll > mset;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		vec.clear();
		exam.resize(n);
		mset.clear();

		for(auto &it: exam)
		{
			cin >> it.first >> it.second;
			vec.push_back(it.first);
		}

		sort(exam.begin(),exam.end(),comp);
		sort(vec.begin(),vec.end());

		ll idx = 0;

		for(auto it: exam)
		{
			while(vec[idx] <= it.second) idx++;

			if(it.first == vec[idx])
			{
				idx++;
				continue;
			}
		}

		if(idx == n) cout << exam.back().second << "\n";
		else cout << vec.back() << "\n";
    }


}



