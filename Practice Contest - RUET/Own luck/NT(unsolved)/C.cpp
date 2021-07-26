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

bool prime[1000000001];
vector < ll > primestore;
ll sqrtmax = 100000;
map < ll, bool > marked;

void primegen()
{
    primestore.clear();
    prime[0] = true;
    prime[1] = true;

    ll i, j;

    for(i = 4; i <= 1000000000; i = i + 2)
    {
        prime[i] = true;
    }

    primestore.push_back(2);

    for(i = 3; i * i <= 1000000000; i += 2)
    {
        if(prime[i] == false)
        {
            primestore.push_back(i);
            for(j = i * i; j <= 1000000000; j += i)
            {
                prime[j] = true;
            }
        }
    }
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    primegen();

    ll sqrt_input;

    scanlld(testcase);

    ll cnt;

    cout << primestore.size() << endl;

    for(l = 1; l <= testcase; l++)
    {
        scanlld(input);

        marked.clear();

        cnt = 0;
        flag = 0;

        sqrt_input = sqrt(input);
        if(sqrt_input * sqrt_input == input)
        {
            flag = 1;
            sqrt_input--;
        }

        for(i = 0; i < primestore.size(); i++)
        {
            j = primestore[i];

            cout << "->" << j << endl;

            if(j > sqrt_input)
            {
                bug;
                break;
            }
            if(input % j == 0)
            {
                cout << "--" << j << endl;
                cnt++;

                for(k = j + j; k <= sqrt_input; k += j)
                {
                    if(input % k == 0 && k <= sqrt_input)
                    {
                        if(marked[k] == 0)
                        {
                            cout << "--" << k << endl;
                            cnt++;
                            marked[k] = true;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        cnt++;
        cnt = cnt * 2;

        if(flag)
        {
            cnt++;
        }

        cout << cnt << endl;
    }


}


