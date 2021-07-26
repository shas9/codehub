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
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

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
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

struct Point
{
    ll x, y;
};

Point p0;
vector < pll > conv;
Point arr1[100], arr2[100];

Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

ll swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

ll distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}

ll orientation(Point p, Point q, Point r)
{
    ll val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;

   ll o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;

   return (o == 2)? -1: 1;
}

bool comp(Point a, Point b)
{
    if(a.x == b.x)
        return a.y < b.y;

    return a.x < b.x;
}

void convexHull(Point points[], ll n)
{

    bool on = 0;
    for(ll i = 0; i < (n - 1); i++)
    {
        if(orientation(points[i], points[i + 1], points[(i + 2) % n]) != 0)
        {
            on = 1;
            break;
        }
    }

    if(!on)
    {
        sort(arr1, arr1 + n, comp);

        conv.push_back({arr1[0].x, arr1[0].y});

        conv.push_back({arr1[n-1].x, arr1[n-1].y});

        return;
    }

   ll ymin = points[0].y, min = 0;
   for (ll i = 1; i < n; i++)
   {
     ll y = points[i].y;
     if ((y < ymin) || (ymin == y &&
         points[i].x < points[min].x))
        ymin = points[i].y, min = i;
   }

   swap(points[0], points[min]);

   p0 = points[0];

   qsort(&points[1], n-1, sizeof(Point), compare);

   ll m = 1;
   for (ll i=1; i<n; i++)
   {
       while (i < n-1 && orientation(p0, points[i],
                                    points[i+1]) == 0)
          i++;


       points[m] = points[i];
       m++;  // Update size of modified array
   }

   if (m < 3) return;

   stack<Point> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);

   for (ll i = 3; i < m; i++)
   {
      while (orientation(nextToTop(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }


   while (!S.empty())
   {
       Point p = S.top();
       S.pop();
       conv.push_back(make_pair(p.x,p.y));
   }
}

bool check(Point a)
{
    ll prev = -1;

    if(conv.size() == 2) return false;

    for(ll i = 0; i < conv.size(); i++)
    {
        Point b, c;

        b.x = conv[i].first;
        b.y = conv[i].second;

        c.x = conv[(i + 1) % conv.size()].first;
        c.y = conv[(i + 1) % conv.size()].second;

        ll now = orientation(a, b, c);

        if(now == 0) return false;

        if(prev == -1)
        {
            prev = now;
            continue;
        }

        if(prev != now) return 0;
    }

    return 1;
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        conv.clear();

        ll c, p;

        slld(c);
        slld(p);

        Point xx;

        for(i = 0; i < c; i++)
        {
            slld(xx.x);
            slld(xx.y);

            arr1[i] = xx;
        }

        for(i = 0; i < p; i++)
        {
            slld(xx.x);
            slld(xx.y);

            arr2[i] = xx;
        }

        convexHull(arr1, c);

        cout << "Case " << cs << endl;

        ll mnx = mxlld, mny = mxlld;
        ll pos = -1;

        for(i = 0; i < conv.size(); i++)
        {
            if(conv[i].first == mnx && conv[i].second < mny)
            {
                mny = conv[i].second;
                pos = i;
                continue;
            }

            if(conv[i].first < mnx)
            {
                mnx = conv[i].first;
                mny = conv[i].second;

                pos = i;
            }
        }

        for(i = pos; i >= 0; i--)
        {
            cout << conv[i].first << " " << conv[i].second << endl;
        }

        for(i = conv.size() - 1; i >= pos; i--)
        {
            cout << conv[i].first << " " << conv[i].second << endl;
        }



        for(i = 0; i < p; i++)
        {
            if(check(arr2[i]))
            {
                cout << arr2[i].x << " " << arr2[i].y << " is unsafe!" << endl;
            }
            else
            {
                cout << arr2[i].x << " " << arr2[i].y << " is safe!" << endl;
            }
        }

        cout << endl;
    }


}


