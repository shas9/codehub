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

    bool teamname[150];

    struct contestant
    {
    	int totalsolved;
    	map < int, int > problem;
    	int totaltime;
    	bool solved[10];
    };

    struct contestant info[150];

bool compare(int A, int B)
{
	if(info[A].totalsolved != info[B].totalsolved)
	{
		return (info[A].totalsolved > info[B].totalsolved);
	}
	else
	{
		if(info[A].totaltime != info[B].totaltime)
		{
			return (info[A].totaltime > info[B].totaltime);
		}
		else
		{
			return (A < B);
		}
	}
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    string garb;

    string line;
    int number;
    int teamnum;
    int probnum;
    int time;
    char code;

    scanlld(testcase);

    getline(cin,garb);

    vector < int > index;
    o = 0;

    for(l = 1; l <= testcase; l++)
    {
        getline(cin,garb);
        //printf("---");
    	if(o)
    	{
    		printnewline;
    		o = 1;
    	}
    	for(i = 0; i < 150; i++)
    	{
    		info[i].totalsolved = 0;
    		info[i].problem.clear();
    		info[i].totaltime = 0;
    		for(j = 0; j < 9; j++)
    		{
    			info[i].solved[j] = 0;
    		}

    		teamname[i] = 0;
    	}
    	index.clear();
    	while(getline(cin,line))
    	{
    	    //cout << "string: " << line << endl;
    		if(line.empty())
    		{
    			break;
    		}
    		stringstream ss(line);

    		ss >> teamnum;
    		ss >> probnum;
    		ss >> time;
    		ss >> code;

    		if(info[teamnum].solved[probnum] == 0)
    		{
    			info[teamnum].totalsolved++;
    			info[teamnum].solved[probnum] = 1;

    		}

    		if(code == 'I')
    		{
    			info[teamnum].problem[probnum] = info[teamnum].problem[probnum] + 20;
    		}
    		else if(code == 'C')
    		{
    			info[teamnum].problem[probnum] = info[teamnum].problem[probnum] + time;
    			info[teamnum].totaltime = info[teamnum].totaltime + info[teamnum].problem[probnum];
    		}

    		if(teamname[teamnum] == 0)
    		{
    			index.push_back(teamnum);
    			teamname[teamnum] = 1;
    		}
    	}

    	sort(index.begin(),index.end(),compare);

    	for(i = 0; i < index.size(); i++)
    	{
    		printf("%d %d %d\n",index[i],info[index[i]].totalsolved,info[index[i]].totaltime);
    	}


    }


}

