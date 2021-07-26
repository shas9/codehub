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


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	slld(testcase);

    while(testcase--)
    {
		slld(n);
		vector < ll > vec;
		vec.clear();

		ll nn = 1;
		ll cnt = 0;

		while(cnt + nn <= n)
		{
			cnt += nn;
			vec.push_back(nn);
			nn *= 2;
		}

		if(cnt != n) vec.push_back(n - cnt);

		sort(vec.begin(),vec.end());

		cout << vec.size() - 1 << "\n";

		for(i = 1; i < vec.size(); i++)
		{
			printf("%lld ", vec[i] - vec[i - 1]);
		}

		printf("\n");
    }


}


