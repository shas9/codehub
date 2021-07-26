// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long int
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

const ll maxn  = 10000002;
pll vis[maxn+10];
pll arr[1000000];

void sieve()
{
	memset(vis,-1,sizeof vis);

    for(ll i = 2; i <= maxn; i++)
    {
        if(vis[i].first == -1)
        {
			for(ll j = i; j <= maxn; j += i)
			{
//				if(j == 6326) cout << i << endl;

				if(vis[j].first == -1) vis[j].first = i;
				else if(vis[j].second == -1) vis[j].second = i;
				else vis[j].second *= i;
			}
        }
    }

//    cout << vis[6326].first << " " << vis[6326].second << endl;
}

void solve(ll idx,ll num)
{
	if(vis[num].second == -1) arr[idx].first = arr[idx].second = -1;
	else arr[idx] = vis[num];
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    sieve();

    while(cin >> n)
    {
		for(i = 1; i <= n; i++)
		{
			slld(input);

//			if(n == 499999 && i == 6325) cout << input << endl;

			solve(i,input);
		}

		for(i = 1; i <= n; i++) printf("%lld ", arr[i].first);
		printf("\n");
		for(i = 1; i <= n; i++) printf("%lld ", arr[i].second);
		printf("\n");
    }



}


