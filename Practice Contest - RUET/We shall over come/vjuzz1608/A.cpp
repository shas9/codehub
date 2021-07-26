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

    ll N, tracks_total;

    ll input;

    ll sum;

    ll maxD;

    while(scanlld(N) != EOF)
    {
        maxD = 0;
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

            unsorted_subset = subset;

            sort(subset.begin(), subset.end());

            ll high, low, mid;

            high = subset.size();
            low = 0;

            while(low <= high)
            {
                mid = (high + low) / 2;

                //printlld(subset[mid]);

                if(subset[mid] == N)
                {
                    high = mid;
                    break;
                }
                else if(subset[mid] < N)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }

            ll ans = subset[high];

            sum = subset[subset.size()-1];

            //cout << ans << " : " << sum << endl;

            sorted_tracks = tracks;

            sort(sorted_tracks.begin(), sorted_tracks.end());

            k = 1;

            while(sum - ans > 0)
            {

                sorted_tracks = tracks;
                maxD = sorted_tracks[sorted_tracks.size() - 1];
                sort(sorted_tracks.begin(), sorted_tracks.end());

                for(i = 0; i < sorted_tracks.size(); i++)
                {
                    cout << sorted_tracks[i] << " ";
                }

                cout << endl;

                //cout << sum << endl;

                if((sum - ans) > maxD)
                {
                    sum -= maxD;
                    k++;

                    for(i = 0; i < tracks.size(); i++)
                    {
                        if(tracks[i] == maxD)
                        {
                            tracks[i] = -1;
                        }
                    }

                }
                else if((sum - ans) == maxD)
                {
                    //cout << sum << endl;
                    sum -= maxD;
                    for(i = 0; i < tracks.size(); i++)
                    {
                        if(tracks[i] == maxD)
                        {
                            tracks[i] = -1;
                        }
                    }
                }
                else
                {
                    maxD = sum - ans;

                    high = tracks_total - 1;
                    low = 0;
                    while(low <= high)
                    {
                        mid = (high + low) / 2;

                        //printlld(subset[mid]);

                        //cout << mid << endl;

                        if(sorted_tracks[mid] == maxD)
                        {
                            high = mid;

                            //cout << high << endl;
                            break;
                        }
                        else if(sorted_tracks[mid] < maxD)
                        {
                            low = mid + 1;
                        }
                        else
                        {
                            high = mid - 1;
                        }
                    }

                    for(i = 0; i < tracks_total; i++)
                    {
                        if(sorted_tracks[high] == tracks[i])
                        {
                            high = i;
                        }
                    }

                    cout << " Lower bound: " << tracks[high] << "Max: " << maxD << "Sum: " << sum << endl;


                    /*cout << "HIGH: " << high << endl;
                    cout << "maxD:  " << maxD << " Tracks: " << tracks[high] << endl;*/

                    if(tracks[high] != -1)
                    {
                        sum -= tracks[high];

                        maxD = tracks[high];
                    }

                    //cout << "Sum: " << sum << " maxD: " << maxD << endl;

                    for(i = 0; i < tracks.size(); i++)
                    {
                        if(tracks[i] == maxD)
                        {
                            tracks[i] = -1;
                        }
                    }
                }
            }

            for(i = 0; i < tracks.size(); i++)
            {
                if(tracks[i] != -1)
                {
                    printf("%lld ", tracks[i]);
                }
            }

            printf("sum:%lld\n", ans);
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


