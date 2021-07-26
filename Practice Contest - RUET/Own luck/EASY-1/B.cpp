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

    string input;

    //read:
    cin >> input;
    tag = 1;

    for(i = 0; i < input.size(); i++)
    {
        if(input[i] > 'Z')
        {
            break;
        }
    }

    if(i != 0 && i != input.size())
    {
        tag = 0;
    }

    if(i != input.size())
    {
        if(input[0] > 'Z')
        {
            for(i = 1; i < input.size(); i++)
            {
                if(input[i] > 'Z')
                {
                    break;
                }
            }

            if(i != input.size())
            {
                tag = 0;
            }
        }
    }

    for(i = 1; i < input.size(); i++)
    {
        if(input[i] < 'Z')
        {
            break;
        }
    }

    if(i == input.size())
    {
        tag = 0;
    }

    if(tag)
    for(i = 0; i < input.size(); i++)
    {
        if(input[i] <= 'Z')
        {
            input[i] += 32;
        }
        else
        {
            input[i] -= 32;
        }
    }

    if(input.size() == 1)
    {
        i = 0;
        if(input[i] <= 'Z')
        {
            input[i] += 32;
        }
        else
        {
            input[i] -= 32;
        }
    }

    cout << input << endl;

    //goto read;

}


