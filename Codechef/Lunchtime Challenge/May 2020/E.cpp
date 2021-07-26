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

vector < ll > vec1, vec2;

ll dp[1000006];
ll n;

void shift()
{
	ll dane = (n - vec1.back() + 1);

	vec2.clear();

	vec2.push_back(1LL);

	for(ll i = 0; i + 1 < vec1.size(); i++)
	{
		vec2.push_back(vec1[i] + dane);
	}

	vec1.clear();

	vec1 = vec2;
}

ll solve()
{
	dp[0] = 0;
	dp[1] = n;
	dp[2] = abs(vec1[0] - vec1[1]);

//	for(auto it: vec1) cout << it << " ";
//	cout << endl;

	for(ll i = 2; i < vec1.size(); i++)
	{
		dp[i + 1] = min(dp[i - 1] + abs(vec1[i - 1] - vec1[i]), dp[i - 2] + abs(vec1[i - 2] - vec1[i]));
	}

//	cout << dp[]

	return dp[vec1.size()];
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		vec1.clear();

		slld(n);

		for(i = 1; i <= n; i++)
		{
			slld(input);

			if(input) vec1.push_back(i);
		}

		if(vec1.size() == 0) printf("0\n");
		else if(vec1.size() == 1) printf("-1\n");
		else
		{
			ans = n;

			ans = min(ans,solve());

			shift();

			ans = min(ans,solve());

			shift();

			ans = min(ans,solve());

			printf("%lld\n", ans);
		}


    }


}



