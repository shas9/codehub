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

vector < ll > v1, v2;

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

		v1.clear();
		v2.clear();

		for(i = 0; i < n; i++)
		{
			slld(input);
			v1.push_back(input);
		}

		sort(v1.begin(), v1.end());

		ans = -1;

		for(i = 1; i <= 1024; i++)
		{
			v2.clear();

			for(j = 0; j < n; j++)
			{
				v2.push_back(v1[j] ^ i);
			}

			sort(v2.begin(),v2.end());

			if(v1 == v2)
			{
				ans = i;
				break;
			}
		}

		cout << ans << '\n';
    }


}


