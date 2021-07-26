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

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

using namespace std;

ll str, stc, enr, enc;
ll ans = 0;
ll moved;

queue < pair < ll, ll > > q;

bool visited[20][20];
ll path[20][20];

ll bfs(ll row, ll col)
{
    pair < ll, ll > current;

    ll x, y, a, b, i, j, k, temp;

    current.first = row;
    current.second = col;

    q.push(current);

    path[row][col] = 0;

    while(!q.empty())
    {
        current = q.front();
        q.pop();

        x = current.first;
        y = current.second;

        //cout << x << "  " << y << endl;

        if(x == enr && y == enc)
        {
            return path[x][y];
        }

        //1

        i = x + 1;
        j = y - 2;

        if(visited[i][j] == false && i > 0 && i < 9 && j > 0 && j < 9)
        {
            visited[i][j] = true;

            path[i][j] = path[x][y] + 1;

            current.first = i;
            current.second = j;

            q.push(current);
        }

        //2

        i = x - 1;
        j = y - 2;

        if(visited[i][j] == false && i > 0 && i < 9 && j > 0 && j < 9)
        {
            visited[i][j] = true;

            path[i][j] = path[x][y] + 1;

            current.first = i;
            current.second = j;

            q.push(current);
        }

        //3
        i = x + 2;
        j = y - 1;

        if(visited[i][j] == false && i > 0 && i < 9 && j > 0 && j < 9)
        {
            visited[i][j] = true;

            path[i][j] = path[x][y] + 1;

            current.first = i;
            current.second = j;

            q.push(current);
        }

        //4
        i = x - 2;
        j = y - 1;

        if(visited[i][j] == false && i > 0 && i < 9 && j > 0 && j < 9)
        {
            visited[i][j] = true;

            path[i][j] = path[x][y] + 1;

            current.first = i;
            current.second = j;

            q.push(current);
        }

        //5
        i = x - 2;
        j = y + 1;

        if(visited[i][j] == false && i > 0 && i < 9 && j > 0 && j < 9)
        {
            visited[i][j] = true;

            path[i][j] = path[x][y] + 1;

            current.first = i;
            current.second = j;

            q.push(current);
        }

        //6
        i = x + 1;
        j = y + 2;

        if(visited[i][j] == false && i > 0 && i < 9 && j > 0 && j < 9)
        {
            visited[i][j] = true;

            path[i][j] = path[x][y] + 1;

            current.first = i;
            current.second = j;

            q.push(current);
        }

        //7
        i = x - 1;
        j = y + 2;

        if(visited[i][j] == false && i > 0 && i < 9 && j > 0 && j < 9)
        {
            visited[i][j] = true;

            path[i][j] = path[x][y] + 1;

            current.first = i;
            current.second = j;

            q.push(current);
        }

        //8
        i = x + 2;
        j = y + 1;

        if(visited[i][j] == false && i > 0 && i < 9 && j > 0 && j < 9)
        {
            visited[i][j] = true;

            path[i][j] = path[x][y] + 1;

            current.first = i;
            current.second = j;

            q.push(current);
        }
    }

    return -1;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    slld(testcase);

    char start[5];
    char endp[5];

    for(i = 1; i <= testcase; i++)
    {
        cin >> start >> endp;

        stc = start[0] - 96;
        str = start[1] - 48;

        enc = endp[0] - 96;
        enr = endp[1] - 48;

        //cout << stc << " " << str << " " << enc << " " << enr << endl;

        moved = mxlld;

        while(!q.empty())
        {
            q.pop();
        }

        memset(visited,false,sizeof(visited));

        memset(path,0,sizeof(path));

        moved = bfs(str, stc);

        cout << moved << endl;
    }


}


