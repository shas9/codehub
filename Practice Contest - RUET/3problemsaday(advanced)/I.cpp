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

long double mat[20][20];
long double ans[20];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;

    cin >> n;

    for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) cin >> mat[i][j];

    if(n == 1)
    {
		cout << 1 << endl;
		return 0;
    }

    ll on = 0;
    long double tot = 0;

    for(ll i = 0; i < n; i++)
    {
		ans[i] = 0;

		for(ll mask = 1; mask < (1 << n); mask++)
		{
			long double sum = 1;

			for(ll j = 0; j < n; j++)
			{
				if(check(mask,j)) sum *= mat[i][j];
			}

			ans[i] += sum;
		}

		ans[i] /= ((1 << (n - 1)) - 1);

		if(abs(ans[i] - 1) < 0.000001) on++;

		tot += ans[i];

	}

	assert(on <= 1);

	for(ll i = 0; i < n; i++)
	{
		if(abs(ans[i] - 1) < 0.000001) cout << setprecision(10) << fixed << ans[i] << " ";
		else
		{
			if(on) cout << "0.0000000000" << ' ';
			else cout << setprecision(10) << fixed << ans[i] / tot << " ";
		}
	}

	cout << endl;


}



