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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	srand(time(NULL));

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		string str;

		cin >> str;

		vector < ll > v;

		for(auto it: str) v.push_back(it);

		ans = 0;

		for(ll i = 0; i + 1 < v.size(); i++)
		{
			bool x = 0;
			bool y = 0;

			if(v[i] == v[i + 1])
			{
				ans++;
				v[i + 1] = (rand() * 1LL * rand());
			}

			if(i + 2 < v.size())
			{
				if(v[i] == v[i + 2])
				{
					ans++;
					v[i + 2] = (rand() * 1LL * rand());
				}
			}

//			for(auto it: v) cout << it << " ";
//			cout << "\n";
		}

		cout << ans << "\n";
    }


}


