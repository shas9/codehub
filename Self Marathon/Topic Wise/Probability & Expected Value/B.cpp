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

double prob[103];

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

		memset(prob,0,sizeof prob);

		prob[1] = 1;

		for(i = 1; i < n; i++)
		{
			ll shamne = (n - i);
			shamne = min(shamne,6LL);

			double add = (1.0/shamne) * prob[i];

			for(j = i + 1; j <= i + shamne; j++)
			{
				prob[j] += add;
			}
		}

		prob[n] = 1;

		double ans = 0;

		for(i = 1; i <= n; i++)
		{
			slld(input);

			ans += prob[i] * input;
		}

		printf("Case %lld: %.8f\n", cs, ans);
    }


}


