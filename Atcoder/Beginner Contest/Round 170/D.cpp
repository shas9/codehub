// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
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


const ll maxn  = 5000;
vector < ll > primes;
bool vis[maxn+10];

void sieve()
{
    vis[0] = 1;
    vis[1] = 1;

    for(ll i = 4; i <= maxn; i += 2)
    {
        vis[i] = 1;
    }

    for(ll i = 3; i * i <= maxn; i += 2)
    {
        if(vis[i] == 0)
        for(ll j = i * i; j <= maxn; j += i)
        {
            vis[j] = 1;
        }
    }

    for(ll i = 2; i <= maxn; i++)
    {
        if(vis[i] == false)
        primes.pb(i);
    }

}

vector < ll > vec;
map < ll, ll > mp2;
ll mp[1000005];

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
		vec.clear();
		memset(mp,0,sizeof mp);
		mp2.clear();

		for(i = 0; i < n; i++)
		{
			slld(input);
			vec.push_back(input);
			mp2[input]++;
		}

		sort(vec.begin(),vec.end());

		ans = 0;

		for(auto it: vec)
		{
			if(mp2[it] > 1)
			{
				mp[it]++;
				continue;
			}

			bool no = 1;

			for(i = 1; i * i <= it; i++)
			{
				if(it % i) continue;

				ll x = it / i;
				ll y = i;

				if(mp[y]) no = 0;
				if(mp[x]) no = 0;
			}

//			cout << it << " " << no << endl;
			if(no) ans++;

			mp[it]++;
		}

		cout << ans << '\n';
    }


}



