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

ll arr[100005];

bool solve()
{
    ll n, m, i, j;

    slld(n);
    slld(m);

    bool flag = 0;

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);

        if(arr[i] == m) arr[i] = 1, flag = 1;
        else if(arr[i] < m) arr[i] = 0;
        else arr[i] = 2;
    }

    if(!flag) return 0;

    if(n == 1) return 1;

//    for(i = 1; i <= n; i++) cout << arr[i] << " ";
//    cout << endl;

    for(i = 1; i <= n; i++)
    {
		for(j = 1; j <= 2 && i + j <= n; j++)
		{
//			cout << i << " " << i + j << " " << (int)(arr[i] & arr[i + j]) << endl;
			if(arr[i] && arr[i + j]) return 1;
		}
    }

    return 0;
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
        if(solve()) printf("Yes\n");
        else printf("No\n");
    }


}



