
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

    string name;
    map < string, long long int > salary;
    map < string, long long int > pos;
    string tag;

    char temp[1000];

    ll high, low;

    ll ls;

    ll query;

    ll money;

    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanlld(ls);

        scanlld(query);

        salary.clear();
        pos.clear();
        cin >> name;

        printf("Case %lld:\n", i);

        for(j = 1; j <= query; j++)
        {
            scanlld(low);
            scanlld(high);

            scanlld(money);
            l = 0;

            for(k = low - 1; k < high; k++)
            {
                temp[l] = name[k];
                l++;
            }

            temp[l] = '\0';

            tag = temp;

            salary[tag] = money + salary[tag];
            pos[tag]++;
        }

        scanlld(query);

        for(j = 1; j <= query; j++)
        {
            cin >> tag;

            cout << pos[tag] << " " << salary[tag] << endl;
        }

    }

    return 0;
}


