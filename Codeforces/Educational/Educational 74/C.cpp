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

ll arr[200005];
map < ll, ll > mp;

void test(ll n, ll m)
{
    ll i, j, k, ans;
    for(i = 1; i < m;)
    {
        cout << arr[i] << " " << ans << endl;

        if(arr[i] <= 2) break;

        if(abs(arr[i] - arr[i + 1]) != 1)
        {
            if(mp.find(arr[i + 1] - 1) != mp.end())
            {
                mp[arr[i + 1] - 1] = 1;
                ans++;
                arr[i + 1]--;

                i++;
            }
            else
            {
                i += 2;
            }
        }
        else if(mp.find(arr[i] - 2) == mp.end())
        {
            mp[arr[i] - 2] = 1;
            ans++;

            if(mp.find(arr[i + 1] - 1) != mp.end())
            {
                mp[arr[i + 1] - 1] = 1;
                ans++;
                arr[i + 1]--;

                i++;
            }
            else
            {
                i += 2;
            }
        }
        else i += 2;
    }
}

ll solve(ll n)
{
	bool on = 1;
	ll ret = 0;

	arr[++n] = 2;

	for(ll i = 1; i < n; i++)
	{
		if(arr[i] <= 2)
		{
//			cout << i << " " << on << endl;
			if(on == 0) ret++;
			break;
		}

//		cout << arr[i] << " " << on << " " << ret << endl;

		if(on == 0)
		{
			if(abs(arr[i] - arr[i + 1]) != 1)
			{
				ret++;
			}
			else
			{
				on = 1;
			}
		}
		else if(on)
		{
			if(abs(arr[i] - arr[i + 1]) == 1)
			{
				if(mp.find(arr[i] - 2) != mp.end()) i++;
				else mp[arr[i] - 2] = 1, arr[i + 1]--, ret++;
			}
			else if(arr[i] == 3) break;
			else
			{
				on = 0;
			}
		}

	}

	return ret;
}

bool vis[200005];

ll solve1(ll n)
{
	for(ll i = 1; i <= n; i++) vis[i] = 0;

	ll ret = 0;
	ll cnt = 1;

	vis[1] = 1;
	for(ll i = 2; i <= n; i++)
	{
		if(arr[i] == arr[i - 1] - 1) cnt++, vis[i] = 1;
		else break;

//		cout << "~~" << i << endl;
	}


	if(vis[n] && arr[n] == 1) return 0;

	if(cnt % 2 == 0) ret++;



//	cout << "@@" << ret << endl;
	if(arr[n] == 1 && vis[n] == 0)
	{
		vis[n] = 1;
		for(ll i = n -1; i >= 1; i--)
		{
			if(arr[i] == arr[i + 1] + 1) vis[i] = 1;
			else break;
		}
	}

	cnt = 0;

	for(ll i = 1; i <= n; i++)
	{
		if(vis[i]) continue;

//		cout << "@@" << i << endl;
		if(cnt == 0)
		{
			cnt++;
			continue;
		}

		if(arr[i] == arr[i - 1] - 1)
		{
			cnt++;
		}
		else
		{
			if(cnt % 2) ret++;
			cnt = 1;
		}

//		cout << i << " " << cnt << " " << ret << endl;
	}

	if(cnt & 1) ret++;

	return ret;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);

        mp.clear();

        for(i = 1; i <= m; i++) slld(arr[i]), mp[arr[i]] = 1;

        ans = solve1(m);

        cout << ans << "\n";
    }


}



