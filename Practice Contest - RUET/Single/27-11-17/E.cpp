#include <bits/stdc++.h>`

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld\n", longvalue)

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

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    vector < ll > arr;

    ll arrsize;

    scanlld(testcase);

    bool check[100005];

    for(i = 1; i <= testcase; i++)
    {
        arr.clear();
        memset(check,false,sizeof(check));

        scanlld(arrsize);

        flag = 1;

        for(j = 1; j <= arrsize; j++)
        {
            scanlld(input);

            arr.pb(input);

        }

        ll ans;

        for(j = 0; j < arrsize; j++)
        {
            if(arr[j] > 1)
            {
                ans = arr[j];
                break;
            }
        }

        for(j = 1; j < arrsize; j++)
        {
            ans = __gcd(arr[j], ans);
        }

        if(ans != 1)
        {
            flag = 0;
        }

        if(flag == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }



    }

    return 0;


}

