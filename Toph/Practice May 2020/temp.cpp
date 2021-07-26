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

char str[10000];
pll outdeg[10000];
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(i = 1; i <= n; i++) outdeg[i] = {0,i};

		for(i = 2; i <= n; i++)
		{
			scanf("%s", str + 1);

			for(j = 1; j < i; j++)
			{
				if(str[j] == '1') outdeg[j].first++;
				else outdeg[i].first++;
			}
		}

		sort(outdeg + 1, outdeg + 1 + n);

		ans = 0;
		ll now = 0;

		for(i = 1; i <= n; i++)
		{
			now += (outdeg[i].first - (i - 1));

			ans = max(ans,now);
		}

		printf("%lld\n", ans);
    }

}


