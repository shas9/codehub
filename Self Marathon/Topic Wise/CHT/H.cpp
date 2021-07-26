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

struct line
{
    ll m, c;

    line(ll x, ll y)
    {
        m = x;
        c = y;
    }
};

struct CHT
{
	vector < ll > M, C;

	ll t, ptr;

	void init(ll x)
	{
		t = x;
		ptr = 0;
		M.clear();
		C.clear();
	}

    bool bad(ll i, ll j, ll k)
    {
        __int128 a = (C[k] - C[i]);
        a = a * (M[i] - M[j]);

        __int128 b = (C[j] - C[i]);
        b = b * (M[i] - M[k]);

        if(t == 1) return a <= b;
        if(t == 2) return a >= b;
        if(t == 3) return a >= b;
        if(t == 4) return a <= b;

        assert(0);
    }

    void add(ll a, ll b)
    {
		if(!M.empty()) assert(M.back() != a);

		M.push_back(a);
		C.push_back(b);

        ll sz = M.size();

        while(sz >= 3 && bad(sz - 3, sz - 2, sz - 1))
        {
            M.erase(M.end() - 2);
            C.erase(C.end() - 2);
            sz--;
        }
    }

    ll ask1(ll x) // pointer search (linear)
    {
		if(ptr >= M.size()) ptr = M.size() - 1;

		while(ptr < (M.size() - 1) && (M[ptr] * x + C[ptr]) <= (M[ptr + 1] * x + C[ptr + 1]))
		{
			ptr++;
		}

		return M[ptr] * x + C[ptr];
    }
};

// 1 = mi > mi+1, mn
// 2 = mi > mi+1, mx
// 3 = mi < mi+1, mn
// 4 = mi < mi+1, mx

struct node
{
	ll x, y;
	long long val;
};

#define ff first
#define ss second

bool cmp(pair<pair<ll,ll>,ll> a, pair<pair<ll,ll>,ll> b){
    return a.ff.ff<b.ff.ff;
}


ll n;
pair<pair<ll,ll>,ll> a[1000002];
ll dp[1000002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(),cout.tie();
	cin>>n;
	for(int i=1;i<=n;i++){
        ll x,y,val;
        cin>>x>>y>>val;
        a[i]={{x,y},val};
	}
	sort(a+1,a+n+1);
    dp[0]=0;
    CHT cht;

    cht.init(2);
    cht.add(0,0);
    for(int i=1;i<=n;i++){
        dp[i]=cht.ask1(a[i].ff.ss)+(a[i].ff.ff*a[i].ff.ss)-a[i].ss;
        cht.add(-a[i].ff.ff,dp[i]);
    }
    ll ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}



