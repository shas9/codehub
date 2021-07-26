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


ll aa[100005];
ll mm[100005];
ll mp[45];

vector < pll > vec;

const ll lim = 127700000;

ll mp1[lim + 50];

long long lcm(ll x, ll y)
{
	return (long long)(x * y) / __gcd(x,y);
}

void test()
{
	ll ret = 0;

	for(ll i = 2; i <= 40; i++) ret += (1e8) / i;

	printf("%lld\n", ret);

	ret = 1;

	for(ll i = 2; i <= 40; i++) ret = lcm(ret,i);

	printf("%lld\n", ret);
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;
    long long ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


//	test();

    slld(n);

    for(i = 1; i <= n; i++)
    {
		slld(aa[i]);
    }

    memset(mp,-1,sizeof mp);

    bool no = 0;

    for(i = 1; i <= n; i++)
    {
		slld(input);

		if(mp[input] == -1) mp[input] = aa[i], vec.push_back({input,aa[i]});
		else if(mp[input] != aa[i]) no = 1;

		if(mp[input] >= input) no = 1;
    }

    if(no) printf("Infinity Stones are just a myth\n");
    else
    {
		long long modulo = vec[0].first;

		for(i = 1; i < vec.size(); i++) modulo = lcm(modulo,vec[i].first);

		ans = -1;

		sort(vec.begin(),vec.end());

		for(i = 0; i <= 1e7; i++)
		{
			ll num = (vec.back().first * i) + vec.back().second;

			bool yes = 1;

			for(j = 0; j + 1 < vec.size(); j++)
			{
				if(num % vec[j].first != vec[j].second)
				{
					yes = 0;
					break;
				}
			}

			if(yes)
			{
				ans = num;
				break;
			}
		}

		if(ans == -1) printf("Infinity Stones are just a myth\n");
		else printf("%lld\n", ans % modulo);
    }
}


