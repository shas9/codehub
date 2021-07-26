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

ll pw[25];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		queue < ll > q1, q2;

		cin >> m;

		for(ll i = 1; i <= m; i++)
		{
			cin >> input;
			q1.push(input);
		}

		cin >> m;

		for(ll i = 1; i <= m; i++)
		{
			cin >> input;
			q2.push(input);
		}

		bool loop = 0;
		ll cnt = 0;

		while(!q1.empty() && !q2.empty())
		{
			if(cnt > (1e6))
			{
				loop = 1;
				break;
			}

			ll x = q1.front();
			ll y = q2.front();

			q1.pop();
			q2.pop();

			assert(x != y);

			if(x < y)
			{
				q2.push(x);
				q2.push(y);
			}
			else
			{
				q1.push(y);
				q1.push(x);
			}

			cnt++;

		}

		if(loop) cout << -1 <<"\n";
		else if(q1.empty()) cout << cnt << " " << 2 << "\n";
		else cout << cnt << " " << 1 << "\n";

    }


}


