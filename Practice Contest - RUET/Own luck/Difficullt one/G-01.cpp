#include <bits/stdc++.h>`

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




using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;

    scanlld(testcase);

    map < int,int> part[200]; 
    map < int,int> totalsolved[200];
    map < int,int> totaltime[200]; 

    int flag, tag;


    int teamnum;
    int time;
    int problem;
    char code;
    char garb;
    char hund, ten, one;
    scanc(garb);
    scanc(garb);
    o = 0;


    for(i = 1; i <= testcase; i++)
    {
    	if(o == 1)
    	{
    		printnewline;
    	}
    	o = 1;
    	map.clear();

    	while(1)
    	{
    	    //printf("while");
    		scanc(hund);
    		if(hund == 10)
    		{
    		    scanc(garb);
    			break;
    		}
    		scanc(ten);
    		if((ten != 32) && (ten != 10))
            {
                //printf("TEN is %d\n", ten);
    			scanc(one);
    			if((one != 32) && (one != 10))
                {
                    //printf("One is %d\n", one);
                    scanc(garb);
                }
            }


            if(ten == 32 || ten == 10)
    		{
    			teamnum = (hund - 48);
    		}
    		else
    		{

    			if(one == 32 || one == 10)
    			{
    				teamnum = ((hund - 48) * 10) + (ten - 48);
    			}
    			else
    			{
    				teamnum = ((hund - 48) * 100) + ((ten - 48) * 10) + (one - 48);
    			}
    		}

    		scanlld(problem);
    		scanlld(time);
    		scanc(code);
    		if(part[teamnum][problem] == 0)
    		{
    			totalsolved[teamnum]++;
    		}

    		if(code == 'I')
    		{
    			part[teamnum][problem] = part[teamnum][problem] + 20;
    		}
    		else if(code == 'C')
    		{
    			part[teamnum][problem] = part[teamnum][problem] + time;

    			flag = part[teamnum][problem];

    			totaltime[teamnum] = flag;
    		}
    	}




    }


}

