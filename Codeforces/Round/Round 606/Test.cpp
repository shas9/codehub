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

map < ll, ll > mp;

vector < ll > vec;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);



	for(i = 1; i <= 600; i++)
    {
		for(j = i + 1; j <= 1000; j++)
		{
			k = i ^ j;

			if(mp[i] == 0 && mp[j] == 0 && mp[k] == 0)
			{
				cout << i << " " << j << " " << k <<  " ~~~ ";

				mp[i] = 1;
				mp[j] = 1;
				mp[k] = 1;

				j = 0;

				for(k = 0; k < 42; k += 2)
				{
					if(check(i,k) && check(i, k + 1))
					{
						j = Set(j, k);
					}
					else if(check(i,k) && !check(i, k + 1))
					{
//						cout << " Just ";
						j = Set(j, k + 1);
					}
					else if(!check(i,k) && check(i, k + 1))
					{
						j = Set(j, k + 1);
						j = Set(j, k);
					}
				}

				cout << i << " " << j << " " << (i ^ j) << endl;

			}
		}
    }

//    for(auto it: vec) cout << it<< " ";
//    cout << endl;


}



