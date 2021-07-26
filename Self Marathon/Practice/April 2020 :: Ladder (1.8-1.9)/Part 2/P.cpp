#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int

using namespace std;

const ll block = 500;
const ll stt = 10000;
ll i;
ll dsu[402][115000];
ll arr[200005];
ll nxt[402];
ll track[402][10003];

ll fnd(ll blk, ll idx)
{
	if(dsu[blk][idx] <= stt) return dsu[blk][idx];

	return dsu[blk][idx] = fnd(blk,dsu[blk][idx]);
}

int main()
{
    ll j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    slld(n);

    for(i = 0; i <= 400; i++)
    {
		nxt[i] = stt + 500 + 1;
    }

    for(i = 1; i <= n; i++)
    {
		slld(arr[i]);

		ll blk = i / block;
		ll idx = i % block;
		idx += stt + 1;

		if(track[blk][arr[i]] == 0)
		{
			track[blk][arr[i]] = ++nxt[blk];

			dsu[blk][nxt[blk]] = arr[i];
		}

		dsu[blk][idx] = track[blk][arr[i]];
    }

    slld(m);

    ll x, y;

    for(i = 1; i <= m; i++)
    {
		slld(l);
		slld(r);
		slld(x);
		slld(y);

		if(x == y) continue;

		ll lblock = l / block;
		ll rblock = r / block;

		if(track[lblock][y] == 0)
		{
			track[lblock][y] = ++nxt[lblock];

			dsu[lblock][nxt[lblock]] = y;
		}

		if(track[rblock][y] == 0)
		{
			track[rblock][y] = ++nxt[rblock];

			dsu[rblock][nxt[rblock]] = y;
		}

		for(j = l; j <= r && (j / block) == lblock && j <= n; j++)
		{
			ll idx = j % block;
			idx += stt + 1;

			ll val = fnd(lblock,idx);

			if(val != x) continue;

			dsu[lblock][idx] = track[lblock][y];

		}

		if(lblock == rblock) continue;


		for(j = r; j >= 1 && (j / block) == rblock; j--)
		{
			ll idx = j % block;
			idx += stt + 1;

			ll val = fnd(rblock,idx);

			if(val == x)
			{
				dsu[rblock][idx] = track[rblock][y];
			}
		}

		for(j = lblock + 1; j < rblock; j++)
		{
			if(track[j][x] == 0) continue;

			if(track[j][y] == 0)
			{
				track[j][y] = track[j][x];
				dsu[j][track[j][x]] = y;
			}
			else
			{
				dsu[j][track[j][x]] = track[j][y];
			}

			track[j][x] = 0;
		}

    }

    for(i = 1; i <= n; i++)
    {
		ll blk = i / block;
		ll idx = (i % block) + (stt + 1);

		ans = fnd(blk,idx);

		if(i > 1) printf(" ");
		printf("%d", ans);
    }

    printf("\n");

}


