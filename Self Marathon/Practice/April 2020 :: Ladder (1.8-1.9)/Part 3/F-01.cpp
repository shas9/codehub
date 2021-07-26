// God put a smile upon your face <3

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

#define mod 1000000007

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

ll dist[100][100][2];
ll nr[100][100];
ll comb[100][100][2];

ll ncr(ll n, ll r)
{
	if(r > n) return 0;
	if(r == 0) return 1;
	if(r == n) return 1;

	if(nr[n][r] != -1) return nr[n][r];

	return nr[n][r] = (ncr(n-1,r) + ncr(n - 1, r - 1)) % mod;
}

ll n, k, small, big;

struct node
{
	ll small, big, state, val;

	node(ll a, ll b, ll c, ll d)
	{
		small = a;
		big = b;
		state = c;
		val = d;
	}
};

const bool operator < (const node &a, const node &b)
{
	return a.val < b.val;
}

ll calc(ll x, ll y, ll z)
{
//	cout << x << " " << y << " " << z << endl;
	return (x * ((y * z) % mod)) % mod;
}

pll solve()
{
	queue < node > st;

	st.push(node(small,big,0,0));

	comb[small][big][0] = 1;
	dist[small][big][0] = 0;

	while(!st.empty())
	{
//		set < node > :: iterator it = st.begin();

		node top = st.front();
		st.pop();

//		cout << top.small << " " << top.big << " " << " " << top.state << " " << top.val << endl;

		for(ll i = 0; i <= top.small; i++)
		{
			for(ll j = 0; j <= top.big; j++)
			{
				if(i + j == 0) continue;

				if(i * 50 + j * 100 > k) continue;

				node nd = node(0,0,0,0);

				nd.state = top.state ^ 1;
				nd.small = small - (top.small - i);
				nd.big = big - (top.big - j);
				nd.val = top.val + 1;

//				cout << nd.small << " ~~ " << nd.big << " " <<  dist[nd.small][nd.big][nd.state] <<endl;

				if(dist[nd.small][nd.big][nd.state] > top.val + 1)
				{
//					bug;
//					st.erase(node(nd.small,nd.big,nd.state,dist[nd.small][nd.big][nd.state]));

					dist[nd.small][nd.big][nd.state] = top.val + 1;

					comb[nd.small][nd.big][nd.state] = calc(comb[top.small][top.big][top.state],ncr(top.small,i),ncr(top.big,j));

//					bug;

//					cout << nd.small << " @@ " << nd.big << " @@ " <<  dist[nd.small][nd.big][nd.state] <<endl;
					st.push(nd);
				}
				else if(dist[nd.small][nd.big][nd.state] == top.val + 1)
				{
					comb[nd.small][nd.big][nd.state] += calc(comb[top.small][top.big][top.state],ncr(top.small,i),ncr(top.big,j));
					comb[nd.small][nd.big][nd.state] %= mod;
				}

//				cout << "!! " << st.size() << endl;

			}
		}
	}

	if(dist[small][big][1] == mxlld) return {-1,0};

	return {dist[small][big][1], comb[small][big][1]};
}


int main()
{
    ll i, j, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	memset(nr,-1,sizeof nr);
    while(cin >> n >> k)
    {
		small = 0;
		big = 0;

		for(i = 0; i <= n; i++) for(j = 0; j <= n; j++) for(r = 0; r <= 1; r++) dist[i][j][r] = mxlld, comb[i][j][r] = 0;

		for(i = 1; i <= n; i++)
		{
			slld(input);

			if(input == 50) small++;
			else big++;
		}

		pll ans = solve();

		printf("%lld\n%lld\n", ans.first,ans.second);
    }


}



