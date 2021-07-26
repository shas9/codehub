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
    ll input, flag = 0, temp;

    cin >> input;

    if(input % 4 == 0 || input % 7 == 0)
    {
        flag = 1;
    }
    else
    {
        m = input;
        while(1)
        {
            if(input == 0)
            {
                break;
            }
            temp = input % 10;

            if(temp != 4 && temp != 7)
            {
                break;
            }

            input /= 10;
        }

        if(input == 0)
        {
            flag = 1;
        }
    }

    if(flag == 0)
    {
        if(m % 44 == 0)
        {
            flag = 1;
        }
        else if(m % 47 == 0)
        {
            flag = 1;
        }
        else if(m % 74 == 0)
        {
            flag = 1;
        }
        else if(m % 77 == 0)
        {
            flag = 1;
        }
        else if(m % 444 == 0)
        {
            flag = 1;
        }
        else if(m % 447 == 0)
        {
            flag = 1;
        }
        else if(m % 477 == 0)
        {
            flag = 1;
        }
        else if(m % 777 == 0)
        {
            flag = 1;
        }
        else if(m % 774 == 0)
        {
            flag = 1;
        }
        else if(m % 744 == 0)
        {
            flag = 1;
        }
        else if(m % 474 == 0)
        {
            flag = 1;
        }
        else if(m % 747 == 0)
        {
            flag = 1;
        }

    }

    if(flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

}


