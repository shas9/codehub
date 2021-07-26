#include<bits/stdc++.h>

using namespace std;

#define ll       long long

#define  sci(x)   scanf("%d", &x)
#define  scl(x)   scanf("%lld", &x)
#define  scd(x)   scanf("%lf", &x)

#define  pfi(x)   printf("%d", x)
#define  pfl(x)   printf("%lld", x)
#define  pfd(x)   printf("%lf", x)
#define  pfc(x)   printf("Case %d: ", x++)
#define  ps       printf(" ")
#define  pn       printf("\n")

#define  pb       push_back
#define  ppb      pop_back
#define  pf       push_front
#define  ppf      pop_front
#define  In       insert
#define  All(a)   a.begin(), a.end()

const int types = 26;
char str[200005];
int sz;

struct node
{
	set<int, greater<int> > endmark;
	node *next[types];

	node()
	{
		endmark.clear();
		for(int i = 0; i < types; i++)
			next[i] = NULL;
	}
} *root[100001];

void insert(int indx, int sv)
{
	//cout << str << ' ' << indx << ' ' << sv << endl;
	int len = strlen(str);
	node *curr = root[indx];

	for(int i = 0, id; i < len; i++)
	{
		id = str[i] - 'a';
		curr->endmark.insert(sv + i);

		if(curr->next[id] == NULL)
			curr->next[id] = new node();
		curr = curr->next[id];
	}
	curr->endmark.insert(sv + len);
}

int search(int indx)
{
	int len = strlen(str);
	node *curr = root[indx];
	int ret = 0;

	for(int i = 0, id; i < len; i++)
	{
		id = str[i] - 'a';

		for(auto j: curr->endmark)
		{
			ret = max(ret, j);
			/*if(indx == 0 || indx == 2)
			{
				printf("= %d %d %d\n",i, j, int(curr->endmark.size()));
			}*/
			break;
		}

		if(curr->next[id] == NULL)
		{
			break;
		}
		curr = curr->next[id];
	}

	for(auto j: curr->endmark)
	{
		ret = max(ret, j);
		/*if(indx == 0)
			{
				printf("= %d %d\n",0,  j);
			}*/
		break;
	}
	//cout << "ret = " << ret << ' ' << indx << endl;
	return ret;
}

void del(node *curr)
{
	for(int i = 0; i < types; i++)
		if(curr->next[i])
			del(curr->next[i]);
	//cout << curr->endmark.size() << endl
	curr->endmark.clear();
	delete(curr);
}

void clear()
{
	for(int i = sz ; i >= 0; i--)
		del(root[i]);
}

string s;
int data[100005];

map<string, int> id;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int test, temp, i, n, ans, q;
    sci(test);

    while(test--)
    {
    	id.clear();
    	sci(n);
    	sz = 0;
    	root[0] = new node();
    	for(i = 0; i < n; i++)
    		sci(data[i]);

    	for(i = 0; i < n; i++)
    	{
    		scanf(" %s", str);

    		s = str;
    		//cout << s << endl;
    		insert(0, 0);
    		sort(All(s));
    		temp = id[s];
    		if(!temp)
    		{
    			temp = ++sz;
    			root[temp] = new node();
    			id[s] = temp;
    		}
    		//cout << temp << "  ami " << data[i] << endl;
    		insert(temp, data[i]);
    		//cout << "ok" << endl;
    		//cout << s << endl;
    	}


    	sci(q);

    	while(q--)
    	{
    		ans = 0;
    		scanf(" %s", str);
    		s = str;

    		sort(All(s));

    		temp = id[s];
    		//cout << s << ' ' << temp << endl;
    		ans = search(0);
    		//cout << s << ' ' << ans << endl;
    		if(temp)
    		{
    			ans = max(ans, search(temp));
    		}
    		printf("%d\n", ans);
    	}

    	//cout << "ok" << endl;

    	clear();
    }

    return 0;
}