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

string s;

bool fcheck(ll k)
{
	ll one = 0;
	ll unk = 0;

	for(ll i = 0; i < k; i++)
	{
		one += s[i] == '1';
		unk += s[i] == '?';
	}

	ll n = s.size();

	for(ll i = k, j = 0; i <= n; i++, j++)
	{
		ll z = k - one - unk;

		if(z > (k / 2) || one > (k / 2)) return 0;

		one -= s[j] == '1';
		unk -= s[j] == '?';

		if(i == n) break;

		one += s[i] == '1';
		unk += s[i] == '?';

	}

	return 1;
}
bool solve(ll k)
{
	ll cnt = 200;

	while(cnt--)
	{
		ll one = 0;
	ll unk = 0;

	for(ll i = 0; i < k; i++)
	{
		one += s[i] == '1';
		unk += s[i] == '?';
	}

	ll n = s.size();

	ll ptr = 0;

	for(ll i = k, j = 0; i <= n; i++, j++)
	{
		ll z = k - one - unk;
//		cout << i << ": " <<  z << " " << one << " " << unk << endl;

		if(z > (k / 2) || one > (k / 2)) return 0;

		ptr = max(ptr, j);

		if(z == (k / 2))
		{
			while(unk > 0)
			{
				unk--;
				while(s[ptr] != '?') ptr++;

				s[ptr] = '1';
				one++;
			}
		}
		else if(one == (k / 2))
		{
			while(unk > 0)
			{
				unk--;
				while(s[ptr] != '?') ptr++;

				s[ptr] = '0';
			}
		}

//		cout << s << endl;


		one -= s[j] == '1';
		unk -= s[j] == '?';

		if(i == n) break;

		one += s[i] == '1';
		unk += s[i] == '?';

	}
	}

//	cout << "~~ " << s << endl;

	return fcheck(k);
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
		cin >> n >> k >> s;

		if(solve(k)) cout << "YES\n";
		else cout << "NO\n";
    }


}



