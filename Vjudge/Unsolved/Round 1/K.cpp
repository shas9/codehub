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

bool pal()
{
	string rts = str;

	reverse(rts.begin(),rts.end());

	return rts == str;
}

bool lucky()
{
	for(auto it: str)
	{
		if(it != '4' && it != '7') return 0;
	}

	return 1;
}

map < ll, ll > mp;
bool dp[100005][25][2][2][2];
bool vis[100005][25][2][2][2];
ll n, k;

bool solve(ll pos, ll dist, bool sec, bool on1, bool on2)
{
//	cout << pos << " " << dist << " " << sec << " " << on1 << " " << on2 << endl;
	if(pos == n) return on2 & on1;

	bool &ret = dp[pos][dist][sec][on1][on2];

	if(vis[pos][dist][sec][on1][on2]) return ret;

	vis[pos][dist][sec][on1][on2] = 1;

	ret = 0;

	if(mp[pos + 1] == sec)
	{
		if(pos == 0) ret |= solve(pos + 1, k + 2, sec, 0, 1);
		else ret |= solve(pos + 1, min(k + 2, dist + 1), sec, 1, on2);
	}
	else if(mp[pos + 1] == (sec ^ 1))
	{
		if(dist >= k)
		{
			if(on2)
			{
				ret |= solve(pos + 1, 1, sec ^ 1, 0, on1);
			}
		}
		else
		{
			ret |= solve(pos + 1, 1,sec ^ 1, 1, on1);
		}
	}
	else if(mp[pos + 1] == 2)
	{
		if(pos == 0) ret |= solve(pos + 1, k + 2, sec, 0, 1);
		else ret |= solve(pos + 1, min(k + 2, dist + 1), sec, 1, on2);

		if(dist >= k)
		{
			if(on2)
			{
				ret |= solve(pos + 1, 1, sec ^ 1, 0, on1);
			}
		}
		else
		{
			ret |= solve(pos + 1, 1,sec ^ 1, 1, on1);
		}
	}

	return ret;


}

int main()
{
    ll i, j, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
		mp.clear();

		for(ll i = 1; i <= n; i++)
		{
			cin >> str;

			if(pal() && lucky())
			{
				mp[i] = 2;
			}
			else if(pal())
			{
				mp[i] = 0;
			}
			else if(lucky())
			{
				mp[i] = 1;
			}
		}

		memset(vis,0,sizeof vis);

//		cout << "pos        dist          sec         on1        on2" << endl;

		if(solve(0,k + 2,0,1,1)) cout << "Yes\n";
		else cout << "No\n";
    }


}


