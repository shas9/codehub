#include <bits/stdc++.h>`

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld\n", longvalue)

#define scanlf(longvalue) scanf("%lf", &longvalue)
#define printlf(longvalue) printf("%lf\n", longvalue)
#define scanc(letter) scanf("%c", &letter)
#define printc(letter) printf("%c", letter)

#define scans(name) scanf("%s", name)
#define prints(name) printf("%s\n", name)

#define printnewline printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

using namespace std;

vector < char > words;
ll n;

char comb[100];


void solve(ll pos, ll tag)
{
    if(pos == n)
    {
        comb[pos] = '\0';
        prints(comb);
        return;
    }


    ll i, j, k, l, flag;

    flag = words.size();

    for(i = tag; i < flag; i++)
    {
        comb[pos] = words[i];

        solve(pos + 1,i + 1);

        while(words[i] == words[i + 1] && i + 1 < flag) i++;
    }
}

int main()
{
    ll i, j, k, l, m, o;
    ll testcase;
    char input[70], tag;
    char flag;

    while(scans(input) != EOF)
    {
        k = strlen(input);
        words.clear();
        check.clear();

        scanlld(n);

        for(i = 0; i < k; i++)
        {
            flag = input[i];
            words.push_back(flag);
        }

        sort(words.begin(),words.end());

        solve(0,0);
    }


}

