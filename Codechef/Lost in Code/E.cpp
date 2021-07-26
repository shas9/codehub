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

ll freq[27][1000006];
char str[1000006];
char ss[10];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    {
		cin >> n;
//		bug;
		scanf(" %s", str + 1);

//		cout << str + 1 << endl;

		ll len = strlen(str + 1);

//		cout << str + 1 << endl;

		for(i = 0; i < 26; i++) freq[i][0] = 0;

		for(i = 1; i <= len; i++)
		{
			freq[str[i] - 'A'][i]++;
		}

		for(i = 1; i <= len; i++)
		{
			for(j = 0; j < 26; j++)
			{
				freq[j][i] += freq[j][i - 1];
			}
		}

		slld(m);

		for(i = 1; i <= m; i++)
		{
			scanf("%lld %s", &r, ss);

			ll pp = r;

			ll ch = ss[0] - 'A';

			assert(ch >= 0 && ch <= 25);

			ll tmp = 1;

			if(r & 1) tmp = (tmp * ((r - 1) / 2)) % len, tmp = ((tmp % len) * (r % len)) % len;
			else tmp = (tmp * (r / 2)) % len, tmp = ((tmp % len) * ((r - 1) % len)) % len;


			ans = 0;


			r += tmp;

			assert(tmp >= 0);

//			cout << (long long)tmp << " " << r << endl;

			if(tmp) ans -= freq[ch][tmp];

//			cout << ans << " && ";

			ans += freq[ch][len] * (r / len);

//			cout << ans << " " << freq[ch][len] << " " << r / len << endl;

			ll rem = r % len;

			ans += freq[ch][rem];

			printf("%lld\n", ans);

			assert(ans >= 0);

		}
    }
}



