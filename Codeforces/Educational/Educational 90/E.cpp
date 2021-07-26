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

void test(ll n, ll k)
{
	ll ans = -1;

//	cout << n << " " << k << ": ";

	for(ll i = 0; i <= 9; i++)
	{
		ll sum = 0;

		for(ll j = i; j <= i + k; j++)
		{
			if(j <= 9) sum += (j - i);
			else
			{
				sum += (j - i) - 9;
			}
		}

//		cout << i << " & " << sum << endl;

		ll lft = n - sum;

		if(lft < (i * (k + 1))) continue;

		string dig = "";

		dig += (i + '0');

		lft -= (i * (k + 1));

//		cout << i << " && " << lft << " && " << (k + 1) << endl;

		if(lft % (k + 1)) continue;

		lft /= (k + 1);

//		cout << lft << " ";

		if(i + k > 9)
		{
			dig += min(lft, 8LL) + '0';
			lft -= min(lft,8LL);
		}

		while(lft)
		{
			dig += min(lft,9LL) + '0';
			lft -= min(lft,9LL);
		}

		reverse(dig.begin(),dig.end());

		ll num = 0;

		for(auto it: dig)
		{
			num *= 10;
			num += (it - '0');
		}

		if(ans == -1) ans = num;
		else ans = min(ans,num);

//		cout << num << " " << i << ", ";
	}

	cout << ans << '\n';
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
		slld(k);

		 test(n,k);
    }


}



