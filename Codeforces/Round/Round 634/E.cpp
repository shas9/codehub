#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll arr[200005];
ll freq[203][200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);

		for(i = 1; i <= 200; i++)
		{
			for(j = 1; j <= n; j++)
			{
				freq[i][j] = 0;
			}
		}

		ans = 0;

		for(i = 1; i <= n; i++)
		{
			slld(input);

			arr[i] = input;

			freq[input][i]++;
		}

		for(i = 1; i <= 200; i++)
		{
			for(j = 1; j <= n; j++)
			{
				freq[i][j] += freq[i][j - 1];
			}

			ans = max(ans,freq[i][n]);
		}

		for(i = 1; i <= 200; i++)
		{
			ll p1, p2;

			p1 = 1;
			p2 = n;

			ll cnt = 0;

			while(p1 < p2)
			{
				while(arr[p1] != i && p1 <= p2) p1++;
				while(arr[p2] != i && p1 <= p2) p2--;

				cnt += 2;

				if(p1 >= p2) break;
				for(j = 1; j <= 200; j++)
				{
					if(i == j) continue;
					ll cnt2 = 0;

					cnt2 = freq[j][p2 - 1] - freq[j][p1];

					ans = max(ans,cnt2 + cnt);
				}

				p1++;
				p2--;
			}
		}

		printf("%lld\n", ans);
    }


}



