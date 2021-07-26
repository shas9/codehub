 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

bool solve()
{
    ll n, a, b;

    cin >> n >> a >> b;

    if(a == 1) return (n - 1) % b == 0;
    if(b == 1) return 1;
    if((n - 1) % b == 0) return 1;


}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//    ll now = 0;
//
//    vector < ll > v;
//    v.push_back(1);
//
//    while(now <= 20)
//    {
//        v.push_back(v[now] * 5);
//        v.push_back(v[now] + 7);
//
//        now++;
//    }
//
//    sort(v.begin(), v.end());
//
//    for(auto it: v) cout << it << " ";
//
//    cout << "\n";

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        if(solve()) cout << "Yes\n";
        else cout << "No\n";
    }


}

