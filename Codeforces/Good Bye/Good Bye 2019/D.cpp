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

set < ll > st;
ll arr[5005];
bool vis[2000];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(k);

    st.clear();

    for(i = 1; i <= k; i++)
    {
        st.insert(i);
    }

    if(k == 1)
    {
        cout << "! 1" << endl;
        exit(0);
    }

    for(i = 1; i < n; i++)
    {
        cout << "? ";

        for(auto it: st) cout << it;

        cout << endl;

        ll pos, apos;

        cin >> pos >> apos;

        arr[pos] = apos;

        st.erase(st.find(pos));

        st.insert(k + i);
    }


}


