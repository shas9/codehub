#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

string str;

bool comp(ll ch, ll idx)
{

	if(idx < 0) return 0;

	ll dh = str[idx] - 'a';

//	cout << ch << " " << idx << " " << str[idx] << " " << dh << endl;

	return ch == dh;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {

		cin >> str;

		ll pos = -1;

		for(i = n - 1; i >= 0; i--)
		{
			for(ll j = str[i] - 'a' + 1; j < m; j++)
			{
				if(comp(j,i-1) || comp(j,i-2)) continue;

				str[i] = (j + 'a');

				pos = i;
				break;
			}

			if(pos != -1) break;

		}

		if(pos == -1)
		{
			cout << "NO" << "\n";
			continue;
		}

		for(i = pos + 1; i < n; i++)
		{
			for(j = 0; j < m; j++)
			{
				if(comp(j,i-1) || comp(j,i - 2)) continue;

				str[i] = (j + 'a');
				break;
			}
		}

		cout << str << "\n";
    }



}



