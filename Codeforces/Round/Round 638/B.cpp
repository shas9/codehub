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

ll inn[103];
ll out[10004];
set < ll > st;

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

		st.clear();

		for(i = 1; i <= n; i++)
		{
			slld(inn[i]);

			st.insert(inn[i]);
		}

		if(st.size() > k)
		{
			printf("-1\n");
			continue;
		}

		ll idx = 0;

		for(auto it: st)
		{
			out[++idx] = it;
		}

		j = 1;

		while(idx < k) out[++idx] = out[j++];

		for(i = 1; i < n; i++)
		{
			for(j = 1; j <= k; j++)
			{
				out[++idx] = out[j];
			}
		}

		{
			printf("%lld\n", idx);
			for(i = 1; i <= idx; i++)
			{
				printf("%lld ", out[i]);
			}

			printf("\n");
		}

//		st.clear();
//
//		for(i = 1; i + k - 1<= idx; i++)
//		{
//			ll sum = 0;
//			for(j = i; j <= (i + k - 1); j++)
//			{
//				sum += out[j];
//			}
//
//			st.insert(sum);
//		}
//
//		cout << st.size() << endl;
    }


}



