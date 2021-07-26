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

string str[105];
multiset < string > ms[4];

void query(ll l, ll r, ll ind)
{
    cout << "? " << l << " " << r << endl;

    ll xx = (r - l + 1);

    string st;

    ll sz = (xx * (xx + 1)) / 2;

//    cout << sz << endl;
    for(ll i = 1; i <= sz; i++)
    {
        cin >> st;

        sort(st.begin(),st.end());

        ms[ind].insert(st);
    }
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    slld(n);

    query(1,n,1);

    if(n == 1)
    {
        cout << "! " << *ms[1].begin() << endl;

        return 0;
    }

    query(1,n - 1, 2);

//    cout << ms[1].size() << " - " << ms[2].size() << " = ";

    for(multiset < string > :: iterator it = ms[2].begin(); it != ms[2].end(); it++)
    {
        ms[1].erase(ms[1].find(*it));
    }

//    cout << ms[1].size() << endl;

    string ansstr = "";

    for(multiset < string > :: iterator it = ms[1].begin(); it != ms[1].end(); it++)
    {
        string xx = *it;

//        cout << xx << " - " << xx.size() << endl;
        str[xx.size()] = xx;
    }

    ll cnt[30];
    ll chk[30];

    memset(cnt, 0, sizeof cnt);

    for(i = 1; i <= n; i++)
    {
        memset(chk, 0, sizeof chk);

//        cout << i << " = " << str[i] << " == ";

        for(j = 0; j < i; j++)
        {
            ll yy = (str[i][j] - 'a');
//            cout << yy << endl;
            chk[yy]++;
        }

//        bug;

        for(j = 0; j < i; j++)
        {
            ll yy = (str[i][j] - 'a');

            if(chk[yy] > cnt[yy])
            {
                ansstr += (yy + 'a');
                cnt[yy]++;
            }
        }

//        bug;
    }

    reverse(ansstr.begin(),ansstr.end());

    cout << "! " << ansstr << endl;


}

