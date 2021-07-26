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

ll tree[200005];

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

string str;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> str)
    {
		ll sum = 0;

		for(auto it: str)
		{
			if(it == 'a') sum++;
			else if(it == 'c') sum--;

			update(sum + (1e5), 1, 2e5);
		}

		sum = 0;

		ans = 0;

		for(auto it: str)
		{
			if(it == 'a') sum++;
			else if(it == 'c') sum--;

			if(it == 'a')
			{
				if(sum + 1e5 - 1 >= 0) ans += query(2e5);

				if(sum + 1e5 - 1 > 0) ans -= query(sum + 1e5 - 1);
			}
			else if(it == 'b')
			{
				if(sum + (1e5) <= 2e5) ans += (query(2e5) - query(sum + 1e5));
			}
			else if(it == 'c')
			{
				if(sum + (1e5) + 1 <= 2e5) ans += (query(2e5) - query(sum + 1e5 + 1));
			}

			update(sum + 1e5, -1, 2e5);
//			cout << ans << endl;
		}

		printf("%lld\n", ans % 1000000007);
    }


}



