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

ll arr[104];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(ll i = 1; i <= n; i++) cin >> arr[i];
		vector < pll > cons;

		ans = 0;

		arr[n + 1] =100;

		cons.push_back({0,-1});

		for(ll i = 1; i <= n; i++)
		{
			if(arr[i] == 0) ans++;
			else if(arr[i] == 3)
			{
				ll cnt3 = 0;

				while(arr[i] == 3) i++, cnt3++;

				if(i > n) continue;

				ll num = arr[i];
				ll cnt = 0;

				while(arr[i] == num) i++, cnt++;

				if(num == 0)
				{
					ans += cnt;
					i--;
					continue;
				}

				if(cnt3 & 1)
				{
					if(num != cons.back().second && cons.back().second != -1)
					{
						if(cons.back().first & 1)
						{
							cnt++;
						}
						else
						{
							cons.back().first++;
						}
					}
				}
				else
				{
					if(num == cons.back().second)
					{
						if(cons.back().first & 1)
						{
							cnt++;
						}
						else
						{
							cons.back().first++;
						}
					}
				}

				cons.push_back({cnt,num});

				i--;
			}
			else
			{
				if(arr[i] == cons.back().second) cons.back().first++;
				else cons.push_back({1,arr[i]});
			}
		}

		for(auto it: cons)
		{
			cout << it.first << " " << it.second << "\n";
			ans += it.first / 2;
		}

		cout << ans << "\n";
    }



}



