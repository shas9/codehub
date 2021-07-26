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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

#define mx 20000005

bool check(int n, int pos)
{
	return n & (1 << pos);
}

int Set(int n, int pos)
{
	return n = n | (1 << pos);
}

int status[(mx / 32) + 5];

vector < int > primes;

void sieve(int n)
{
    int i, j, sq;

    sq = int( sqrt(n) );

    for(i = 3; i <= sq; i += 2)
    {
        if(check(status[i >> 5], i & 31) == 0)
        {
            for(j = i * i; j <= n; j += (i << 1))
            {
                status[j >> 5] = Set(status[j >> 5], j & 31);
            }
        }
    }

    primes.clear();

    primes.pb(2);

    for(i = 3; i <= n; i += 2)
    {
        if(check(status[i >> 5], i & 31) == 0)
        {
            primes.pb(i);
        }
    }
}

ll mat[1003][1003];
ll n;

void gen(ll x, ll y, ll dir, ll idx)
{
	if(x > n || y > n || x < 1 || y < 1) return;

//	cout << x << " " << y << " " << dir << " " << idx << endl;

	if(dir == 0)
	{
		while(x <= n && y <= n)
		{
			mat[x][y] = primes[idx];
			idx++;

			if(mat[x-1][y] == -1)
			{
				gen(x - 1, y, 1, idx);
				return;
			}
			y++;
		}
	}
	else if(dir == 1)
	{
		while(x >= 1 && y >= 1)
		{
			mat[x][y] = primes[idx];
			idx++;

			if(mat[x][y - 1] == -1)
			{
				gen(x, y - 1, 2, idx);
				return;
			}
			x--;
		}
	}
	else if(dir == 2)
	{
		while(x >= 1 && y >= 1)
		{
			mat[x][y] = primes[idx];
			idx++;

			if(mat[x + 1][y] == -1)
			{
				gen(x + 1, y, 3, idx);
				return;
			}
			y--;
		}
	}
	else
	{
		while(x <= n && y <= n)
		{
			mat[x][y] = primes[idx];
			idx++;

			if(mat[x][y + 1] == -1)
			{
				gen(x, y + 1, 0, idx);
				return;
			}
			x++;
		}
	}
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	sieve(mx - 5);

//	cout << primes.size() << endl;

    slld(n);
    slld(m);

    memset(mat,-1,sizeof mat);

    if(n & 1) mat[n / 2 + 1][n / 2 + 1] = 2;
    else mat[n / 2  + 1][n / 2] = 2;

    gen(n / 2 + 1, (n & 1) ? n / 2 + 2 : n / 2 + 1, 0, 1);


//    printf("\n\n");
//    for(ll i = 1; i <= n; i++)
//    {
//		for(ll j = 1; j <= n; j++) printf("%lld ", mat[i][j]);
//
//		printf("\n");
//    }

	for(ll i = 1; i <= m; i++)
	{
		ll x, y;
		slld(x);
		slld(y);

		printf("%lld\n", mat[x][y]);
	}

}



