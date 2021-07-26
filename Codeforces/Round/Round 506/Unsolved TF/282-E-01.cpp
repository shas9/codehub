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

const int types = 2;

struct node
{
	int endmark;
	node *next[types];

	node()
	{
		endmark = 0;
		for(int i = 0; i < types; i++)
			next[i] = NULL;
	}
} *root = new node();

void insert(ll n)
{
	node *curr = root;

	for(int i = 42, id; i >= 0; i--)
	{
		id = (n & (1LL << i))? 1 : 0;

		if(curr->next[id] == NULL)
			curr->next[id] = new node();
		curr = curr->next[id];
		curr->endmark++;
	}
//	curr->endmark++;
}

void del(ll n)
{
	node *curr = root;

	for(int i = 42, id; i >= 0; i--)
	{
		id = (n & (1LL << i))? 1 : 0;
		curr = curr->next[id];
		curr->endmark--;
	}

}

ll search(ll n)
{
	node *curr = root;

	ll ret = 0;

	for(int i = 42, id; i >= 0; i--)
	{
		id = (n & (1LL << i))? 1 : 0;
		ll op = id ^ 1;

		if(curr -> next[op] == NULL || curr -> next[op] -> endmark == 0)
        {
            curr = curr ->next[id];
        }
        else
        {
            curr = curr -> next[op];
            ret += (1 )
        }

		if(id == 1)
		{
			if(curr->next[0]==NULL)
			{
				if(curr->next[1]->endmark == 0)
					break;
				curr=curr->next[1];
				ret+=(1LL << i);
			}
			else
			{
				if(curr->next[0]->endmark==0)
				{
					if(curr->next[1]->endmark == 0)
						break;
					curr=curr->next[1];
					ret+=(1LL << i);
				}
				else
				{
					curr=curr->next[0];
				}
			}
		}
		else
		{
			if(curr->next[1]==NULL)
			{
				if(curr->next[0]->endmark == 0)
					break;
				curr=curr->next[0];
			}
			else
			{
				if(curr->next[1]->endmark==0)
				{
					if(curr->next[0]->endmark == 0)
						break;
					curr=curr->next[0];
				}
				else
				{
					curr=curr->next[1];
					ret+=(1LL << i);
				}
			}
		}
	}
//	cout<<ret<<endl;
	return ret;

}

    ll data[100000 + 1];
    ll cumsor[100000 + 1];


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n, i;
    sci(n);



    ll ans = 0;

    insert(0);

    for(i = 1; i <= n; i++)
    {
    	scl(data[i]);
    	cumsor[i] = (cumsor[i - 1] ^ data[i]);
    	insert(cumsor[i]);
    	ans = max(ans, cumsor[i]);
    }
    //cout <<
    ll x = 0;
    for(i = n; i > 1; i--)
    {
    	//ans = max(ans, search)
    	x = (x ^ data[i]);
    	del(cumsor[i]);
    	ans = max(ans, search(x));
    	//cout << ans << endl;
    }

    cout << ans;
    return 0;
}
