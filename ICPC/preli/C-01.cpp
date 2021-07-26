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

    scanlld(testcase);

    ll input;
    ll flag, temp, numb;
    ll ans;
    ll sum;
    map < ll, ll > check;

    for(m = 1; m <= testcase; m++)
    {
        scanlld(input);

        ans = 0;

        ll arr[input][input];

        for(i = 0; i < input; i++)
        {
            for(j = 0; j < input; j++)
            {
                scanlld(numb);

                arr[i][j] = numb;
            }
        }

        if(input < 5)
        {
            ans = 0;
        }
        else
        {
            check.clear();
            for(k = 0; k < (input - 1); k++)
            {
                for(i = 0; i <= (input - 5); i++)
                {
                    sum = 0;
                    printnewline;
                    check.clear();
                    for(j = i; j < i + 5; j++)
                    {
                        for(l = k; l < k + 2; l++)
                        {
                            flag = arr[j][l];
                            check[flag]++;
                            if(check[flag] != 1)
                            {
                                sum = 0;
                                break;
                            }
                            sum += arr[j][l];

                            printf("%lld ", arr[j][l]);
                        }

                        printnewline;
                    }

                    if(sum == 55)
                    {
                        bug;
                        ans++;
                    }
                }
            }

            for(k = 0; k <= (input - 5); k++)
            {
                for(i = 0; i < (input - 1); i++)
                {
                    sum = 0;

                    //printnewline;
                    check.clear();
                    for(j = i; j < i + 2; j++)
                    {
                        for(l = k; l < k + 5; l++)
                        {
                            flag = arr[j][l];
                            check[flag]++;
                            if(check[flag] != 1)
                            {
                                sum = 0;
                                break;
                            }
                            sum += arr[j][l];

                            printf("%lld ", arr[j][l]);
                        }

                        printnewline;
                    }

                    if(sum == 55)
                    {
                        bug;
                        ans++;
                    }
                }
            }

            if(input == 10)
            {
                for(k = 0; k <= (input - 10); k++)
                {
                    for(i = 0; i < (input - 0); i++)
                    {
                        sum = 0;
                        check.clear();
                        printnewline;
                        for(j = i; j < i + 1; j++)
                        {
                            for(l = k; l < k + 10; l++)
                            {
                                flag = arr[j][l];
                                check[flag]++;
                                if(check[flag] != 1)
                                {
                                    sum = 0;
                                    break;
                                }
                                sum += arr[j][l];

                                printf("%lld ", arr[j][l]);
                            }

                            printnewline;
                        }

                        if(sum == 55)
                        {
                            bug;
                            ans++;
                        }
                    }
                }

                    for(k = 0; k <= (input - 0); k++)
                    {
                        for(i = 0; i < (input - 10); i++)
                        {
                            printnewline;
                            sum = 0;
                            check.clear();
                            for(j = i; j < i + 10; j++)
                            {
                                for(l = k; l < k + 1; l++)
                                {
                                    flag = arr[j][l];
                                check[flag]++;
                                if(check[flag] != 1)
                                {
                                    sum = 0;
                                    break;
                                }
                                    sum += arr[j][l];

                                    printf("%lld ", arr[j][l]);
                                }

                                printnewline;
                            }

                            if(sum == 55)
                            {
                                bug;
                                ans++;
                            }
                        }
                    }
            }

        }

        printf("Case %lld: %lld\n", m, ans);
    }


}



