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

ll ring_size;
bool prime[110] = {1};
ll sol_no = 0;
bool marked[20] = {0};

ll check[20];
ll ans[100000][20];

void solve(ll ring_no)
{
    ll i, j, k, l, m;

    //cout << check[ring_no-1] << endl;

    if(ring_no == ring_size + 1)
    {
        if(prime[check[ring_no - 1] + 1] == true)
        {
            for(i = 0; i < 20; i++)
            {
                if(check[i + 1] == 0)
                {
                    break;
                }
                ans[sol_no][i] = check[i + 1];

                //cout << "Here sol: " << sol_no << " i = " << i << " Ans = " << ans[sol_no][i] << endl;
            }
            sol_no++;
        }

        return;
    }

    for(i = 2; i <= ring_size; i++)
    {
        //cout << prime[check[ring_no-1] + i] << "-" << endl;
        if(prime[check[ring_no-1] + i] == true && marked[i] == false)
        {
            marked[i] = true;
            check[ring_no] = i;

            solve(ring_no + 1);

            marked[i] = false;
            check[ring_no] = 0;

        }
    }
}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase = 0;


    for(i = 0; i < 110; i++)
    {
        prime[i] = true;
    }

    prime[0] = 0;
    prime[1] = 0;

    for(i = 2; i*i <= 110; i++)
    {
        if(prime[i] == 1)
        {
            for(j = i * i; j < 110; j += i)
            {
                prime[j] = 0;
            }
        }
    }

    ll tag = 0;

    while(scanlld(ring_size) != EOF)
    {

        if(tag)
        {
            printnewline;
        }
        else
        {
            tag = 1;
        }

        testcase++;
        for(i = 0; i < 20; i++)
        {
            check[i] = 0;
            marked[i] = false;
        }

        check[1] = 1;
        marked[1] = 1;
        sol_no = 0;
        solve(2);

        //cout << sol_no << endl;

        printf("Case %lld:\n", testcase);


        for(i = 0; i < sol_no; i++)
        {
            for(j = 0; j < ring_size - 1; j++)
            {
                printf("%lld ", ans[i][j]);
                //cout << "Here sol: " << sol_no << " j = " << j << " Ans = " << ans[sol_no][i] << endl;
            }

            printf("%lld", ans[i][j]);
            printnewline;
        }
    }


}


