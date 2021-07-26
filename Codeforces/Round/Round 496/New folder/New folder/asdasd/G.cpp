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
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

struct node{
    ll a,b;
};

vector<node>v;

bool cmp(node x,node y)
{
    ll p=abs(x.a-x.b);
    ll q=abs(y.a-y.b);
    return p<q;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);
    node tmp;
    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(tmp.a);
        slld(tmp.b);
        v.pb(tmp);


    }

    sort(v.begin(),v.end(),cmp);

    ll aa=0,bb=0;
    string str;
    for(i=0;i<testcase;i++)
    {
        if(v[i].a+aa-bb<=500)
        {
            str.pb('A');
            aa+=v[i].a;
        }
        else if(v[i].b-aa+bb<=500)
        {
            str.pb('G');
            bb+=v[i].b;
        }
        else
        {
            cout<<"-1"<<endl;
            return 0;
        }

    }
    cout<<str;


}

