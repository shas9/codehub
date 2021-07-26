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

set < pll > st;
ll arr[200005];

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

		st.clear();

		st.insert({-n,1});

		ll cnt = 0;

		while(!st.empty())
		{
			pll x = *st.begin();
			st.erase(st.begin());

			x.first *= -1;
			l = x.second;
			r = x.second + x.first - 1;

//			if(cnt <= 10)cout << l << " " << r << endl;

			ll idx = 0;

			if((r - l + 1) % 2) idx = (l + r) / 2;
			else idx = (l + r - 1) / 2;

			arr[idx] = ++cnt;

			ll sz1 = (idx - l);
			ll sz2 = (r - idx);

//			cout << idx << " " << sz1 << " ~~ " << sz2 << endl;

			if(sz1 > 0) st.insert({-sz1,l});
			if(sz2 > 0) st.insert({-sz2,idx + 1});
		}

		for(i = 1; i <= n; i++) cout << arr[i] << " ";

		cout << "\n";
    }


}



