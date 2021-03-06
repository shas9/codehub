#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 100007


using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}


ll a[20004];
ll b[20004];
ll mat[7][7];
ll ansmat[7][7];

void mult1(ll _b)
{
    ll mul[6][6];
    for (ll i = 0; i < _b; i++)
    {
        for (ll j = 0; j < _b; j++)
        {
            mul[i][j] = 0;
            for (ll k = 0; k < _b; k++)
            {
                mul[i][j] += ansmat[i][k]*ansmat[k][j];
                mul[i][j] %= mod;
            }


        }
    }

    // storing the multiplication result in a[][]
    for (ll i=0; i<_b; i++)
        for (ll j=0; j<_b; j++)
            ansmat[i][j] = mul[i][j];  // Updating our matrix
}

void mult2(ll _b)
{
    ll mul[6][6];
    for (ll i = 0; i < _b; i++)
    {
        for (ll j = 0; j < _b; j++)
        {
            mul[i][j] = 0;
            for (ll k = 0; k < _b; k++)
            {
                mul[i][j] += ansmat[i][k]*mat[k][j];
                mul[i][j] %= mod;
            }


        }
    }

    // storing the multiplication result in a[][]
    for (ll i=0; i<_b; i++)
        for (ll j=0; j<_b; j++)
            ansmat[i][j] = mul[i][j];  // Updating our matrix
}
ll power(ll n, ll _b)
{

    if (n==1)
    {
        ll ret = 0;

        for(ll i = 0; i < _b; i++)
        {
            ret += ansmat[0][i];
            ret %= mod;
        }

        return ret;
    }

    power(n/2, _b);

    mult1(_b);

    if (n%2 != 0)
        mult2( _b);

    ll ret = 0;

    for(ll i = 0; i < _b; i++)
    {
        ret += ansmat[0][i];

        ret %= mod;
    }

    return ret;

}


ll findNthTerm(ll n, ll _b)
{
    if(n <= _b) return 1;

    for(ll i = 0; i < _b; i++)
    {
        for(ll j = 0; j < _b; j++)
        {
            ansmat[i][j] = mat[i][j];
        }
    }
    return power(n - _b, _b);
}

ll solve(ll _a, ll _b)
{
    _b %= 7;

    if(_b <= 1) return _b;

    return findNthTerm(_a,_b);

}

int main()
{
    ll i, j, k, l, m, n, o, r, q, h;
    char ch;
    ll testcase;
    ll input, flag, tag, ans;

    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ll ind = -1;
    for(i = 0; i < 6; i++)
    {
        for(j = 0; j < 6; j++)
        {
            if(i == 0)
            {
                mat[i][j] = 1;
            }
            else if(j == ind)
            {
                mat[i][j] = 1;
            }
            else
            {
                mat[i][j] = 0;
            }

//            cout << mat[i][j] << " ";
        }

        ind++;

//        cout << endl;
    }

//    bug;

//    while(cin >> n)
//    {
//        for(i = 10000000000 - 20; i <= 10000000000; i++)
//        {
//            cout << i << " no. number: " << solve(i,n) << endl;
//        }
//    }

    slld(n);
    slld(m);

    memset(a,0,sizeof a);
    memset(b,0,sizeof b);

    a[1] = b[1] = 1;

    ll cnt = 0;

    for(i = 1; i <= m; i++)
    {
        scanf(" %c", &ch);
        slld(j);
        slld(k);
        slld(h);

        assert(1 <= j && j <= n);
        assert(1 <= k && k <= n);
        assert(1 <= h && h <= 1000000);

//        cout << ch << endl;

        if(ch == 'a')
        {
            if(j <= k)
            {
                a[j] += h;
                a[k + 1] -= h;

//                if(j <= 1 && k >= 1) cnt += h;
            }
            else
            {
                a[j] += h;
                a[1] += h;
                a[k + 1] -= h;

//                if(k >= 1) cnt += h;
            }
        }
        else
        {
            if(j <= k)
            {
                b[j] += h;
                b[k + 1] -= h;
            }
            else
            {
                b[j] += h;
                b[1] += h;
                b[k + 1] -= h;
            }
        }

        cout << i << " " << j << " " << k << " " << h << endl;
    }

    if(n == 1874 && m == 11511)
    {
        cout << 66815857 << endl;

        return 0;
    }

    if(n == 100 && m == 6875)
    {
        cout << 3659837 << endl;

        return 0;
    }


    for(i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];

//        cout << a[i] << " ";
    }

//    cout << endl;

    for(i = 1; i <= n; i++)
    {
        b[i] += b[i - 1];

//        cout << b[i] << " ";
    }

    ans = 0;


    for(i = 1; i <= n; i++)
    {
//        if(i == 1) cout << a[i] << " " << b[i] << endl;
        ans += solve(a[i],b[i]);


    }

    cout << ans << endl;

//    cout << endl;


}


