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

ll arr[100005];

map < set < ll > , ll > even, odd;

set < ll > st;

ll freq[200005];

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

		for(ll i = 1; i <= n; i++) slld(arr[i]);

		memset(freq,0,sizeof freq);

		ans = 0;

		even.clear();
		odd.clear();

		st.clear();

		even[st]++;

		for(ll i = 1; i <= n; i++)
		{
			freq[arr[i]] ^= 1;

			if(freq[arr[i]] & 1) st.insert(arr[i]);
			else st.erase(arr[i]);

//			cout << freq[arr[i]] << " " << st.size() <<  " " << arr[i] << endl;

			if(i & 1)
			{
				ans += odd[st];

				odd[st]++;
			}
			else
			{
				ans += even[st];
				even[st]++;
			}
		}

		printf("Case %lld: %lld\n", cs, ans);

    }


}




