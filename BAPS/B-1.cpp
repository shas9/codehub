#include <bits/stdc++.h>


#define scand(value) scanf("%d", &value)
#define printd(value) printf("%d", value)

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld", longvalue)

#define scanc(letter) scanf("%c", &letter)
#define printc(letter) printf("%c", letter)

#define scans(name) scanf("%s", name)
#define prints(name) printf("%s", name)

#define printnewline printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)




using namespace std;

int main()
{
    ll i, j, k, l, m;
    ll testcase;
    ll input;

    scanlld(testcase);

    ll size;
    ll position;
    ll tag;
    ll sum;
    ll maxsum;
    ll frame;

    vector < long long int > store;
    vector < long long int > negetive;
    vector < long long int > temp;

    for(i = 1; i <= testcase; i++)
    {
        store.clear();
        negetive.clear();
        temp.clear();
        scanlld(size);
        scanlld(position);
        for(j = 0; j < size; j++)
        {
            scanlld(input);
            store.push_back(input);
        }
        sum = 0;
        tag = 0;
        while(1)
        {
            if(store[size - 1] < 0)
            {
                size--;
            }
            else
            {
                break;
            }
        }
        for(j = 0; j < size; j++)
        {
            if(store[j] < 0)
            {
                tag = 1;
            }
            else
            {
                sum = sum + store[j];
            }
        }
        if(tag == 0)
        {
            printcase(i,sum);
        }
        else
        {
            for(j = 0; j < size; j++)
            {
                if(store[j] < 0)
                {
                    input = store[j];
                    negetive.push_back(input);
                }
            }

            m = negetive.size();
            if(m <= position)
            {
                printcase(i,sum);
            }
            else
            {
                negetive.clear();
                sum = 0;
                maxsum = 0;
                k = 2;
                while(k < size)
                {
                    negetive.clear();

                }


            }
        }
    }
    return 0;
}

