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

map < ll, ll > dist;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		if(n >= m) cout << n - m << "\n";
		else
		{
			dist.clear();

			queue < ll > q;

			q.push(m);

			ans = mxlld;

			while(!q.empty())
			{
				ll top = q.front();
				q.pop();

				ans = min(ans, abs(n - top) + dist[top]);

				if(top < n) continue;

				if(top == n) break;

				if(top % 2 == 0 && dist.find(top / 2) == dist.end())
				{
					dist[top / 2] = dist[top] + 1;
					q.push(top / 2);
				}
				else
				{
					if(dist.find(top - 1) == dist.end())
					{
						dist[top - 1] = dist[top] + 1;
						q.push(top - 1);
					}

					if(dist.find(top + 1) == dist.end())
					{
						dist[top + 1] = dist[top] + 1;
						q.push(top + 1);
					}
				}
			}

			cout << ans << '\n';
		}
    }


}



