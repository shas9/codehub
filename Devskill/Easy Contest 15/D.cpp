
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

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999




using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    slld(testcase);

    ll len;

    char st[2000];

    map < char, ll > store;

    char c;

    ll ans;
    ll moved;

    char most;
    for(i = 1; i <= testcase; i++)
    {
        slld(len);

        cin >> st;

        ans = 0;
        moved = 0;

        store.clear();

        for(j = 0; j < len; j++)
        {
            store[st[j]]++;

            if(store[st[j]] > ans)
            {
                most = st[j];
                ans = store[st[j]];
            }
        }

        moved = len - ans;

        cout << moved << endl;

    }


}

