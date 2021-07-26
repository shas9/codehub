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

vector < ll > part[2];
ll arr[100];

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
		slld(m);

		for(i = 0; i < n; i++) slld(arr[i]);

		ll half = (n / 2);

		part[0].clear();
		part[1].clear();

		part[0].push_back(0);
		part[1].push_back(0);

		for(i = 1; i < (1 << half); i++)
		{
			ll sum = 0;

			for(j = half - 1; j >= 0; j--)
			{
				if(check(i,j))
				{
					sum += arr[j];
				}
			}

			part[0].push_back(sum);
		}


		for(i = 1; i < (1 << (n - half)); i++)
		{
			ll sum = 0;

			for(j = n - half - 1; j >= 0; j--)
			{
				if(check(i,j))
				{
					sum += arr[half + j];
				}
			}

			part[1].push_back(sum);
		}

		sort(part[0].begin(),part[0].end());
		sort(part[1].begin(),part[1].end());

		ans = 0;

//		for(auto it: part[0]) cout << it << " !! ";
//		cout << endl;
//
//		for(auto it: part[1]) cout << it << " ~~ ";
//		cout << endl;

		for(auto it: part[0])
		{
			ll ret = 0;
			ll lo = 0;
			ll hi = part[1].size() - 1;

			while(lo <= hi)
			{
				ll mid = (lo + hi) / 2;

				if(part[1][mid] + it <= m)
				{
					ret = mid + 1;
					lo = mid + 1;
				}
				else
				{
					hi = mid - 1;
				}
			}

			ans += ret;
		}

		printf("Case %lld: %lld\n", cs, ans);
    }


}



