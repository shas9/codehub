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
char out[500];

bool flag;

void recurse(ll pos)
{
    ll sz = str.size();

    if(pos == sz)
    {
        flag = 1;

        out[pos] = '\0';
        return;
    }

    for(ll i = 0; i < sz; i++)
    {
        if(str[i] == ' ') continue;

        out[pos] = str[i];

        if(pos >= 1)
            if(abs(out[pos - 1] - out[pos]) == 1)
                continue;

        str[i] = ' ';

        recurse(pos + 1);

        if(flag) return;

        str[i] = out[pos];
    }
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> str;

        flag = 0;
        recurse(0);

        if(flag)
        {
            cout << out << endl;
        }
        else
        {
            cout << "No answer" << endl;
        }
    }


}


