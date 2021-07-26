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

const ll mod1 = 999995813;
const ll mod2 =	999995819;

ll arr[100005];
bool freq[2000005];
ll hsh1[2000005];
ll hsh2[2000005];

map < ll, ll > odd, even;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	hsh1[0] = 1;
	hsh2[0] = 1;

	for(ll i = 1; i <= 2000000; i++) hsh1[i] = (hsh1[i - 1] * 2) % mod1;
	for(ll i = 1; i <= 2000000; i++) hsh2[i] = (hsh2[i - 1] * 2) % mod2;

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		memset(freq,0,sizeof freq);
		odd.clear();
		even.clear();

		even[0] = 1;

		cin >> n;

		for(ll i = 1; i <= n; i++) cin >> arr[i];

		ans = 0;

		ll hashv1 = 0, hashv2 = 0;

		for(ll i = 1; i <= n; i++)
		{
			freq[arr[i]] ^= 1;

			if(freq[arr[i]]) hashv1 = (hashv1 + hsh1[arr[i]]) % mod1;
			else hashv1 = ((hashv1 - hsh1[arr[i]]) % mod1 + mod1) % mod1;

			if(freq[arr[i]]) hashv2 = (hashv2 + hsh2[arr[i]]) % mod2;
			else hashv2 = ((hashv2 - hsh2[arr[i]]) % mod2 + mod2) % mod2;

			ll hashv = hashv1 + (hashv2 << 32);

			if(i & 1) ans += odd[hashv], odd[hashv]++;
			else ans += even[hashv], even[hashv]++;
		}

		printf("Case %lld: %lld\n", cs, ans);
    }


}




