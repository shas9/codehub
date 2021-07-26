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

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

char str[3][200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);

		scanf("%s", str[0]+1);
		scanf("%s", str[1]+1);

		ll nx = 0, ny = 1;

		bool on = 1;
		ll prv = 0;

		while(on)
		{
//				cout << str[nx][ny] << endl;
			if(str[nx][ny] == '1' || str[nx][ny] == '2')
			{
				if(prv == 0) ny += 1;
				else
				{
					on = 0;
					break;
				}
			}
			else
			{
				if(prv == 0) nx ^= 1, prv = 1;
				else ny += 1, prv = 0;
			}
//			cout << nx << " " << ny << " " << prv << endl;

			if(nx == 1 && ny == (n + 1)) break;

			if(nx > 1) on = 0;
			if(ny > n) on = 0;
		}

		if(on) printf("YES\n");
		else printf("NO\n");

    }


}



