
#include <bits/stdc++.h>

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
    ll i, j, k, l, m, n, o;
    ll testcase;

    scanlld(n);

    scanlld(testcase);

    ll input1, input2, input;

    vector < long long int > arr;
    arr.clear();
    ll result = 1;

    for(i = 0; i < n; i++)
    {
        scanlld(input);

        arr.push_back(input);
    }
    for(i = 1; i < n; i++)
    {
        arr[]
    }


    for(i = 1; i <= testcase; i++)
    {
        scanlld(input1);
        scanlld(input2);

        result = 1;

        for(j = input1 - 1; j < input2; j++)
        {
            result = result * arr[j];
        }

        printlld(result);
    }


}


