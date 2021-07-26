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

string str;
ll freq[30];
string out;

bool solve(ll n, ll m)
{
	memset(freq,0,sizeof freq);

	for(auto it: str) freq[it - 'a']++;

	out = str;

	ll extra = 0;

	for(ll i = 0; i < 26; i++) extra += (m - freq[i] % m) % m;

	if(extra == 0) return 1;

	for(ll i = n - 1; i >= 0; i--)
	{
		out.pop_back();

		ll val = str[i] - 'a';

		extra -= (m - freq[val] % m) % m;
		freq[val]--;
		extra += (m - freq[val] % m) % m;

		for(ll j = val + 1; j < 26; j++)
		{
			extra -= (m - freq[j] % m) % m;
			freq[j]++;
			extra += (m - freq[j] % m) % m;

			ll diff = (n - extra - i - 1);

//			cout << i << " " << j << " " << extra << " " << diff << endl;
//
			if(diff >= 0 && diff % m == 0)
			{
				out.push_back(j + 'a');

				for(ll k = 1; k <= diff; k++) out += 'a';

				for(ll k = 0; k < 26; k++)
				{
					while((m - freq[k] % m) % m)
					{
						out += k + 'a';
						freq[k]++;
					}
				}

				return 1;
			}

			extra -= (m - freq[j] % m) % m;
			freq[j]--;
			extra += (m - freq[j] % m) % m;
		}
	}

	return 0;
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
		cin >> str;

		if(solve(n,m)) cout << out << "\n";
		else cout << -1 << "\n";
    }


}


