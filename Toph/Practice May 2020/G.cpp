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

void test(ll k)
{
	ll mx = 0;
	ll x = 20;

	for(ll i = 0; i <= x; i++)
	{
		for(ll j = 0; j <= x; j++)
		{
			for(ll m = 0; m <= x; m++)
			{
				for(ll n = 0; n <= x; n++)
				{
					if(i + j + m + n != x) continue;

					vector < ll > vec;

					vec.push_back(i);
					vec.push_back(j);
					vec.push_back(m);
					vec.push_back(n);

					ll sum = 0;
					sort(vec.rbegin(),vec.rend());

					while(!vec.empty())
					{
						for(auto it: vec) sum += it;

						vec[0] -= min(k,vec[0]);

						sort(vec.rbegin(),vec.rend());
						while(vec.back() == 0) vec.pop_back();

					}

					mx = max(mx,sum);
				}

			}
		}
	}


	for(ll i = 0; i <= x; i++)
	{
		for(ll j = 0; j <= x; j++)
		{
			for(ll m = 0; m <= x; m++)
			{
				for(ll n = 0; n <= x; n++)
				{
					if(i + j + m + n != x) continue;


					vector < ll > vec;

					vec.push_back(i);
					vec.push_back(j);
					vec.push_back(m);
					vec.push_back(n);

					ll sum = 0;
					sort(vec.rbegin(),vec.rend());

					while(!vec.empty())
					{
						for(auto it: vec) sum += it;

						vec[0] -= min(k,vec[0]);

						sort(vec.rbegin(),vec.rend());
						while(vec.back() == 0) vec.pop_back();

					}

					if(mx == sum) cout << i << " " << j << " " << m << " " << n << endl;
//					if(i == j && j == m) cout << i << " " << sum << endl;
 				}

			}
		}
	}

	cout << mx << endl;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	while(cin >> input)
//	{
//		test(input);
//	}

    while(cin >> n >> m >> k)
    {
		ans = 0;

		for(i = max(0LL, n/k - m); i <= (n / k); i++)
		{
			ll a = k;
			ll b = (n - (i * k)) / m;
			ll c = b;

			if(((n - (i * k)) % m)) c++;

			ll asz = i;
			ll bsz = m - ((n - (i * k)) % m);
			ll csz = ((n - (i * k)) % m);

			ll cnt = 0;

//			cout << a << " " << b << " " << c << endl;
//			cout << asz << " " << bsz << " " << csz << endl;

			cnt += ((asz * (asz + 1)) / 2) * a + asz * (b * bsz + c * csz);

//			cout << cnt << endl;

			cnt += ((csz * (csz + 1)) / 2) * c + csz * (b * bsz);

//			cout << cnt << endl;

			cnt += ((bsz * (bsz + 1)) / 2) * b;

//			cout << cnt << endl;

			ans = max(ans,cnt);
		}

		cout << ans << endl;
    }


}



