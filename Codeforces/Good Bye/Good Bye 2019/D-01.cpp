#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

//ll arr[1003];
vector < ll > vec;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(k);

//    for(i = 1; i <= k; i++) arr[i] = i;

    for(i = 1; i <= k + 1; i++)
    {
        cout << "? ";

        for(j = 1; j <= k + 1; j++)
        {
            if(i == j) continue;

            cout << j << " ";
        }

        cout << endl;

        cin >> flag >> input;

        vec.push_back(input);
    }

    ll mx = 0;

    for(auto it:vec) mx = max(mx,it);

    ans = 0;

    for(auto it:vec) if(mx == it) ans++;

    cout << "! " << ans << endl;


}



