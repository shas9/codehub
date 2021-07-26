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

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    string x = "qwertyuiopasdfghjkl;zxcvbnm,./";

    char c;
    string in;

    cin >> c >> in;

    if(c == 'R')
    {
        ll sz = in.size();

        for(i = 0; i < sz; i++)
        {
            if(in[i] == 'q' || in[i] == 'a' || in[i] == 'z') continue;
            for(j = 0; j < x.size(); j++)
            {
                if(in[i] == x[j])
                {
                    in[i] = x[j - 1];
                    break;
                }
            }
        }
    }
    else
    {
        ll sz = in.size();

        for(i = 0; i < sz; i++)
        {
            if(in[i] == 'p' || in[i] == '/' || in[i] == ';') continue;
            for(j = 0; j < x.size(); j++)
            {
                if(in[i] == x[j])
                {
                    in[i] = x[j + 1];
                    break;
                }
            }
        }
    }

    cout << in << endl;


}


