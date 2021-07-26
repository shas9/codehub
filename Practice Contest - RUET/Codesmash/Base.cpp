
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

int abul(vector < int > k, d)
{
    return 0;
}


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;

    string name;

    char temp[10];

    cin >> name;
    cin >> l >> m;

    j = 0;

    for(i = l - 1; i < m; i++)
    {
        temp[j] = name[i];
        j++;
    }

    temp[j] = '\0';

    name = temp;

    cout << name << endl;


}

