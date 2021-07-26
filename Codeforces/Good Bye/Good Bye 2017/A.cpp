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

#define pi 3.14159265359


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    char card[55];

    cin >> card;

    flag = strlen(card);

    ans = 0;

    char c = 0;
    for(i = 0; i < flag; i++)
    {
        if(card[i] == 'a' || card[i] == 'e' || card[i] == 'i' || card[i] == 'o' || card[i] == 'u')
        {
            ans++;
        }
        else if(((card[i] - 48) % 2 != 0) && card[i] >= '0' && card[i] <= '9')
        {
            //cout << card[i] - 48 << " " << card[i] << endl;
            ans++;
        }
    }

    cout << ans  << endl;



}


