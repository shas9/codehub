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

vector < vector < pll >  > vec;
map < ll, ll > mp;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		vec.clear();
		mp.clear();

		for(i = 1; i <= n; i++)
		{
			slld(input);

			vec.push_back({});
			ll nn = 1;

			for(j = 2; j * j <= input; j++)
			{
				if(input % j) continue;

				ll cnt = 0;

				while(input % j == 0) input /= j, cnt++;

				cnt %= m;

				if(cnt) vec.back().push_back({j,cnt});

				for(k = 1; k <= cnt; k++) nn = (nn * j);
			}

			if(input > 1)
			{
				vec.back().push_back({input,1});

				nn *= input;
			}

//			cout << nn << endl;

			mp[nn]++;
		}

		ans = 0;

		for(auto it: vec)
		{
			ll need = 1;
			ll num = 1;

			for(auto jt: it)
			{
				ll x = (m - jt.second);

				for(i = 1; i <= x; i++) need = (need * jt.first);
				for(i = 1; i <= jt.second; i++) num = (num * jt.first);
			}

//			cout << num << " " << need << " " << mp[need] << endl;

			mp[num]--;

			ans += mp[need];

//			if(need == num) ans--;
		}

		printf("%lld\n", ans);
    }


}



