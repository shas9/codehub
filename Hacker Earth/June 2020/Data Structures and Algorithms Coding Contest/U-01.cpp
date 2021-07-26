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

ll zero(ll n)
{
	ll ret = 0;

	while(n)
	{
		if(n % 10 == 0) ret++;

		n /= 10;
	}

	return ret;
}
void test()
{
	for(ll i = 1; i <= 1000; i++)
	{
		ll cnt = 0;

		for(ll j = 1; j <= i; j++)
		{
			cnt += zero(j);
		}

		cout << i << " " << cnt << endl;
	}
}

const ll sz = 14;

ll dp[sz + 1][2][2][2][20];
char lft[sz + 1], rgt[sz + 1];

void shft()
{
	scanf("%s%s", lft, rgt);

	ll lenl = strlen(lft);
	ll lenr = strlen(rgt);

	for(ll i = sz - 1; i >= 0; i--)
	{
		if(lenl) lft[i] = lft[lenl -1], lenl--;
		else lft[i] = '0';
	}

	for(ll i = sz - 1; i >= 0; i--)
	{
		if(lenr) rgt[i] = rgt[lenr -1], lenr--;
		else rgt[i] = '0';
	}

	lft[sz] = rgt[sz] = '\0';

	memset(dp,-1,sizeof dp);
}

ll solve(ll pos, bool isbig, bool issmall, bool isvalid, ll zero = 0)
{
	if(pos == 14) return zero;

	ll &ret = dp[pos][isbig][issmall][isvalid][zero];

	if(ret != -1) return ret;

	ll hi = 9;
	ll lo = 0;

	if(issmall == 0) hi = rgt[pos] - '0';
	if(isbig == 0) lo = lft[pos] - '0';

	ret = 0;

	for(ll i = lo; i <= hi; i++)
	{
		bool valid = isvalid;
		if(i) valid = 1;
		ll add = (i == 0 && isvalid);

		if(i < hi)
		{
			if(i > lo) ret += solve(pos + 1, 1, 1, valid, zero + add) ;
			else ret += solve(pos + 1, isbig, 1, valid, zero + add) ;
		}
		else
		{
			if(i > lo) ret += solve(pos + 1, 1, issmall, valid, zero + add) ;
			else ret += solve(pos + 1, isbig, issmall, valid, zero + add) ;
		}
	}

	return ret;
}

bool zz()
{
	for(ll i = 0; i < 14; i++) if(lft[i] != '0') return 0;

	return 1;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	test();

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		shft();

		ans = solve(0,0,0,0);

		if(zz()) ans++;

		printf("Case %lld: %lld\n", cs, ans);
    }


}



