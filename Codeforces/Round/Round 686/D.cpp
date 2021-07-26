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

vector < pll > dv;

void process(ll x)
{
	for(auto it: primes)
	{
		if(it * it > x) break;

		if(x % it == 0)
		{
			dv.push_back({0,it});

			while(x % it == 0)
			{
				dv.back().first++;
				x /= it;
			}
		}
	}

	if(x > 1) dv.push_back({1,x});

	return;
}

void solve()
{
//	cout << dv.size() << endl;
	sort(dv.rbegin(),dv.rend());

	cout << dv.front().first << "\n";


	vector < ll > pr;
//
	while(!dv.empty())
	{
		ll x = 1;

		for(auto &it: dv)
		{
			x *= it.second;
			it.first--;
		}

		pr.push_back(x);

		while(dv.back().first == 0 && !dv.empty()) dv.pop_back();
	}

	reverse(pr.begin(),pr.end());

	for(auto it: pr) cout << it << " ";

	cout << "\n";
//
//	return;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	sieve();

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		dv.clear();
		cin >> input;

		process(input);
//
		solve();
    }


}


