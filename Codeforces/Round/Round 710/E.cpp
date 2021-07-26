 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

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

ll arr[200005];
bool f[200005];
ll ans[200005];

void smallest(ll n)
{
    for(ll i = 1; i <= n; i++) f[i] = 0, ans[i] = -1;

    arr[0] = 0;

    for(ll i = 1; i <= n; i++)
    {
        if(arr[i] != arr[i - 1]) ans[i] = arr[i], f[arr[i]] = 1;
    }

    ll now = 1;

    for(ll i = 1; i <= n; i++)
    {
        if(ans[i] == -1)
        {
            while(f[now]) now++;

            ans[i] = now;

            f[now] = 1;
        }
    }

    for(ll i = 1; i <= n; i++) cout << ans[i] << " ";

    cout << '\n';
}

void biggest(ll n)
{
    for(ll i = 1; i <= n; i++) f[i] = 0, ans[i] = -1;

    arr[0] = 0;

    for(ll i = 1; i <= n; i++)
    {
        if(arr[i] != arr[i - 1]) ans[i] = arr[i], f[arr[i]] = 1;
    }

    ll now = n;

    set < ll > st;

    for(ll i = 1; i <= n; i++) if(!f[i]) st.insert(-i);

    ll last = -1;
    for(ll i = 1; i <= n; i++)
    {
        if(ans[i] == -1)
        {
            auto it = st.lower_bound(-last);

            assert(it != st.end());

            ans[i] = *it * -1;

            st.erase(it);
        }
        else last = arr[i];
    }

    for(ll i = 1; i <= n; i++) cout << ans[i] << " ";

    cout << '\n';
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;

        for(ll i = 1; i <= n; i++) cin >> arr[i];

        smallest(n);
        biggest(n);
    }


}

