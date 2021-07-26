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

    vector < ll > tracks;
    vector < ll > subset;
    vector < ll > unsorted_subset;
    vector < ll > sorted_tracks;
    vector < ll > max_store;

    ll N, tracks_total;

    ll input;

    ll sum;

    ll maxD;

    ll count_1;

    ll temp, flag;
    ll ans;
    ll ANS;

    while(scanlld(N) != EOF)
    {
        maxD = 0;
        ans = 0;
        tracks.clear();
        subset.clear();
        unsorted_subset.clear();
        sorted_tracks.clear();
        sum = 0;
        ll minD = 1000000000;

        scanlld(tracks_total);

        for(i = 1; i <= tracks_total; i++)
        {
            scanlld(input);

            tracks.push_back(input);

            sum += input;

            if(input < minD)
            {
                minD = input;
            }
        }

        if(sum <= N)
        {
            for(i = 0; i < tracks.size(); i++)
            {
                printf("%lld ", tracks[i]);
            }

            printf("sum:%lld\n", sum);
        }
        else if(sum < minD)
        {
            printf("sum:0\n");
        }
        else if(sum == minD)
        {
            printf("%lld sum:%lld\n", minD, minD);
        }
        else
        {
            for (i = 1; i <= (pow(2,tracks_total) - 1); i++)
            {
                sum = 0;

                for (j = 0; j < tracks_total; j++)
                {
                    if ( (i & (1 << j)) != 0 )
                        sum += tracks[j];
                }

                subset.pb(sum);
            }

            ans = 0;

            for(i = 0; i < subset.size(); i++)
            {
                if(subset[i] > ans)
                {
                    if(subset[i] <= N)
                    {
                        ans = subset[i];

                        max_store.clear();

                        flag = i + 1;

                        max_store.push_back(flag);
                    }
                }
                else if(subset[i] == ans)
                {
                    flag = i + 1;
                    max_store.push_back(flag);
                }
            }

            sum = ans;
            flag = 0;

            for(i = 0; i < max_store.size(); i++)
            {
                temp = max_store[i];

                count_1 = 0;

                for(j = 0; j <= tracks.size(); j++)
                {
                    if((temp & (1 << j)) != 0)
                    {
                        count_1++;
                    }
                }

                if(flag < count_1)
                {
                    ans = temp;
                    flag = count_1;
                }
            }

            //cout << ans << endl;
            for(i = 0; i <= tracks.size(); i++)
            {
                if((ans & (1 << i)) != 0)
                {
                    cout << tracks[i] << " ";
                }
            }

            printf("sum:%lld\n",sum);
        }


    }

}

/*
Input:
5 3 1 3 4
10 4 9 8 4 2
20 4 10 5 7 4
90 8 10 23 1 2 3 4 5 7
45 8 4 10 44 43 12 9 8 2

Output:
1 4 sum:5
8 2 sum:10
10 5 4 sum:19
10 23 1 2 3 4 5 7 sum:55
4 10 12 9 8 2 sum:45
*/



