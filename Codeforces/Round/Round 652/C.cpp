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

vector < ll > kk[200005];
vector < ll > vec;
vector < ll > vv;

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
		slld(k);

		vec.clear();

		for(i = 0; i <= k; i++) kk[i].clear();

		for(i = 1; i <= n; i++)
		{
			slld(input);

			vec.push_back(input);
		}

		sort(vec.begin(),vec.end());

		ll lo = 0;
		ll hi = vec.size() - 1;

		vv.clear();

		for(i = 1; i <= k; i++)
		{
			slld(input);

			vv.push_back(input);
		}

		sort(vv.begin(),vv.end());

		ll lol = 0;
		ll hh = vv.size() - 1;

		for(i = 1; i <= k; i++)
		{
			if(vv[lol] == 1) input = vv[lol], lol++;
			else input = vv[hh], hh--;

			kk[i].pb(vec[hi]);
			hi--;

			input--;

			while(input--)
			{
				kk[i].pb(vec[lo]);
				lo++;
			}

			sort(kk[i].begin(),kk[i].end());
		}

		ans = 0;

		for(i = 1; i <= k; i++)
		{
			ans += kk[i].front() + kk[i].back();

//			cout << kk[i].front() << " " << kk[i].back() << endl;
		}

		printf("%lld\n", ans);
    }


}



