// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long

using namespace std;

ll arr[200005];
ll n, k;
ll tree[2000006];

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

int main()
{
    ll i, j, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		slld(k);

		for(i = 1; i <= n; i++) slld(arr[i]);

		for(i = 1; i <= 10 * n; i++) tree[i] = 0;

		for(i = 2; i < n; i++)
		{
			if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) update(i,1,n);
		}

		ll mx = 0;
		ll mxl = 1;

		for(i = 1; i <= (n - k + 1); i++)
		{
			ll cnt = query(i + k - 2);

			cnt -= query(i);

			if(mx < cnt) mx = cnt, mxl = i;

		}

		printf("%lld %lld\n", mx + 1, mxl);
    }


}




