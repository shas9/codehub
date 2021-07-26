#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m;
bool visit[22][22];
int c[22], q[111111];

int check(int w, int l, int r)
{
     for(int i = l; i < r; i ++)
             if(visit[q[i]][w] == 0)
                             return i;
     return -1;
}

int main()
{
    int t = 1, cse, i, j;
    scanf("%d", &cse);
    while(cse --)
    {
              scanf("%d%d", &n, &m);
              int wheel[22], l = 0, r = n;

              memset(visit, 0, sizeof(visit));
              memset(c, 0, sizeof(c));
              memset(wheel, -1, sizeof(wheel));
              memset(q, 0, sizeof(q));
              for(i = 0; i < n; i ++)
                    q[i] = i;
              int cnt = 0, tot = n * m, ti = 0, w = 0;
              ti ++;
              while(cnt != tot)
              {
                        while(l == r) // if the queue is empty
                        {
                                        while(wheel[w] == -1) // if current wheel is not occupied
                                        {
                                                    w ++;
                                                    w %= m;
                                                    ti ++; //switch to next wheel
                                        }
                                        c[wheel[w]] ++; // the people on the wheel goes down
                                        if(c[wheel[w]] != m)
                                                       q[r ++] = wheel[w]; //if it's the mth time he goes down, then don't let him go into the queue
                                        wheel[w] = -1; //current wheel is available
                                        cnt ++; // tot times plus one
                                        if(cnt >= tot) // if there are no people on the wheel, then break...to avoid while again
                                               break;
                        }
                        if(cnt >= tot) // to avoid an empty queue
                               break;
                        int pos;
                        while((pos = check(w, l, r)) == -1) // if the wheel has been visited by all people
                        {
                                            if(wheel[w] != -1) // if someone is on the wheel
                                            {
                                                        c[wheel[w]] ++;
                                                        if(c[wheel[w]] != m) // if he hasn't visited all those m wheels, push him into the queue again
                                                                q[r ++] = wheel[w];
                                                        wheel[w] = -1; //the wheel is avalable again
                                                        cnt ++;
                                            }
                                            w ++; // switch to next wheel
                                            w %= m;
                                            ti ++;
                        }
                        if(wheel[w] != -1) // if the wheel someone is going to get on is occupied by another person
                        {
                                    c[wheel[w]] ++;
                                    if(c[wheel[w]] != m)
                                                   q[r ++] = wheel[w];
                                    wheel[w] = -1;
                                    cnt ++; // let the man down
                        }
                        visit[q[pos]][w] = 1; // let the person who meets the condition get onto the wheel
                        wheel[w] = q[pos];
                        r --; // minus one of the size of queue
                        for(i = pos; i < r; i ++)
                              q[i] = q[i+1];
                        w ++;
                        w %= m;
                        ti ++;
              }
              printf("Case %d: %d\n", t ++, ti * 5);
    }
}



