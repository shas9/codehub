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

const ll mx = 1000000;

ll arr[mx];
bool tree[mx*4];
ll brr[mx];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node] = 0;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = tree[left] & tree[right];
}

void update(ll node, ll b, ll e, ll i, bool val)
{
    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        tree[node] = val;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);

    tree[node] = tree[left] & tree[right];
}

ll smallest(ll node, ll b, ll e)
{
	if(b == e) return b;

	ll lft = node * 2;
	ll rgt = lft + 1;

	if(tree[lft] == 0) return smallest(lft, b, (b + e) / 2);
	else return smallest(rgt, ((b + e) / 2) + 1, e);
}

ll mp[mx];

bool solve(ll n)
{
	ll j = 1;

	for(ll i = 1; i <= n; i++)
	{
		if(tree[1]) return 1;

		ll sm = smallest(1,1,mx);

		if(sm > arr[i]) return 1;

		if(sm == arr[i])
		{
			while(mp[j] || j <= arr[i])
			{
				j++;

				if(j > mx) return 1;
			}


			brr[i] = j;

			update(1,1,mx,j,1);

			j++;
		}
		else
		{
			brr[i] = sm;

			update(1,1,mx,sm,1);

			sm = smallest(1,1,mx);

			if(sm != arr[i]) return 1;
		}


//		cout << brr[i] << " && " << endl;

		mp[arr[i]]--;
	}

	for(ll i = 1; i <= n; i++)
	{
		brr[i]--;
	}

	return 0;
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		init(1,1,mx);

		for(i = 1; i <= n; i++)
		{
			slld(arr[i]);
			arr[i]++;
			mp[arr[i]]++;
		}

		if(solve(n)) printf("-1");
		else for(i = 1; i <= n; i++) cout << brr[i] << " ";
		cout << '\n';
    }


}



