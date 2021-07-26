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

ll zero[100005];
ll one[100005];
vector < ll > v;

ll solve10(ll x, ll y)
{
	ll sum = 0;
	ll mn = mxlld;
	ll lim = 100000;

	for(auto it: v)
	{
		ll bam = one[it];
		ll dan = one[lim] - one[it];

		sum += (bam * y) + (dan * x);
	}

	ll cnt = 0;

	for(auto it: v)
	{
		cnt++;

		ll bam = one[it];
		ll dan = one[lim] - one[it];

		sum -= (bam * y) + (dan * x);

		bam = zero[it];
		dan = zero[lim] - zero[it];

		sum += (bam * x) + (dan * y);

		bam = cnt;
		dan = v.size() - cnt;

		mn = min(mn, sum + (bam * dan * y));
	}

	if(mn == mxlld) mn = 0;

	return mn;
}

ll solve01(ll x, ll y)
{
	ll sum = 0;
	ll mn = mxlld;
	ll lim = 100000;

	for(auto it: v)
	{
		ll bam = zero[it];
		ll dan = zero[lim] - zero[it];

		sum += (bam * x) + (dan * y);
	}

	ll cnt = 0;

	for(auto it: v)
	{
		cnt++;

		ll bam = zero[it];
		ll dan = zero[lim] - zero[it];

		sum -= (bam * x) + (dan * y);

		bam = one[it];
		dan = one[lim] - one[it];

		sum += (bam * y) + (dan * x);

		bam = cnt;
		dan = v.size() - cnt;

		mn = min(mn, sum + (bam * dan * x));
	}

	return mn;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	string str;

	while(cin >> str >> n >> m)
	{
		memset(one,0,sizeof one);
		memset(zero,0,sizeof zero);
		ans = 0;
		v.clear();

//		cout << str << " " << n << " " << m << endl;

		for(ll i = 0; i < str.size(); i++)
		{
			if(str[i] == '1')
			{
				ans += zero[i] * n;
				one[i + 1]++;
			}
			else if(str[i] == '0')
			{
				ans += one[i] * m;
				zero[i + 1]++;
			}
			else v.push_back(i + 1);

			one[i + 1] += one[i];
			zero[i + 1] += zero[i];
		}

		for(ll i = str.size() + 1; i <= 100000; i++) one[i] += one[i - 1], zero[i] += zero[i - 1];


		ans += min(solve10(n,m), solve01(n,m));

		cout << ans << "\n";
	}


}

