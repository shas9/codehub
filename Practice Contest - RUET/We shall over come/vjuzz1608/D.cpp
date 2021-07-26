#include <bits/stdc++.h>

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

    vector < ll > subset;
    vector < ll > arr;

    ll t;
    ll input;
    ll limit;

    vector < ll > store_ans;

    ll sum;
    ll last_j;

    map < string, long long int > check;

    string f = "";
    string e;

    ll a, b;

    while(1)
    {
        check.clear();
        subset.clear();
        arr.clear();
        store_ans.clear();

        scanlld(t);
        scanlld(n);

        if(n == 0)
        {
            return 0;
        }

        for(i = 0; i < n; i++)
        {
            scanlld(input);

            arr.push_back(input);
        }
        limit = pow(2,n) - 1;

        for(i = limit; i >= 1; i--)
        {
            sum = 0;
            f = "";
            for(j = 0; j < n; j++)
            {
                if((i & (1 << j)) != 0)
                {
                    sum += arr[n - j - 1];
                    a = arr[n - j - 1];
                    while(a > 0)
                    {
                        b = a % 10;
                        e = b + 48;
                        f += e;
                        a = a / 10;
                    }
                }
            }

            check[f]++;
            if(sum == t && check[f] == 1)
            {
                store_ans.push_back(i);
            }
        }

        printf("Sums of %lld:\n", t);


        if(store_ans.size() == 0)
        {
            printf("NONE\n");
        }
        else
        {
            sort(store_ans.begin(),store_ans.end());
            for(i = (store_ans.size() - 1); i >= 0; i--)
            {
                //cout << "-->" << store_ans[i] << endl;
                for(j = n - 1; j >= 0; j--)
                {
                    if((store_ans[i] & (1 << j)) != 0)
                    {
                        last_j = j;
                    }
                }
                //cout << last_j << endl;
                for(j = n - 1; j >= 0; j--)
                {
                    //cout << j << endl;
                    if((store_ans[i] & (1 << j)) != 0)
                    {
                        printf("%lld", arr[n - j - 1]);
                        if(j != last_j)
                        {
                            printf("+");
                        }
                    }
                }
                printnewline;
            }
        }
    }


}

