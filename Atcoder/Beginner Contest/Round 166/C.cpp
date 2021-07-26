// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

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


vector < int > g[100005];
int hill[100005];

int main()
{
    int i, j, k, l, m, n, o, r, q;
    int testcase;
    int input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		for(i = 1; i <= n; i++) g[i].clear();

		for(i = 1; i <= n; i++) slld(hill[i]);

		for(i = 1; i <= m; i++)
		{
			int u, v;

			slld(u);
			slld(v);

			g[u].pb(v);
			g[v].pb(u);
		}

		ans = 0;

		for(i = 1; i <= n; i++)
		{
			bool on = 1;

			for(auto it: g[i])
			{
				if(hill[it] >= hill[i])
				{
					on = 0;
					break;
				}
			}

			if(on) ans++;
		}

		printf("%d\n", ans);
    }

}



