#include <bits/stdc++.h>`

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld", longvalue)

#define scanlf(longvalue) scanf("%lf", &longvalue)
#define printlf(longvalue) printf("%lf\n", longvalue)
#define scanc(letter) scanf("%c", &letter)
#define printc(letter) printf("%c", letter)

#define scans(name) scanf("%s", name)
#define prints(name) printf("%s", name)

#define printnewline printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

using namespace std;

vector < ll > a;

ll binary(ll num, ll sizeofa)
{
    ll high, low, mid;
    high = sizeofa - 1;
    low = 0;
    ll ans;

    while(low <= high)
    {
        mid = (high + low) / 2;

        if(a[mid] == num)
        {
            low = mid + 1;
        }
        else if(a[mid] > num)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return high;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    ll sizeofa, sizeofb;

    vector < ll > b;

    a.clear();
    b.clear();

    scanlld(sizeofa);
    scanlld(sizeofb);

    for(i = 1; i <= sizeofa; i++)
    {
        scanlld(input);

        a.pb(input);
    }


    for(i = 1; i <= sizeofb; i++)
    {
        scanlld(input);

        b.pb(input);
    }

    sort(a.begin(),a.end());

    m = a.size();

    for(i = 1; i <= sizeofb; i++)
    {
        input = b[i - 1];
        ll ans = binary(input,m);

        cout << ans + 1;

        if(i != sizeofb)
        {
            cout << " ";
        }
    }

    cout << endl;





}


