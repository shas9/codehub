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

ll dp[2][51][51][(1 << 10) + 3];
char str[55][1000005];
ll n, m;

ll solve(ll l = 0, ll r = 0, ll mask = 0)
{
    ll &ret = dp[0][l][r][mask];

    if(ret != -1) return ret;

    ll nmask = mask;

    nmask ^= (1 << (str[l][r] - 'a'));

    if(l == (n - 1) && r == (m - 1))
    {
        return ret = 1;
    }


    ret = 0;

    if(l < (n - 1))
    {
        ret = (ret + solve(l + 1, r, nmask)) % mod;
    }

    if(r < (m - 1))
    {
        ret = (ret + solve(l, r + 1, nmask)) % mod;
    }

    return ret;
}


ll solve1(ll l = n - 1, ll r = m - 1, ll mask = 0)
{
//	cout << l << " " << r << " " << mask << endl;
    ll &ret = dp[1][l][r][mask];

    if(ret != -1) return ret;

    ll nmask = mask;

    nmask ^= (1 << (str[l][r] - 'a'));

    if(l == 0 && r == 0)
    {
        return ret = 1;
    }

    ret = 0;

    if(l > 0)
    {
        ret = (ret + solve1(l - 1, r, nmask)) % mod;
    }

    if(r > 0)
    {
        ret = (ret + solve1(l, r - 1, nmask)) % mod;
    }

    return ret;
}

bool no(ll i, ll j, ll k, ll p)
{
    if(dp[p][i][j][k] == -1) return 0;

    return 1;
}


void subtask3()
{
	assert(3 <= m && m <= 40);

	memset(dp,-1,sizeof dp);

	ll ans = 0;
    solve();
    solve1();



    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < m; j++)
        {
            ans = 0;

            for(ll k = 0; k < (1 << 10); k++)
            {
                ll mask = k;

                if(no(i,j,mask,0) && no(i,j,mask,1))
                {
                    ans = (ans + (dp[0][i][j][mask] * dp[1][i][j][mask]) % mod) % mod;
                }

                for(ll p = 0; p < 10; p++)
                {
                    mask = (k ^ (1 << p));

                    if(no(i,j,mask,0) && no(i,j,k,1))
                    {
						cout << i << " & " << j << endl;
						cout << mask << ": ";
						for(ll pp = 0; pp < 10; pp++) cout << check(mask,pp);
						cout << endl;
						cout << k << ": ";
						for(ll pp = 0; pp < 10; pp++) cout << check(k,pp);
						cout << endl;
                        ans = (ans + (dp[0][i][j][mask] * dp[1][i][j][k]) % mod) % mod;

                        cout << endl;
                    }

                }
            }

//            if(j) printf(" ");

//            printf("%lld", ans);
        }

//        printf("\n");
    }
}

void subtask1()
{
	assert(2 <= m && m <= 10000);
    ll mask = 0;

    for(ll i = 0; i < m; i++) mask ^= (1 << (str[0][i] - 'a'));

    ll tot = __builtin_popcount(mask);

    if(tot <= 1)
    {
        for(ll i = 0; i < m; i++)
        {
			if(i) printf(" ");
			cout << 1;
        }
        cout << '\n';
    }
    else
    {
        for(ll i = 0; i < m; i++)
        {
			if(i) printf(" ");
			cout << 0;
        }
        cout << '\n';
    }
}

ll nimask[1000006];
ll mp[(1 << 10)];

void subtask2()
{
	assert(2 <= m && m <= 1000000);

	memset(nimask,0,sizeof nimask);
	memset(mp,0,sizeof mp);

	for(ll i = m - 1; i >= 0; i--)
	{
		nimask[i] = nimask[i + 1] ^ (1 << (str[1][i] - 'a'));
	}

	ll mask = 0;

	for(ll i = 0; i < m; i++)
	{
		mask ^= (1 << (str[0][i] - 'a'));

		ll nmask = mask ^ nimask[i];

		mp[nmask]++;
	}

	mask = 0;
	ll ans = 0;

	for(ll i = 0; i < m; i++)
	{
		ans = 0;

		ans = (ans + mp[mask]) % mod;

		for(ll j = 0; j < 10; j++)
		{
			ll nmask = mask ^ (1 << j);

			ans = (ans + mp[nmask]) % mod;
		}

		mask ^= (1 << (str[0][i] - 'a'));

		mp[mask ^ nimask[i]]--;

		if(i) printf(" ");
		printf("%lld", ans);
	}

	// Second part

	memset(nimask,0,sizeof nimask);
	memset(mp,0,sizeof mp);

	for(ll i = 0; i < m; i++)
	{
		nimask[i] = (1 << (str[0][i] - 'a'));

		if(i) nimask[i] ^= nimask[i - 1];
	}

	mask = 0;

	for(ll i = m - 1; i >= 0; i--)
	{
		mask ^= (1 << (str[1][i] - 'a'));

		ll nmask = mask ^ nimask[i];

		mp[nmask]++;
	}

	mask = 0;

	printf("\n");

	vector < ll > vec;

	for(ll i = m - 1; i >= 0; i--)
	{
		ans = 0;

		ans = (ans + mp[mask]) % mod;

		for(ll j = 0; j < 10; j++)
		{
			ll nmask = mask ^ (1 << j);

			ans = (ans + mp[nmask]) % mod;
		}

		mask ^= (1 << (str[1][i] - 'a'));

		mp[mask ^ nimask[i]]--;

		vec.push_back(ans);
	}

	reverse(vec.begin(),vec.end());

	for(ll i = 0; i < vec.size(); i++)
	{
		if(i) cout << " ";

		cout << vec[i];
	}

	printf("\n");

}
int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    bool type1 = 0;
    bool type2 = 0;
    bool type3 = 0;

    for(ll j = 1; j <= testcase; j++)
    {
		printf("Case %lld:\n",j);

		cin >> n >> m;

		if(n == 1) type1 = 1;
		if(n == 2) type2 = 1;
		if(n >= 3) type3 = 1;

		assert(1 <= n && n <= 40);

        for(ll i = 0; i < n; i++) scanf("%s", str[i]);

        if(n == 1) subtask1();
		else if(n == 2) subtask2();
		else subtask3();
    }

    if(type1) assert(1 <= testcase && testcase <= 10000);
    if(type2) assert(1 <= testcase && testcase <= 10000);
    if(type3) assert(1 <= testcase && testcase <= 30);

    assert(!(type1 & type2));
    assert(!(type3 & type2));
    assert(!(type1 & type3));
}


