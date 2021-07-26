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

ll pw[100];

void brute(ll n)
{
	for(ll i = n; i <= n + 1000; i++)
	{
		set < ll > st;
		ll cnt = 0;
		ll tmp = i;

		for(ll j = 38; j >= 0; j--)
		{
			while(pw[j] <= tmp)
			{
				cnt++;
				st.insert(j);
				tmp -= pw[j];
			}
		}

		if(st.size() == cnt)
		{
			cout << i << " ";
//			for(auto it: st) cout << it << " ";
//			cout << endl;
			return;
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

	pw[0] = 1;

	for(i = 1; i <= 38; i++)
	{
		pw[i] = pw[i - 1] * 3;
	}

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);

//		brute(n);

		ll x = 0;

		for(i = 0; x < n; i++)
		{
			x += pw[i];
		}

		for(i = 38; i >= 0; i--)
		{
			if(x - pw[i] >= n) x -= pw[i];
		}

		printf("%lld\n", x);
    }


}



