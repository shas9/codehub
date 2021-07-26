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

#define mod 1000004099

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

char s[100005];
char t[1000006];
ll basei[1000006];
ll hasht, lens, lent;
ll first0, first1;
ll hashtable[1000006];

ll mul(ll a, ll b)
{
	return ((a % mod) * (b % mod)) % mod;
}

pll gethash(ll sz0, ll sz1)
{
	ll st0 = (first0 - 1) * sz1 + 1;
	ll en0 = st0 + sz0 - 1;

	ll st1 = (first1 - 1) * sz0 + 1;
	ll en1 = (st1 + sz1 - 1);

	ll hsh1 = mul((hashtable[en0] - hashtable[st0 - 1] + mod), basei[lent - en0]);
	ll hsh2 = mul((hashtable[en1] - hashtable[st1 - 1] + mod), basei[lent - en1]);

	return {hsh1,hsh2};
}
bool solve(ll sz0, ll sz1)
{

	pll hsh = gethash(sz0,sz1);

//	cout << sz0 << " " << sz1 << " " << hsh.first << " " << hsh.second << endl;

	if(hsh.first == hsh.second) return 0;

	ll csz = 0;
	ll hsht = 0;

	for(ll i = 1; i <= lens; i++)
	{
		if(s[i] == '0')
		{
			ll tmphsh = mul((hashtable[csz + sz0] - hashtable[csz] + mod), basei[lent - csz - sz0]);

//			cout << tmphsh << " " << hsh.first << endl;

			if(tmphsh != hsh.first) return 0;

			csz += sz0;
		}
		else
		{
			ll tmphsh = mul((hashtable[csz + sz1] - hashtable[csz] + mod), basei[lent - csz - sz1]);

			if(tmphsh != hsh.second) return 0;

			csz += sz1;
		}
	}

//	cout << hsht << " " << hasht << endl;

	return 1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	basei[0] = 1;
	for(i = 1; i <= 1000000; i++) basei[i] = mul(base, basei[i - 1]);

    while(scanf("%s %s", s + 1, t + 1) != EOF)
    {
//		hasht = 0;
		lens = strlen(s + 1);
		lent = strlen(t + 1);

//		for(i = 1; i <= lent; i++)
//		{
//			hasht = (hasht + (basei[i] * t[i])) % mod;
//		}

		ll zero, one;

		zero = 0;
		one = 0;
		first0 = first1 = lens;

		for(i = 1; i <= lens; i++)
		{
			if(s[i] == '0') zero++, first0 = min(first0,i);
			else one++, first1 = min(first1,i);
		}

		for(i = 1; i <= lent; i++)
		{
			hashtable[i] = (hashtable[i - 1] + mul(basei[i], t[i])) % mod;
		}


		int ans = 0;

//		if(lent == 358983) cout << lent /(i * zero) << " " << lent / (i * one) << endl;

		if(zero > one)
		{
			for(i = 1; i * zero < lent; i++)
			{
				j = (lent - (i * zero));

				if(j % one) continue;

				j /= one;

//				cout << i << " " << j << endl;

				ans += solve(i,j);
			}
		}
		else
		{
			for(i = 1; i * one < lent; i++)
			{
				j = (lent - (i * one));

				if(j % zero) continue;

				j /= zero;

//				cout << j << " " << i << endl;
				ans += solve(j,i);
			}
		}

		printf("%d\n", ans);



    }


}



