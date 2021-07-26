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

char a[1003][1003], b[1003][1003], c[1003][1003];
ll cnta, cntb;
ll bb[1003][1003];
ll n, m;

ll dx[] = {-1,-1,-1,0,0,1,1,1};
ll dy[] = {-1,0,1,-1,1,-1,0,1};

void calca()
{
	cnta = 0;

	for(ll i = 1; i <= n; i++)
	{
		for(ll j = 1; j <= m; j++)
		{
			for(ll k = 0; k < 8; k++)
			{
				ll nx = i + dx[k];
				ll ny = j + dy[k];

				if(nx < 1 || nx > n || ny < 1 || ny > m) continue;

				if(a[i][j] == 'X') continue;
				if(a[nx][ny] == 'X') cnta++;
			}
		}
	}

	return;
}

void calcb()
{
	cntb = 0;

	for(ll i = 1; i <= n; i++)
	{
		for(ll j = 1; j <= m; j++)
		{
			ll tot = 0;

			for(ll k = 0; k < 8; k++)
			{
				ll nx = i + dx[k];
				ll ny = j + dy[k];

				if(nx < 1 || nx > n || ny < 1 || ny > m) continue;


				if(b[i][j] == 'X') continue;
				if(b[nx][ny] == 'X') tot++;
			}

			bb[i][j] = tot;
			cntb += tot;
		}
	}

	return;
}

bool solve()
{
	ll mov = 0;

//	cout << cnta << " " << cntb << "\n";

	for(ll i = 1; i <= n; i++)
	{
		for(ll j = 1; j <= m  && cntb > cnta; j++)
		{
			ll jog = 0;
			ll biyog = 0;

			if(b[i][j] == 'X')
			{
				for(ll k = 0; k < 8; k++)
				{
					ll nx = i + dx[k];
					ll ny = j + dy[k];

					if(nx < 1 || nx > n || ny < 1 || ny > m) continue;

					if(b[nx][ny] == 'X') jog++;
					else biyog++;
				}

				if(jog < biyog)
				{
					cntb -= (biyog - jog);
					mov++;
					b[i][j] = '.';
				}
			}
			else
			{
				for(ll k = 0; k < 8; k++)
				{
					ll nx = i + dx[k];
					ll ny = j + dy[k];

					if(nx < 1 || nx > n || ny < 1 || ny > m) continue;

					if(b[nx][ny] != 'X') jog++;
					else biyog++;
				}

				if(jog < biyog)
				{
					cntb -= (biyog - jog);
					mov++;
					b[i][j] = 'X';
				}
			}
		}
	}


//	cout << cnta << " " << cntb << "\n";
//	for(ll i = 1; i <= n; i++) cout << b[i] + 1 << "\n";


	for(ll i = 1; i <= n; i++)
	{
		for(ll j = 1; j <= m  && cntb < cnta; j++)
		{
			ll jog = 0;
			ll biyog = 0;

			if(b[i][j] == 'X')
			{
				for(ll k = 0; k < 8; k++)
				{
					ll nx = i + dx[k];
					ll ny = j + dy[k];

					if(nx < 1 || nx > n || ny < 1 || ny > m) continue;

					if(b[nx][ny] == 'X') jog++;
					else biyog++;
				}

				if(jog > biyog)
				{
//					cout << i << " ^^ " << j << endl;
					cntb -= (biyog - jog);
					mov++;
					b[i][j] = '.';
				}
			}
			else
			{
				for(ll k = 0; k < 8; k++)
				{
					ll nx = i + dx[k];
					ll ny = j + dy[k];

					if(nx < 1 || nx > n || ny < 1 || ny > m) continue;

					if(b[nx][ny] != 'X') jog++;
					else biyog++;
				}

				if(jog > biyog)
				{
//					cout << i << " ++ " << j << endl;
					cntb -= (biyog - jog);
					mov++;
					b[i][j] = 'X';
				}
			}
		}
	}

//
//	cout << cnta << " " << cntb << "\n";
//	for(ll i = 1; i <= n; i++) cout << b[i] + 1 << "\n";


	for(ll i = 1; i <= n; i++)
	{
		for(ll j = 1; j <= m  && cntb > cnta; j++)
		{
			ll jog = 0;
			ll biyog = 0;

			if(b[i][j] == 'X')
			{
				for(ll k = 0; k < 8; k++)
				{
					ll nx = i + dx[k];
					ll ny = j + dy[k];

					if(nx < 1 || nx > n || ny < 1 || ny > m) continue;

					if(b[nx][ny] == 'X') jog++;
					else biyog++;
				}

				if(jog < biyog && (cntb - cnta >= (jog - biyog)))
				{
					cntb -= (biyog - jog);
					mov++;
					b[i][j] = '.';
				}
			}
			else
			{
				for(ll k = 0; k < 8; k++)
				{
					ll nx = i + dx[k];
					ll ny = j + dy[k];

					if(nx < 1 || nx > n || ny < 1 || ny > m) continue;

					if(b[nx][ny] != 'X') jog++;
					else biyog++;
				}

				if(jog < biyog  && (cntb - cnta >= (jog - biyog)))
				{
					cntb -= (biyog - jog);
					mov++;
					b[i][j] = 'X';
				}
			}
		}
	}



//	cout << cnta << " " << cntb << "\n";
//	for(ll i = 1; i <= n; i++) cout << b[i] + 1 << "\n";

	return mov <= (n * m) / 2 && (cnta == cntb);
}

