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

struct node{

    char str[35];

    node(char *p)
    {
        ll len1 = strlen(p);

        for(ll i = 0; i <=len1; i++)
            str[i] = p[i];
    }
};

vector < node > arr[4];
ll cnt[4];

bool comp(node a, node b)
{
    ll len1 = strlen(a.str), len2 = strlen(b.str);

    for(ll i = 0; i < min(len1,len2); i++)
    {
        char _a = a.str[i];
        char _b = b.str[i];

        _a = toupper(_a);
        _b = toupper(_b);

        //cout << _a << " " << _b << endl;

        if(_a != _b)
        {
            return _a < _b;
        }
        else
        {
            if(a.str[i] != b.str[i])
            {
                return a.str[i] < b.str[i];
            }
        }
    }

    return len1 < len2;
}

char inn[50005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);

        for(i = 0; i < 4; i++) arr[i].clear();

        for(i = 1; i <= n; i++)
        {
            scanf("%s", &inn);

            arr[inn[0] - 'A'].push_back(node(inn));
        }

        for(i = 0; i < 4; i++)
        {
            sort(arr[i].begin(),arr[i].end(),comp);
        }

        memset(cnt,0,sizeof cnt);

        slld(m);

        getchar();
        for(i = 1; i <= m; i++)
        {
            gets(inn);

            ll val = inn[0] - 'A';

            if(cnt[val] < arr[val].size())
            {
                printf("%s\n", arr[val][cnt[val]].str);
                cnt[val]++;
            }
            else
            {
                printf("Already Mastered\n");
            }
        }




    }


}



