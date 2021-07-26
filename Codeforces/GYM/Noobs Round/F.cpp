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

ll freq[1000006];
ll arr[200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    memset(freq,0,sizeof freq);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n >> m;

		for(ll i = 1; i <= n; i++) cin >> arr[i];

		ll ptr1 = 1, ptr2 = 1;
		ll sum = 0;
		ans = 0;

		while(ptr1 <= n && ptr2 <= n)
		{
			while(ptr2 <= n && sum <= m)
			{
				freq[arr[ptr2]]++;

				if(freq[arr[ptr2]] == 1)
				{
					sum += arr[ptr2];
				}

//				cout << "--> " << ptr2 << " " << sum << endl;

				if(sum <= m && sum)
				{

//					cout << sum << " - " << ptr1 << " " << ptr2 << "\n";
					ans = max(ans, ptr2 - ptr1 + 1);
				}

				ptr2++;
			}
//
//			cout << " now " << ptr1 << " () " << ptr2 << endl;

			while(ptr1 < ptr2 && sum > m)
			{
				freq[arr[ptr1]]--;

				if(freq[arr[ptr1]] == 0)
				{
					sum -= arr[ptr1];
				}

				ptr1++;

				if(sum <= m && sum)
				{
//					cout << sum << " + " << ptr1 << " " << ptr2 << "\n";
					ans = max(ans, ptr2 - ptr1);
				}

			}
		}

		for(ll i = 1; i <= n; i++) freq[arr[i]] = 0;

		cout << ans << "\n";
    }


}