bool solve1()
{
	ll mov = 0;

	for(ll i = 1; i <= n; i++) c[i][m + 1] = '\0';

	for(ll i = 1; i <= n; i++) for(ll j = 1; j <= m; j++) mov += a[i][j] != b[i][j], c[i][j] = a[i][j];

//	cout << mov << "\n";

	if(mov <= ((n * m) / 2)) return 1;

	mov = 0;

	for(ll i = 1; i <= n; i++)
		for(ll j = 1; j <= m; j++)
			if(a[i][j] == '.') a[i][j] = 'X';
			else a[i][j] = '.';


	for(ll i = 1; i <= n; i++) for(ll j = 1; j <= m; j++) mov += a[i][j] != b[i][j], c[i][j] = a[i][j];

	if(mov <= ((n * m) / 2)) return 1;

}

bool solve2()
{
	priority_queue < pair < ll, pll > > pq;

ll mov = 0;

//	cout << cnta << " " << cntb << "\n";

	for(ll i = 1; i <= n; i++)
	{
		for(ll j = 1; j <= m  && cntb > cnta; j++)
		{
			ll jog = 0;
			ll biyog = 0;

			if(b[i][j] == 'X')
			{
				for(ll k = 0; k < 8; k++)
				{
					ll nx = i + dx[k];
					ll ny = j + dy[k];

					if(nx < 1 || nx > n || ny < 1 || ny > m) continue;

					if(b[nx][ny] == 'X') jog++;
					else biyog++;
				}

				if(jog < biyog)
				{
					cntb -= (biyog - jog);
					mov++;
					b[i][j] = '.';
				}
			}
			else
			{
				for(ll k = 0; k < 8; k++)
				{
					ll nx = i + dx[k];
					ll ny = j + dy[k];

					if(nx < 1 || nx > n || ny < 1 || ny > m) continue;

					if(b[nx][ny] != 'X') jog++;
					else biyog++;
				}

				if(jog < biyog)
				{
					cntb -= (biyog - jog);
					mov++;
					b[i][j] = 'X';
				}
			}
		}
	}


//	cout << cnta << " " << cntb << "\n";
//	for(ll i = 1; i <= n; i++) cout << b[i] + 1 << "\n";


	for(ll i = 1; i <= n; i++)
	{
		for(ll j = 1; j <= m  && cntb < cnta; j++)
		{
			ll jog = 0;
			ll biyog = 0;

			if(b[i][j] == 'X')
			{
				for(ll k = 0; k < 8; k++)
				{
					ll nx = i + dx[k];
					ll ny = j + dy[k];

					if(nx < 1 || nx > n || ny < 1 || ny > m) continue;

					if(b[nx][ny] == 'X') jog++;
					else biyog++;
				}

				if(jog > biyog)
				{
//					cout << i << " ^^ " << j << endl;
					cntb -= (biyog - jog);
					mov++;
					b[i][j] = '.';
				}
			}
			else
			{
				for(ll k = 0; k < 8; k++)
				{
					ll nx = i + dx[k];
					ll ny = j + dy[k];

					if(nx < 1 || nx > n || ny < 1 || ny > m) continue;

					if(b[nx][ny] != 'X') jog++;
					else biyog++;
				}

				if(jog > biyog)
				{
//					cout << i << " ++ " << j << endl;
					cntb -= (biyog - jog);
					mov++;
					b[i][j] = 'X';
				}
			}
		}
	}
}

int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		for(ll i = 1; i <= n; i++) cin >> a[i] + 1;
		for(ll i = 1; i <= n; i++) cin >> b[i] + 1;

		calca();
		calcb();

		if(solve1())
		{
			for(ll i = 1; i <= n; i++) cout << c[i] + 1 << "\n";
		}
		else
		{
			cout << -1 << "\n";
		}
    }


}



