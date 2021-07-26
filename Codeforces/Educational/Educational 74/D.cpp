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

ll tree[300100];
char str[300100];

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

vector < ll > g[2];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//		freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		memset(tree,0,sizeof tree);
		g[0].clear();
		g[1].clear();

		scanf("%s", str + 1);

		for(i = 1; i <= n; i++)
		{
			g[str[i] - 'A'].pb(i);
		}

		bool on[2] = {0};

		ans = 0;

		for(i = n; i >= 1; i--)
		{
			auto nxt = upper_bound(g[str[i] - 'A'].begin(),g[str[i] - 'A'].end(),i);

			if(nxt == g[str[i] - 'A'].end()) continue;

			ll nxti = *nxt;


			ll id = (str[i] - 'A') ^ 1;

			if(abs(nxti - i) != 1) on[id] = 1;

			if(on[str[i] - 'A'] == 0) nxti++;
			on[str[i] - 'A'] = 1;

			assert(nxti <= (n + 1));

			ll q = query(nxti);

//			cout << i << " " << nxti << " " << q << endl;

			update(i,q + 1,n + 10);
			update(nxti,-q-1,n+10);

			ans += (q + 1);
		}

		printf("%lld\n", ans);
    }


}



