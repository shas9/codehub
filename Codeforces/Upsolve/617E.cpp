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

ll k;

struct node
{
    ll l, r, id, blc;
};

const ll lim = 100005;

node q[lim];
ll ans[lim];
ll freq[3000006];
ll arr[lim];
ll cnt;

bool comp(node a, node b)
{
    if(a.blc != b.blc)
    {
        return a.blc < b.blc;
    }

    if(a.blc % 2 == 0)
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
	ll need = arr[x] ^ k;

	cnt += freq[need];

	freq[arr[x]]++;
}

void rem(ll x)
{
	freq[arr[x]]--;

	ll need = arr[x] ^ k;

	cnt -= freq[need];
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
    ll i, j, l, m, n, o, r;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
		memset(freq,0,sizeof freq);

		n++;

		arr[1] = 0;

		for(ll i = 2; i <= n; i++) cin >> arr[i];
		for(ll i = 2; i <= n; i++) arr[i] ^= arr[i - 1];

		ll ssq = sqrt(n) + 5;

		for(ll i = 1; i <= m; i++)
		{
			cin >> q[i].l;
			cin >> q[i].r;

//			if(q[i].l != 1) q[i].l++;
			q[i].r++;

			q[i].id = i;
			q[i].blc = q[i].l / ssq;
		}

		sort(q + 1, q + 1 + m, comp);

		l = 1, r = 0, cnt = 0;

		for(ll i = 1; i <= m; i++)
		{
//			cout << q[i].l << " " << q[i].r << endl;
			while(l > q[i].l) add(--l);
			while(r < q[i].r) add(++r);
			while(l < q[i].l) rem(l++);
			while(r > q[i].r) rem(r--);

			ans[q[i].id] = cnt;
		}

		for(ll i = 1; i <= m; i++) cout << ans[i] << "\n";
    }


}


