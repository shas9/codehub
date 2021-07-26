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
                sort(negetive.begin(), negetive.end());
                l = -1;

                while(position > 0)
                {
                    l++;
                    frame = negetive[l];
                    //printf("frame is %lld\n", frame);

                    for(j = 0; j < size; j++)
                    {
                        if(store[j] == frame)
                        {
                            store[j] = 0;
                            break;
                        }
                    }
                    //printf("----");
                    position--;
                    //printlld(k);
                    //printnewline;
                }
                sum = 0;
                maxsum = 0;
                /*for(j = 0; j < size; j++)
                {
                    cout << "Dbug: " << store[j] << endl;
                }*/
                while(1)
                {
                    if(store[size - 1]  <= 0)
                    {
                        size--;
                    }
                    else
                    {
                        break;
                    }
                }
                sum = 0;
                maxsum = 0;
                for(j = 0; j < size; j++)
                {
                    if(store[j] < 0)
                    {
                        if(maxsum < sum)
                        {
                            maxsum = sum;
                        }
                        sum = 0;
                    }
                    else
                    {
                        sum = sum + store[j];
                    }
                }
                l = maxsum;
                for(j = 0; j < size - 1; j++)
                {
                    sum = 0;
                    for(k = j; k < size; k++)
                    {
                        sum = sum + store[k];
                    }
                    if(maxsum < sum)
                    {
                        maxsum = sum;
                    }
                }
                if(maxsum < l)
                {
                    maxsum = l;
                }
                printcase(i, maxsum);
            }
        }
    }
    return 0;
}
