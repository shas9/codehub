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

vector < ll > vec;

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
		cin >> n >> m;

		vec.clear();

		ll _n = n;

		while(_n)
		{
			vec.push_back(_n % 10);

			_n /= 10;
		}

		ll nw = 0;
		ll sum = 0;

		bool on = 0;

		for(ll i = vec.size() - 1; i >= 0; i--)
		{
//			cout << nw << " " << sum << "\n";
			if(on)
			{
				nw *= 10;
				continue;
			}

			if(sum + vec[i] > m)
			{
				ll cnt = 0;

				while(nw)
				{
					ll last = nw % 10;
					cnt++;
					nw /= 10;

					if(last != 9 && sum + 1 <= m)
					{
 						last++;
						cnt--;
						nw = (nw * 10) + last;
						sum++;

						break;
					}

					sum -= last;

//					cout << nw << " " << last << " ~ " << sum << endl;
				}

//				cout << nw << " -- " << cnt << "\n";

				if(nw == 0) nw = 1;

				for(ll xx = 0; xx <= cnt; xx++) nw *= 10;

				on = 1;

				continue;
			}

			nw = (nw * 10) + vec[i];
			sum += vec[i];
		}

		cout << nw - n << "\n";
    }


}



