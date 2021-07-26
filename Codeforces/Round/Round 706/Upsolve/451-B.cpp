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

vector < ll > v1, v2, v3;
map < ll, ll > mp;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		v1.clear();
		v2.clear();
		v3.clear();
		mp.clear();

		for(ll i = 1; i <= n; i++)
		{
			cin >> input;
			v1.push_back(input);
		}

		v2 = v1;

		sort(v2.begin(), v2.end());

		for(ll i = 0; i < n; i++) mp[v2[i]] = i;

		ll u = 1, v = 1;

		for(ll i = 0; i < n; i++)
		{
			if(v1[i] != v2[i])
			{
				ll idx = mp[v1[i]];

//				cout << idx << endl;

				for(ll j = idx; j >= i; j--)
				{
					v3.push_back(v1[j]);
				}

				for(ll j = idx + 1; j < n; j++)
				{
					v3.push_back(v1[j]);
				}

				u = i + 1;
				v = idx + 1;

				break;
			}

			v3.push_back(v1[i]);
		}

//		for(auto it: v3) cout << it << " ";
//		cout << endl;

		if(v2 == v3) cout << "yes\n" << u << " " << v << "\n";
		else cout << "no\n";
    }


}


