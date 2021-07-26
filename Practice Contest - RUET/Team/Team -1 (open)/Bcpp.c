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

ll input;

vector < ll > arr;
int main()
{
    ll i, j, k, l, m, n, o;

    scanlld(n);
    arr.clear();

    for(i = 0; i < n; i++)
    {
        scanlld(input);

        arr.push_back(input);
    }

    sort(arr.begin(),arr.end());

    for(i = 0; i < n; i++)
    {
        input = arr[i];

        printlld(input);
    }
}


