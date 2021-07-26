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

string str[20];
string out;

ll dp[12][(1 << 12)];
ll n, m;

string conv(ll x)
{
	out = "";

	while(x >= 26)
	{
		out += ((x % 26) + 'a');

		x /= 26;
	}

	return out;
}

ll solve(ll pos, ll mask)
{
	if(pos >= m) return 1;

	ll &ret = dp[pos][mask];

	if(ret) return ret;

	ret = 0;

	set < char > st;

	for(int i = 0; i < n; i++)
	{
		if(check(mask,i))
		{
			st.insert(str[i][pos]);
		}
	}

	if(st.size() >= 2) return ret = -1;

	if(st.size() == 0)
	{
		for(int i = 0; i < 26; i++)
		{
			ll nmask = 0;

			for(int j = 0; j < n; j++)
			{
				ll cc = str[j][pos] - 'a';

				if(cc != i) nmask = Set(nmask,j);
			}

			ret = solve(pos + 1, nmask);

			if(ret != -1)
			{
//				cout << i << " && " << pos << endl;
				return ret = (ret * 26) + i;
			}
		}

		return ret = -1;
	}

	char c = *st.begin();

	ll nmask = mask;

	for(int i = 0; i < n; i++)
	{
		if(str[i][pos] != c) nmask = Set(nmask, i);
	}

	ret = solve(pos + 1, nmask);

	if(ret == -1) return ret;

	ret = (ret * 26) + (c - 'a');

	return ret;
}
int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		slld(m);

		for(i = 0; i < n; i++) cin >> str[i];

		memset(dp,0,sizeof dp);

		ans = solve(0,0);

		if(ans == -1) cout << ans << '\n';
		else
		{
			cout << conv(ans) << '\n';
		}

    }


}



