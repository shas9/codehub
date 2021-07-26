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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

void brute()
{
	ll a, b, c, d;

	vector < ll > v, sv, r_sv;
	vector < ll > rv, rsv, r_rsv;

	ll cnt = 100;
	map < ll, ll > mp;

	while(cnt--)
	{
		a = rand() % 100000;
		b = rand() % 100000;
		c = rand() % 100000;
		d = rand() % 1000;

		if(rand() & 1) a *= -1;
		if(rand() & 1) b *= -1;
		if(rand() & 1) c *= -1;
		if(rand() & 1) d *= -1;

//		a = 16649, b = -41421, c =  -2362, d =  27;


		v.clear();
		rv.clear();
		mp.clear();
		bool on = 0;

		printf("Processing %lld %lld %lld %lld\n", a, b, c, d);

		for(ll x = 1; x <= 100000; x++)
		{
			ll ans = a + (b * x) + (c * x * x) + (d * x * x * x);

//			cout << ans << " ";

			if(on)
			{
				if(mp.find(ans) == mp.end())
				{
					printf("Repeated here at: %lld\n", x);
				}
				rv.push_back(ans);
			}
			else
			{
				if(mp.find(ans) != mp.end())
				{
					printf("Queue point found at: %lld\n", x);
					rv.push_back(ans);
					on = 1;
				}
				else
				{
					v.push_back(ans);
				}
			}

			mp[ans]++;
		}


		cout << v.size() << " " << rsv.size() << endl;

		sv = v;
		rsv = rv;

		r_sv = v;
		r_rsv = rv;

		sort(sv.begin(),sv.end());
		sort(r_sv.rbegin(),r_sv.rend());

		sort(rsv.begin(),rsv.end());
		sort(r_rsv.rbegin(),r_rsv.rend());



		assert(sv == v || r_sv == v);
		assert(rsv == rv || r_rsv == rv);

		printf("Done\n");

	}
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    brute();

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {

    }


}



