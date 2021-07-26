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

char grid[103][103];

struct info
{
	ll x1, y1, x2, y2, x3, y3;
};

vector < info > seq;
ll n, m;

void toggle(ll x, ll y)
{
	assert(x <= n && y <= m);
	if(grid[x][y] == '0') grid[x][y] = '1';
	else grid[x][y] = '0';

	return;
}

void alter(ll x, ll y)
{
	info ret;

	toggle(x,y);

	ret.x1 = x;
	ret.y1 = y;

	if(grid[x][y + 1] == '0')
	{
		toggle(x + 1, y);
		ret.x2 = x + 1;
		ret.y2 = y;

		if(y < m)
		{
			toggle(x + 1, y + 1);
			ret.x3 = x + 1;
			ret.y3 = y + 1;
		}
		else
		{
			toggle(x + 1, y - 1);
			ret.x3 = x + 1;
			ret.y3 = y - 1;
		}
	}
	else
	{
		toggle(x, y + 1);
		ret.x2 = x;
		ret.y2 = y + 1;

		if(y < m)
		{
			toggle(x + 1, y + 1);
			ret.x3 = x + 1;
			ret.y3 = y + 1;
		}
		else
		{
			toggle(x + 1, y);
			ret.x3 = x + 1;
			ret.y3 = y;
		}
	}

	seq.push_back(ret);

	return;
}

void solve3(ll x)
{
	ll cnt = 4;

	info ret;

	for(ll i = n - 1; i <= n; i++)
	{
		for(ll j = x; j <= x + 1; j++)
		{
			if(grid[i][j] == '1')
			{
				cnt--;

				if(cnt == 0) continue;

				toggle(i,j);

				if(cnt == 3) ret.x1 = i, ret.y1 = j;
				if(cnt == 2) ret.x2 = i, ret.y2 = j;
				if(cnt == 1)
				{
					ret.x3 = i, ret.y3 = j;

				}
			}
		}
	}

	seq.push_back(ret);

	assert(cnt == 1);

	return;
}

void solve2(ll x)
{
	ll cnt1 = 1, cnt2 = 2;

	info ret;

	for(ll i = n - 1; i <= n; i++)
	{
		for(ll j = x; j <= x + 1; j++)
		{
			if(grid[i][j] == '1')
			{
				cnt1--;

				if(cnt1 == 0)
				{
					toggle(i,j);
					ret.x3 = i, ret.y3 = j;
				}
			}
			else
			{
				cnt2--;

				if(cnt2 == 1)
				{
					toggle(i,j);
					ret.x1 = i, ret.y1 = j;
				}
				if(cnt2 == 0)
				{
					toggle(i,j);
					ret.x2 = i, ret.y2 = j;
				}
			}
		}
	}

	assert(cnt1 == -1 && cnt2 == 0);

	seq.push_back(ret);

	solve3(x);

	return;
}

void solve1(ll x)
{
	ll cnt1 = 1, cnt2 = 2;

	info ret;

	for(ll i = n - 1; i <= n; i++)
	{
		for(ll j = x; j <= x + 1; j++)
		{
//			cout << grid[i][j] << " ";
			if(grid[i][j] == '1')
			{
				cnt1--;

				if(cnt1 == 0)
				{
					toggle(i,j);
					ret.x3 = i, ret.y3 = j;
				}
			}
			else
			{
				cnt2--;

				if(cnt2 == 1)
				{
					toggle(i,j);
					ret.x1 = i, ret.y1 = j;
				}
				if(cnt2 == 0)
				{
					toggle(i,j);
					ret.x2 = i, ret.y2 = j;
				}
			}
		}
//
//		cout << "\n";
	}

	assert(cnt1 == 0 && cnt2 == -1);

	seq.push_back(ret);

	solve2(x);

	return;
}

void solve4(ll x)
{
	ll cnt = 4;

	info ret;

	for(ll i = n - 1; i <= n; i++)
	{
		for(ll j = x; j <= x + 1; j++)
		{
//			cout << grid[i][j] << " ";
			if(grid[i][j] == '1' )
			{
				cnt--;

				if(cnt == 0) continue;

				toggle(i,j);

				if(cnt == 3) ret.x1 = i, ret.y1 = j;
				if(cnt == 2) ret.x2 = i, ret.y2 = j;
				if(cnt == 1)
				{
					ret.x3 = i, ret.y3 = j;
				}
			}
		}

//		cout << endl;
	}

	assert(cnt == 0);

	seq.push_back(ret);
	solve1(x);

	return;
}
void solve(ll x)
{
	ll cnt = 0;

	for(ll i = n - 1; i <= n; i++)
	{
		for(ll j = x; j <= x + 1; j++)
		{
			if(grid[i][j] == '1') cnt++;
		}
	}

	if(cnt == 4) solve4(x);
	else if(cnt == 3) solve3(x);
	else if(cnt == 2) solve2(x);
	else if(cnt == 1) solve1(x);

	return;
}

void alter1(ll x, ll y)
{
	info ret;

	ret.x1 = x;
	ret.y1 = y;
	ret.x2 = x - 1;
	ret.y2 = y + 1;
	ret.x3 = x;
	ret.y3 = y + 1;

	toggle(x,y);
	toggle(x - 1,y + 1);
	toggle(x,y + 1);

	seq.push_back(ret);

	return;
}

int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		seq.clear();

		cin >> n >> m;

		for(ll i = 1; i <= n; i++) cin >> grid[i] + 1;

		for(ll i = 1; i <= n; i++) grid[i][m + 1] = '0';

		for(ll i = 1; i <= n - 2; i++)
		{
			for(ll j = 1; j <= m; j++)
			{
				if(grid[i][j] == '1') alter(i,j);
			}
		}


		if(m & 1)
		{
			if(grid[n - 1][1] == '1') alter(n - 1, 1);
			if(grid[n][1] == '1') alter1(n,1);

			for(ll i = 2; i <= m; i += 2)
			{
				solve(i);
			}
		}
		else
		{
			for(ll i = 1; i <= m; i += 2)
			{
				solve(i);
			}

		}

		cout << seq.size() << "\n";

		for(info it: seq)
		{
			cout << it.x1 << " " << it.y1 << " " << it.x2 << " " << it.y2 << " " << it.x3 << " " << it.y3 << "\n";
		}

		assert(seq.size() <= (n * m));
    }
}


