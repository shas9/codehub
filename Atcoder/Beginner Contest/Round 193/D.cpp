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

ll cnt1[10], cnt2[10];
ll cnt[10];

string s, t;
ll pw10[10];
ll tot;

bool solve(ll x, ll y, ll n)
{
	cnt1[x]++;
	cnt2[y]++;

	ll ret1 = 0;
	ll ret2 = 0;

//	for(ll i = 1; i <= 9; i++) cout << cnt1[i] << " + ";
//	cout << "\n";

	for(ll i = 1; i <= 9; i++)
	{
		ret1 += i * pw10[cnt1[i]];

//		if(x == 9 && y == 8) cout << ret1 << " " << cnt1[i] << " " << i * pw10[cnt1[i]] << endl;
	}

	for(ll i = 1; i <= 9; i++)
	{
		ret2 += i * pw10[cnt2[i]];
	}



//	cout << x << " " << y << " " << ret1 << " " << ret2 << "\n";

//	for(ll i = 1; i <= 9; i++)
//	{
//		if(cnt1[i] + cnt2[i] > n)
//		{
//			tot--;
//			cnt1[x]--;
//			cnt2[y]--;
//			return 0;
//		}
//	}


	cnt1[x]--;
	cnt2[y]--;

	return ret1 > ret2;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	pw10[0] = 1;
	for(ll i = 1; i <= 9; i++) pw10[i] = 10 * pw10[i - 1];

    while(cin >> n >> s >> t)
    {
		tot = (9 * n - 8) * (9 * n - 9);

		memset(cnt,0,sizeof cnt);
		memset(cnt1,0,sizeof cnt1);
		memset(cnt2,0,sizeof cnt2);

		s.pop_back();
		t.pop_back();

		for(auto it: s) cnt1[it - '0']++;
		for(auto it: t) cnt2[it - '0']++;

		ans = 0;

		for(ll i = 1; i <= 9; i++) cnt[i] = cnt1[i] + cnt2[i];

		for(ll i = 1; i <= 9; i++)
		{
			for(ll j = 1; j <= 9; j++)
			{
				if(solve(i,j,n))
				{
					if(i == j)
					{
						if(cnt[i] < n)
						{
							ans += (n - cnt[i]) * (n - cnt[i] - 1);
						}
					}
					else ans += (n - cnt[i]) * (n - cnt[j]);
				}
			}
		}

//		cout << ans << "\n";

//		cout << ans << " " << tot << "\n";


		double ans1 = (ans * 1.0) / tot;

		cout << setprecision(7) << fixed << ans1 << "\n";

    }


}



