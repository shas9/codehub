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

ll platform[1004];
ll pos[1004];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ll d;

    while(cin >> n >> m >> d)
    {
		ll tot = 0;

		for(i = 1; i <= n; i++) pos[i] = 0;
		for(i = 1; i <= m; i++)
		{
			slld(platform[i]);

			tot += platform[i];
		}

		ll cpos = 0;
		bool poss = 0;

		for(i = 1; i <= m; i++)
		{
			ll jmp = cpos + d;

			if(n - jmp + 1 <= tot)
			{
				for(; i <= m; i++)
				{
					ll tmp = platform[i];

					while(tmp--) pos[++cpos] = i;
				}

				break;
			}

			cpos = cpos + d - 1;

			tot -= platform[i];

			ll tmp = platform[i];

			while(tmp--) pos[++cpos] = i;
		}

		if(cpos + d <= n)
		{
			printf("NO\n");
			continue;
		}

		printf("YES\n");

		for(i = 1; i <= n; i++) printf("%lld ", pos[i]);

		printf("\n");
    }



}



