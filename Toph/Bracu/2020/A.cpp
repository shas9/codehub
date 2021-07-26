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

ll dp[100000005];

void pre()
{
	memset(dp,0,sizeof dp);

	ll last = 6;

	for(ll i = 7; i <= 100000000; i++)
	{
		ll mov = last;

		if(mov - ((i - mov) * 5) <= 0)
		{
			dp[i] = 0;
			last = i;
		}
		else
		{
			dp[i] = 1;
		}
	}

	ll prv = 1;
	ll diff = 0;

	ll cnt = 0;

	for(ll i = 1; i <= 100000000; i++)
	{
//		cout << i << ": ";
		if(dp[i] == 0)
		{
//			cout << i << " " << i - prv << " " << (i - prv) - diff << endl;

			cout << i << " ";

			cnt++;
			diff = i - prv;

			prv = i;
		}
 //		else cout << "Alice\n";
	}

	cout << cnt << endl;
}

vector < ll > vec;

void precalc()
{
	vec.clear();
	for(ll i = 1; i <= 6; i++) vec.push_back(i);

	ll now = 6;

	while(now <= 2e18)
	{
		ll div = now / 5;

		if(now % 5) div++;

		ll nnxt = now + div - vec.back();

		if((nnxt > 5 && (nnxt - 5) % 2 == 0)) return;
		else vec.push_back(now + div);

		now += div;
	}


//	pre();
//	for(auto it: vec)
//	{
//		if(it <= 100000000) cout << it << " ";
//
//		if(it <= 1e8) assert(0 == dp[it]);
//	}

}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	precalc();

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> input;

		auto it = lower_bound(vec.begin(),vec.end(), input);

		if(it != vec.end() && *it == input) cout << "Bob\n";
		else cout << "Alice\n";
    }


}


