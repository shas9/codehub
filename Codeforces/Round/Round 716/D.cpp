 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll int
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x
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

struct node
{
    ll l, r, id;
};

const ll lim = 300005;

node q[lim];
ll ans[lim];
ll freq[300006];
ll mx[300006];
ll arr[lim];
ll cnt;
ll block = 916;

bool comp(node a, node b)
{
    ll ablc = a.l / block;
    ll bblc = b.l / block;

    if(ablc != bblc)
    {
        return ablc < bblc;
    }

    if(ablc % 2 == 0)
    {
        return a.r < b.r;
    }
    else
    {
        return a.r > b.r;
    }
}


void add(ll x)
{
	freq[arr[x]]++;
	mx[freq[arr[x]]]++;

	cnt = (freq[arr[x]] > cnt ? freq[arr[x]]: cnt);
}

void rem(ll x)
{
	mx[freq[arr[x]]]--;
	freq[arr[x]]--;

	cnt -= (mx[cnt] == 0? 1: 0);
}


// q[i].blc = l / ssq;  /// block count

/*
	l = 1, r = 0, cnt = 0;

    while(l > q[i].l) add(--l);
    while(r < q[i].r) add(++r);
    while(l < q[i].l) rem(l++);
    while(r > q[i].r) rem(r--);
*/


int main()
{
    ll i, j, k, l, m, n, r;
    ll testcase;
    ll in;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;
    while(cin >> n >> m)
    {
        for(ll i = 1; i <= n; i++) cin >> arr[i];

        block = sqrt(n) * 2;

        block = max(1, block);

        for(ll i = 1; i <= m; i++)
        {
            cin >> q[i].l >> q[i].r;
            q[i].id = i;
        }

        sort(q + 1, q + 1 + m, comp);

        l = 0, r = 0;
        cnt = 0;

        for(ll i = 1; i <= m; i++)
        {
            while(l > q[i].l) add(--l);
            while(r < q[i].r) add(++r);
            while(l < q[i].l) rem(l++);
            while(r > q[i].r) rem(r--);

            ans[q[i].id] = cnt * 2 - (r - l + 1);
        }

        for(ll i = 1; i <= m; i++)
        {
            cout << max(1, ans[i]) << "\n";
        }
    }


}


