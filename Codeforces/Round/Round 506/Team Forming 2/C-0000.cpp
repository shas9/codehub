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

vector < pll > neg, zer, pos;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> n)
    {
        neg.clear();
        zer.clear();
        pos.clear();

        for(i = 1; i <= n; i++)
        {
            slld(input);

            if(input < 0) neg.push_back(make_pair(input,i));
            else if(input > 0) pos.push_back(make_pair(input,i));
            else zer.push_back(make_pair(input,i));

        }

        sort(neg.begin(),neg.end());
        sort(pos.begin(),pos.end());

        flag = -1;

        if(zer.size()) flag = zer[0].second;

        for(i = 1; i < zer.size(); i++)
        {
            cout << 1 << " " << flag << " " < zer[i].second << endl;
            flag = zer[i].second;
        }

        if((neg.size() % 2) && zer.size())
        {
            cout << 1 << " " << neg[neg.size() - 1].second << " " << flag << endl;
        }
        else if(neg.size() % 2)
        {
            flag = neg[0].second;
        }

        if(flag)
        {
            cout << 2 << " " << flag << endl;
        }

        for(i = 1; i < neg.size(); i++)

    }

}


