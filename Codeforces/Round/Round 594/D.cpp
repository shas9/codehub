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

string str;
ll freq[300005];

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

		ll shft = 0;
		ll mn = mxlld;

		for(i = 0; i < n; i++)
		{
			if(str[i] == '(') sum++;
			else sum--;

			mn = min(mn,sum);

			if(mn == sum) shft = i;
		}

		if(sum != 0)
		{
			printf("0\n1 1\n");
			continue;
		}

		shft++;

		string t = str.substr(shft, n - shft)+ str.substr(0,shft);
		str = t;

		ans = 0;
		pll best = {1,1};
		ll mncnt = 0;

//		cout << str << endl;



		for(i = 0; i < n; i++)
		{
			if(str[i] == '(') sum++;
			else sum--;

			freq[i] = sum;

			if(sum == 0) mncnt++;
		}
		ans = mncnt;
		l = -1;
		ll cnt = 0;

//		cout << ans << endl;
		for(i = 0; i < (n - 1); i++)
		{
			if(freq[i] < 2) l = -1, cnt = 0;

			if(freq[i] == 2)
			{
				if(l == -1)
				{
					l = i;
				}

				cnt++;

//				cout << i << " " << cnt << endl;

				if(str[i + 1] == ')')
				{
					if(cnt + mncnt > ans)
					{
						ans = cnt + mncnt;

						best = {l + shft,i + 1 + shft};
					}
				}


			}
		}

//		cout << ans << endl;
//
//		cout << str << endl;

		for(i = 0; i < (n - 1); i++)
		{
			if(freq[i] < 1) l = -1, cnt = 0;

			if(freq[i] == 1)
			{
				if(l == -1)
				{
					l = i;
				}

				cnt++;

//				cout << i << " " << cnt << endl;

				if(str[i + 1] == ')')
				{
					if(cnt > ans)
					{
						ans = cnt;

						best = {l + shft,i + 1 + shft};
					}
				}
			}
		}

		printf("%lld\n%lld %lld\n", ans, best.first % n + 1, best.second % n + 1);

    }


}


