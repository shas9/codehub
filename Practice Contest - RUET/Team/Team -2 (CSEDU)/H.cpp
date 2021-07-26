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
    ll num;

    map < string, ll > flag;
    vector < string > store;

    string input;
    string temp_1, temp_2;
    string temp;

    while(scanlld(num) != EOF)
    {
        flag.clear();

        for(i = 1; i <= num; i++)
        {
            temp_1 = "";
            temp_2 = "";
            cin >> input;

            store.push_back(input);

            temp_1 += input[0];
            temp_2 += input[1];

            flag[temp_1]++;
            flag[temp_2]++;
        }

        temp = vector[0];

        while(1)
        {
            temp_1 = "";
            temp_2 = "";

            temp_1 += temp[0];
            temp_2 += temp[1];
        }



    }


}

