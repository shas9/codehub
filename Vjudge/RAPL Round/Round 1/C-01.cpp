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

ll dp[15][(1 << 15)];
string str;

ll solve(ll pos, ll mask)
{
	if(pos == str.size()) return 1;

	ll &ret = dp[pos][mask];

	if(ret != -1) return ret;

	ret = 0;

	for(ll i = 0; i < str.size(); i++)
	{
		if(!check(mask,i))
		{
			ret += solve(pos + 1, Set(mask,i));
		}
	}

	return ret;
}

void brute(string s)
{
	ll cnt = 1;

	string x = s;
	while(1)
	{
		next_permutation(s.begin(),s.end());
		if(x == s) break;
		cnt++;
	}

	cout << cnt << endl;
}

ll fact[100];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	while(cin >> str)
	{
		fact[0] = 1;

		for(ll i = 1; i <= 14; i++) fact[i] = fact[i - 1] * i;

//		brute(str);

		memset(dp,-1,sizeof dp);

		ans = solve(0,0);

		ll freq[30];

		memset(freq,0,sizeof freq);

		for(auto it: str) freq[it - 'A']++;

//		cout << ans << '\n';

		for(ll i = 0; i < 26; i++) if(freq[i]) ans /= fact[freq[i]];

		cout << ans << '\n';
	}


}



