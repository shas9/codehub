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

ll arr[100005];

bool solve(ll sum, ll n)
{
    if(sum % n) return 0;

    sum /= n;

    for(ll i = 1; i <= n; i++)
    {
        ll baki = arr[i] - sum;

        ll nxt = i + 1;

        while(baki)
        {
            if(nxt > n) nxt = 1;

            ll need = sum - arr[nxt];

            if(need <= 0) break;

            if(need > baki) break;

//			arr[nxt] = sum;

            baki -= need;

            nxt++;
        }

        if(nxt > n) nxt = 1;

        if(arr[nxt] >= sum)
        {
            nxt = i + 1;

            while(arr[i] > sum)
            {
                if(nxt > n) nxt = 1;

                ll need = sum - arr[nxt];

                if(need <= 0) break;

                if(need > arr[i] - sum) break;

                arr[nxt] = sum;

                arr[i] -= need;

                nxt++;
            }
        }

        nxt = i - 1;

        while(arr[i] > sum)
        {
            if(nxt < 1) nxt = n;

            ll need = sum - arr[nxt];

            if(need <= 0) break;

            if(need > arr[i] - sum) break;

            arr[nxt] = sum;

            arr[i] -= need;

            nxt--;
        }
    }

    for(ll i = 1; i <= n; i++) if(arr[i] != sum) return 0;

    return 1;
}

bool solve1(ll sum, ll n)
{
    if(sum % n) return 0;

    sum /= n;

    bool on1 = 1, on2 = 1;

    for(ll i = 0; i < n; i += 2)
    {
		if(arr[i] == sum)
		{
			i--;
			continue;
		}

		if(i == (n - 1))
		{
			 if(arr[i] != sum) on1 = 0;

			 continue;
		}

		ll summ = arr[i] + arr[(i + 1) % n];

		if(summ != 2 * sum) on1 = 0;
    }

    for(ll i = 1; i < n; i += 2)
    {
		if(arr[i] == sum)
		{
			i--;
			continue;
		}

		if(i + 1 == (n - 1))
		{
			if(arr[0] != sum) on2 = 0;
		}

		ll summ = arr[i] + arr[(i + 1) % n];

		if(summ != 2 * sum) on2 = 0;
    }

    return (on1 || on2);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        ll sum = 0;
        for(ll i = 0; i < n; i++) slld(arr[i]), sum += arr[i];

        if(solve1(sum,n)) cout << "Yes\n";
        else cout << "No\n";
    }


}



