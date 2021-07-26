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

string s, t;

ll basei[1000006];

bool poss(ll szz, ll szo)
{

	ll hash1 = 0, hash2 = 0;
	ll idx = 0;

	for(auto it: s)
	{
		ll sz;

		ll hashval = 0;

		if(it == '0') sz = szz;
		else sz = szo;

		for(ll i = 1; i <= sz; i++, idx++)
		{
			hashval =(hashval + (basei[i] * t[idx])) % mod;
		}

		if(it == '0')
		{
			if(hash1 == 0) hash1 = hashval;
			else if(hash1 != hashval) return 0;
		}
		else
		{
			if(hash2 == 0) hash2 = hashval;
			else if(hash2 != hashval) return 0;
		}
	}

	if(hash1 == hash2) return 0;

	return 1;
}

void divcnt()
{
	ll mx = 1;

	for(ll i = 1; i <= 1000000; i++)
	{
		ll cnt = 0;

		for(ll j = 1; j * j <= i; j++)
		{
			if(i % j == 0) cnt += 2;
		}

		mx = max(mx,cnt);
	}

	ll cn = 0;

	for(ll i = 1; i <= 358983; i++)
	{
		if(358983 % i == 0) cn++;
	}

	cout << mx << " " << cn << endl;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	divcnt();

    while(cin >> s >> t)
    {
		ll szs = s.size();
		ll szt = t.size();

		if(s == "11000") cout << szs << " " << szt << endl;

		if(szs > szt)
		{
			printf("0\n");
			continue;
		}

		basei[0] = 1;

		for(i = 1; i <= 1000000; i++) basei[i] = (base * basei[i - 1]) % mod;

		ll nz = 0, no = 0;

		for(i = 0; i < szs; i++)
		{
			if(s[i] == '0') nz++;
			else no++;
		}

		ans = 0;

		ll cnt = 0;

		for(i = 1; i < szt; i++)
		{
			ll x = szt - (i * no);

			if(x < no || x % nz) continue;
			cnt++;

			if(poss(i,x/nz)) ans++;
		}

		if(s == "11000") cout << cnt << endl;

		printf("%lld\n", ans);
    }


}



