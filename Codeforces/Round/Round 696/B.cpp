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

const ll maxn  = 1000002;
vector < ll > primes;
bool vis[maxn+10];

void sieve()
{
    vis[0] = 1;
    vis[1] = 1;

    for(ll i = 4; i <= maxn; i += 2)
    {
        vis[i] = 1;
    }

    for(ll i = 3; i * i <= maxn; i += 2)
    {
        if(vis[i] == 0)
        for(ll j = i * i; j <= maxn; j += i)
        {
            vis[j] = 1;
        }
    }

    for(ll i = 2; i <= maxn; i++)
    {
        if(vis[i] == false)
        primes.pb(i);
    }

}

bool check(ll pos, ll n)
{
	vector < ll > v;

	for(ll i = 1; i * i <= pos; i++)
	{
		if(pos % i == 0)
		{
			v.push_back(pos / i);

			if(v.back() != i) v.push_back(i);
		}
	}

	if(v.size() < 4) return 0;

	sort(v.begin(),v.end());
//
//	for(auto it: v) cout << it << " ";
//
//	cout << endl;

	for(ll i = 1; i < v.size(); i++)
	{
		if(v[i - 1] + n > v[i]) return 0;
	}

	for(auto it: v) cout << it << " ";

	cout << endl;


	return 1;
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    sieve();

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n;

		auto it = lower_bound(primes.begin(),primes.end(), n + 1);

		ans = *it;

		it = lower_bound(primes.begin(),primes.end(), ans + n);

		ans *= *it;

		cout << ans << "\n";
    }


}


