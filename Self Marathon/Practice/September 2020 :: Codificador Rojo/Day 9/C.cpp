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

vector < ll > g[300005];
ll arr[300005];
ll dp[300005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(ll i = 1; i <= n; i++) g[i].clear();

		for(ll i = 1; i <= n; i++) cin >> arr[i];

		stack < ll > st;

		for(ll i = 1; i <= n; i++) ///nearest left greater equal
		{
			while(!st.empty() && arr[st.top()] < arr[i]) st.pop();

			if(!st.empty()) g[st.top()].push_back(i);

			st.push(i);
		}

		while(!st.empty()) st.pop();

		for(ll i = 1; i <= n; i++) ///nearest left small
		{
			while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

			if(!st.empty()) g[st.top()].push_back(i);

			st.push(i);
		}

		while(!st.empty()) st.pop();

		for(ll i = n; i >= 1; i--) ///nearest right greater equal
		{
			while(!st.empty() && arr[st.top()] < arr[i]) st.pop();

			if(!st.empty()) g[i].push_back(st.top());

			st.push(i);
		}

		while(!st.empty()) st.pop();

		for(ll i = n; i >= 1; i--) ///nearest right greater equal
		{
			while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

			if(!st.empty()) g[i].push_back(st.top());

			st.push(i);
		}

		for(ll i = 1; i <= n; i++) dp[i] = mxlld;

		dp[1] = 0;

		for(ll i = 1; i <= n; i++)
		{
			for(auto it: g[i])
			{
				dp[it] = min(dp[it], dp[i] + 1);
			}
		}

		cout << dp[n] << "\n";

    }


}


