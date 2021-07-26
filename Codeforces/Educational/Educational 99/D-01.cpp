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

vector < ll > vec, arr;

ll solve(ll idx, ll m)
{
	ll cnt = 0;
	ll j = -1;

	vector < ll > arr1 = arr;

//	cout << idx << endl;

	for(ll i = 0; i < vec.size(); i++)
	{
		if(i == idx) continue;
		j++;

//		cout << arr[j] << " -- " << m << endl;

		if(arr1[j] == vec[i]);
		else if(m == vec[i] && arr1[j] > m)
		{
//			bug;
			swap(arr1[j], m);
			cnt++;
		}
		else
		{
			return mxlld;
		}

//		cout << m << " " << i << endl;
	}

	return cnt;
}


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
		cin >> n >> m;

		vec.clear();
		arr.clear();

		arr.resize(n);

		for(auto &it: arr) cin >> it;

		vec = arr;
		vec.push_back(m);

		sort(vec.begin(),vec.end());

		ans = mxlld;

//		for(ll i = 0; i < vec.size(); i++) cout << vec[i] << " ";
//		cout << endl;

		for(ll i = 0; i < vec.size(); i++)
		{
			ans = min(ans, solve(i, m));
		}

		if(ans == mxlld) ans = -1;

		cout << ans << "\n";
    }


}


