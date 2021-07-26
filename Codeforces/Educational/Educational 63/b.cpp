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


string str;
vector < ll > vec;
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;


    ll len;

    cin >> len >> str;

    ll cnt_8 = 0;

    for(i = 0; i < len; i++)
    {
        if(str[i] == '8')
        {
            cnt_8++;
            vec.push_back(i);
        }
    }

    ll turn = (len - 11) / 2;

    if(turn >= cnt_8)
    {
        cout << "NO" << endl;

        exit(0);
    }

    ll _pos = vec[turn];

    _pos -= turn;

    if(_pos <= turn)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }






}


