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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll arr[1000005];
ll tree[1000006];

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

ll fnd(ll l, ll r, ll k)
{
	ll tot = query(r);
	if(l > 1) tot -= query(l - 1);

	if(tot < k) return -1;

	ll lo = l;
	ll hi = r;

	ll ret;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		ll ase = query(mid);
		if(l > 1) ase -= query(l - 1);

//		cout << l << " ~~ " << mid << " " << ase << endl;

		if(ase < k)
		{
			lo = mid + 1;
		}
		else
		{
			ret = mid;
			hi = mid - 1;
		}
	}

	return ret;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	ll num;

    slld(n);
    slld(num);

    for(ll i = 1; i <= n; i++)
    {
		slld(arr[i]);

		if(arr[i] == num) update(i,1,n);
    }

    slld(m);

    for(ll i = 1; i <= m; i++)
    {
		ll type;

		slld(type);

		if(type == 1)
		{
			slld(l);
			slld(r);
			slld(input);

			printf("%lld\n", fnd(l,r,input));
		}
		else
		{
			slld(l);
			slld(input);

			if(arr[l] == num)
			{
				update(l,-1,n);
			}

			if(input == num)
			{
				update(l,1,n);
			}

			arr[l] = input;
		}
    }


}



