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

    scanlld(testcase);

    vector < int > array;
    vector < int > sorted;
    vector < int > temp;

    ll size;
    ll input;
    ll max;
    ll count;
    ll maxcount;
    ll tag;
    ll prev, now;


    for(i = 1; i <= testcase; i++)
    {
        array.clear();
        sorted.clear();
        temp.clear();

        scanlld(size);
        for(j = 0; j < size; j++)
        {
            scanlld(input);
            array.push_back(input);
        }
        sorted = array;

        sort(sorted.begin(), sorted.end());

        if(sorted[0] == sorted[size-1])
        {
            printf("neutral\n");
        }
        else if(sorted == array)
        {
            printf("allGoodDays\n");
        }
        else
        {
            for(j = size - 1; j >= 0; j--)
            {
                input = sorted[j];
                temp.push_back(input);
            }

            if(temp == array)
            {
                printf("allBadDays\n");
            }
            else
            {
                count = 0;
                tag = 0;
                maxcount = 0;
                for(j = 1; j < size - 1; j++)
                {
                    if((array[j - 1] < array[j]) && (array[j + 1] < array[j]))
                    {
                        now = j;
                        if(tag == 0)
                        {
                            prev = now;
                        }
                        tag++;
                        count = now - prev;
                        prev = now;
                        if(maxcount < count)
                        {
                            maxcount = count;
                        }
                    }


                }

                if(maxcount == 0)
                {
                    printf("none\n");
                }
                else
                {
                    maxcount--;
                    printlld(maxcount);
                    printnewline;
                }
            }
        }
    }
    return 0;
}

