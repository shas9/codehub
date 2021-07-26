#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

string infix, postfix;

void solve()
{
    map < char, ll > mp;
    mp['('] = 0;
    mp['+'] = 1;
    mp['-'] = 1;
    mp['*'] = 2;
    mp['/'] = 2;

    stack < char > op;

    ll sz = infix.size();
    postfix = "";

    for(ll i = 0; i < sz; i++)
    {
        if(infix[i] >= '0' && infix[i] <= '9')
        {
            postfix += infix[i];
        }
        else if(infix[i] == '(')
        {
            op.push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while(op.top() != '(')
            {
                postfix.push_back(op.top());
                op.pop();
            }
            op.pop();
        }
        else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            while(!op.empty() && mp[op.top()] >= mp[infix[i]])
            {
                postfix.push_back(op.top());
                op.pop();
            }

            op.push(infix[i]);
        }
    }


}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    getchar();
    getchar();

    char p;
    for(ll cs = 1; cs <= testcase; cs++)
    {

        char c;

        infix = "(";

        //cout << infix << endl;

        while(scanf("%c", &c) != EOF)
        {
            if(c == '\n' && p == '\n') break;
            infix += c;
            p = c;
        }

        infix += ")";

        solve();

        cout << postfix<< endl;

        if(cs < testcase) cout << endl;
    }


}



