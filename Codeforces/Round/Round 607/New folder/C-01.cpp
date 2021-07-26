#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
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

#define mod 1000000007


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

char str[1000006];

void append(ll st, ll en, ll lim)
{
	if(en == lim) return;
	ll cnt = str[st] - '0';
	st++;

	ll idx = en + 1;

	while(cnt--)
	{
		for(ll i = st; i <= en; i++)
		{
			if(idx > lim) return;
			str[idx++] = str[i];
		}
	}
}

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
		scanf("%s", str + 1);

		ll len = strlen(str + 1);
		ans = len;

		for(i = 1; i <= n; i++)
		{
			append(i,len,n);

			ans += (str[i] - '0' - 1) * (ans - i);
			ans %= mod;

			len = min(ans, n);
		}

		printf("%lld\n", ans);
    }


}


