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

ll mat[503][503];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		ll num = m + 1;

		if(n == 1 && m == 1)
		{
			printf("0\n");
			continue;
		}


		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= m; j++)
			{
				mat[i][j] = (num * j);

//				if(n == 1 || m == 1) mat[i][j] = 0;
			}

			num++;
		}

		if(n == 1 || m == 1)
		{
			ll num = 2;
			for(i = 1; i <= n; i++)
			{
				for(j = 1; j <= m; j++)
				{
					mat[i][j] = num++;

	//				if(n == 1 || m == 1) mat[i][j] = 0;
				}
			}
		}



		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= m; j++)
			{
				printf("%lld ", mat[i][j]);
			}

			printf("\n");
		}



//		set < ll > st;
//
//		for(i = 1; i <= n; i++)
//		{
//			ll gc = 0;
//
//			for(j = 1; j <= m; j++)
//			{
//				gc = __gcd(mat[i][j], gc);
//			}
//
//			st.insert(gc);
//		}
//
//		for(i = 1; i <= m; i++)
//		{
//			ll gc = 0;
//
//			for(j = 1; j <= n; j++)
//			{
//				gc = __gcd(mat[j][i], gc);
//			}
//
//			st.insert(gc);
//		}
//
//		set < ll > :: iterator it = st.end();
//		it--;
//		if(st.size() != (n + m) && *it != (n+m)) bug;
//
//		cout << "Done" << endl;
    }


}



