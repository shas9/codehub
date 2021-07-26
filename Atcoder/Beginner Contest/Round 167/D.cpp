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

ll vis[200005];
ll town[200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		for(i = 1; i <= n; i++)
		{
			slld(town[i]);
		}

		ll now = 1;
		ll used = 0;

		memset(vis,-1,sizeof vis);
		vis[1] = 0;

		while(++used <= m)
		{
			now = town[now];

			if(vis[now] != -1) break;

			vis[now] = used;
		}

		if(used >= m) cout << now << '\n';
		else
		{
			m -= used;
			ll circle = (used - vis[now]);
			ll in = vis[now];
			m %= circle;

			while(vis[now] < in + m)
			{
//				bug;
				now = town[now];
			}

			cout << now << '\n';
		}


    }


}



