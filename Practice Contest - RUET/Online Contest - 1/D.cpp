#include <bits/stdc++.h>`

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld\n", longvalue)

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
    ll n,k,a[55];

    ll i, j, l, m , o, p;

    cin >> n >> k;

    a[0]=1;

    for(i = 1; i < 51;i++)
    {
        a[i]=a[i-1]*2;

        printf("When i = %lld, a[i] = %lld\n", i, a[i]);
    }

    while(k != a[n-1])
    {
        if(k > a[n-1])
        {
            printf("k is bigger then a[n - 1] = %d where n is %d\n", a[n-1], n);
            k=a[n]-k;
            n--;
        }
        else
        {
            n--;
        }
        printf("k is %lld, n is %lld\n", k, n);
    }

    cout << n << endl;
    return 0;
}


