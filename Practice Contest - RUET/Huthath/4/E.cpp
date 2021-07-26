#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    ll alp[30];

    string e[30];

    while(slld(testcase) != EOF)
    {
        memset(alp,0,sizeof(alp));
        for(ll cs = 0; cs < testcase; cs++)
        {
            cin >> e[cs];
        }

        for(i = 0; i < testcase; i++)
        {
            for(j = 0; j < testcase; j++)
            {
                ll temp = e[i][j] - 'A';

                alp[temp]++;
            }
        }

        ll john;

        for(i = 0; i < 26; i++)
        {
            //cout << alp[i] << endl;
            if(alp[i] == 1 || alp[i] > testcase)
            {
                john = i;
                //cout << john << endl;
            }

            if(alp[i] < testcase && alp[i] > 1)
            {
                flag = i;
                //cout << flag << endl;
            }
        }

        if(alp[john] == 1)
        {
            for(i = 0; i < testcase; i++)
            {
                for(j = 0; j < testcase; j++)
                {
                    //cout << "-->" << i << " " << j << endl;
                    ll temp = e[i][j] - 'A';
                    //cout << temp << " " << john << endl;

                    if(temp == john)
                    {
                        printf("%lld %lld %c\n", i+1, j+1, flag + 'A');

                        break;
                    }
                }
            }
        }
        else
        {
            bool check[26];

            for(i = 0; i < testcase; i++)
            {
                memset(check,false,sizeof(check));
                for(j = 0; j < testcase; j++)
                {
                    ll temp = e[i][j] - 'A';

                    if(check[temp] == false)
                    {
                        check[temp] = true;
                    }
                    else
                    {
                        bool checkr = false;
                        for(k = 0; k < testcase; k++)
                        {
                                tag = e[k][j] - 'A';

                                if(tag == flag)
                                {
                                    checkr = true;
                                }
                        }
                        if(checkr == false)
                        {
                            printf("%lld %lld %c\n", i+1, j+1, flag + 'A');
                        }
                        else
                        {
                            for(k = 0; k < testcase; k++)
                            {
                                tag = e[i][k] - 'A';

                                //cout << k << " - " << tag << " " << endl;

                                if(tag == john)
                                {
                                    printf("%lld %lld %c\n", i+1, k+1, flag + 'A');
                                    break;
                                }
                            }
                        }

                        break;
                    }
                }
            }
        }


    }


}

/*
3
IWL
WIW
WLI

*/

