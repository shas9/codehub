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

ll tree[5000006];

ll query(ll idx)
{
       ll sum=0;
       while(idx>0){
             sum+=tree[idx];
             idx -= idx & (-idx);
       }
       return sum;
}

void update(ll idx, ll x, ll n) //n is the size of the array, x is the number to add
{
       while(idx<=n)
       {
             tree[idx]+=x;
             idx += idx & (-idx);
       }
}

ll arr[200005];
ll freq[1000006];



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
		slld(m);

		for(i = 1; i <= n; i++) slld(arr[i]);

//		cout << query(1000000) << " ~~ ";

		for(i = 1; i <= m; i++)
		{
			if(freq[arr[i]] == 0) update(arr[i],1,1000000);

			freq[arr[i]]++;
		}

		ans = query(1000000);

//		cout << ans << endl;

		for(i = m + 1; i <= n; i++)
		{
			freq[arr[i - m]]--;

			if(freq[arr[i - m]] == 0) update(arr[i - m],-1,1000000);

			if(freq[arr[i]] == 0) update(arr[i],1,1000000);

			freq[arr[i]]++;

			ans = min(ans, query(1000000));
		}

		printf("%lld\n", ans);
		for( ; i <= n + m; i++)
		{
			freq[arr[i - m]]--;

			if(freq[arr[i - m]] == 0) update(arr[i - m],-1,1000000);
		}
    }


}



