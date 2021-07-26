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
    ll flag, tag;

    char input[500];
    char temp;
    map < char,ll > store;
    ll words, words2;

    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanc(temp);
        store.clear();
        words = 0;
        words2 = 0;

        scanf("%[^\n]s", input);

        scanc(temp);

        flag = strlen(input);

        for(j = 0; j < flag; j++)
        {
            if(input[j] != ' ')
            {
                words++;
                temp = input[j];

                if(temp < 'a')
                {
                    temp += 32;
                }

                store[temp]++;
            }
        }


        scanf("%[^\n]s", input);;

        flag = strlen(input);

        for(j = 0; j < flag; j++)
        {
            if(input[j] != ' ')
            {
                words2++;
                if(input[j] < 'a')
                {
                    input[j] += 32;
                }
                temp = input[j];

                if(store[temp] == 0)
                {
                    break;
                }
                else
                {
                    store[temp]--;
                }
            }
        }

        if(j == flag && words2 == words)
        {
            printf("Case %lld: Yes\n", i);
        }
        else
        {
            printf("Case %lld: No\n", i);
        }
    }


}


