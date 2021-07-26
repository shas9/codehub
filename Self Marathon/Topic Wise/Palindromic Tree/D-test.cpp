/*
 * Author: Gatevin
 * Created Time:  2015/3/31 14:25:53
 * File Name: Rin_Tohsaka.cpp
 */
#include <bits/stdc++.h>

using namespace std;
const double eps(1e-8);
typedef long long lint;
typedef unsigned long long ulint;

#define maxn 200010

char A[maxn], B[maxn], s[maxn << 1];
int R[maxn << 1];
const ulint mod = 1e9 + 10071;

set<pair<ulint, ulint> > S;

ulint H[maxn], xp[maxn];
ulint H2[maxn], xp2[maxn];
const ulint seed = 300007uLL;
const ulint seed2 = 500009uLL;

void initHash(char *s, int n)
{
    H[0] = (ulint)(s[0] - 'a' + 1);
    for(int i = 1; i < n; i++)
        H[i] = (H[i - 1]*seed % mod + (ulint)(s[i] -'a' + 1)) % mod;
    return;
}

void initHash2(char *s, int n)
{
    H2[0] = (ulint)(s[0] - 'a' + 1);
    for(int i = 1; i < n; i++)
        H2[i] = H2[i - 1]*seed2 + (ulint)(s[i] - 'a' + 1);
    return;
}

ulint askHash(int l, int r)
{
    if(l == 0)
        return H[r];
    else
        return (H[r] - H[l - 1]*xp[r - l + 1] % mod + mod) % mod;
}

ulint askHash2(int l, int r)
{
    if(l == 0)
        return H2[r];
    else
        return H2[r] - H2[l - 1]*xp2[r - l + 1];
}

int wa[maxn], wb[maxn], wv[maxn], Ws[maxn];

int cmp(int *r, int a, int b, int l)
{
    return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(int *r, int *sa, int n, int m)
{
    int *x = wa, *y = wb, *t, i, j, p;
    for(i = 0; i < m; i++) Ws[i] = 0;
    for(i = 0; i < n; i++) Ws[x[i] = r[i]]++;
    for(i = 1; i < m; i++) Ws[i] += Ws[i - 1];
    for(i = n - 1; i >= 0; i--) sa[--Ws[x[i]]] = i;
    for(j = 1, p = 1; p < n; j <<= 1, m = p)
    {
        for(p = 0, i = n - j; i < n; i++) y[p++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
        for(i = 0; i < n; i++) wv[i] = x[y[i]];
        for(i = 0; i < m; i++) Ws[i] = 0;
        for(i = 0; i < n; i++) Ws[wv[i]]++;
        for(i = 1; i < m; i++) Ws[i] += Ws[i - 1];
        for(i = n - 1; i >= 0; i--) sa[--Ws[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
    }
    return;
}

int rnk[maxn], height[maxn];
void calheight(int *r, int *sa, int n)
{
    int i, j, k = 0;
    for(i = 1; i <= n; i++) rnk[sa[i]] = i;
    for(i = 0; i < n; height[rnk[i++]] = k)
        for(k ? k-- : 0, j = sa[rnk[i] - 1]; r[i + k] == r[j + k]; k++);
    return;
}

int dp[maxn][20];
void initRMQ(int n)
{
    for(int i = 1; i <= n; i++) dp[i][0] = height[i];
    for(int j = 1; (1 << j) <= n; j++)
        for(int i = 1; i + (1 << j) - 1 <= n; i++)
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
    return;
}

int askRMQ(int a, int b)
{
    //int ra = rnk[a], rb = rnk[b];
    int ra = a, rb = b;
    if(ra > rb) swap(ra, rb);
    int k = 0;
    while((1 << (k + 1)) <= rb - ra + 1) k++;
    return min(dp[ra][k], dp[rb - (1 << k) + 1][k]);
}

int calCnt(int l, int r, int n)
{
    int rl = rnk[l];
    int lmost = rl, rmost = rl;
    int L = rl + 1, R = n, mid;
    while(L <= R)
    {
        mid = (L + R) >> 1;
        if(askRMQ(rl + 1, mid) >= r - l + 1)
        {
            L = mid + 1;
            rmost = mid;
        }
        else
            R = mid - 1;
    }
    L = 1, R = rl - 1;
    while(L <= R)
    {
        mid = (L + R) >> 1;
        if(askRMQ(mid + 1, rl) >= r - l + 1)
        {
            R = mid - 1;
            lmost = mid;
        }
        else
            L = mid + 1;
    }
    return rmost - lmost + 1;
}

vector <pair<int, int> > pal;

void Manacher(char *s, int *R, int n)
{
    int mx = 0, p = 0;
    R[0] = 1;
    S.clear(), pal.clear();
    for(int i = 1; i < n; i++)
    {
        if(mx > i) R[i] = min(R[2*p - i], mx - i);
        else R[i] = 1;
        while(s[i - R[i]] == s[i + R[i]])
            R[i]++;
        if(i + R[i] > mx)
        {
            for(int j = mx; j < i + R[i]; j++)
            {
                int l = 2*i - j, r = j;
                l >>= 1;
                r = (r & 1) ? r >> 1 : (r >> 1) - 1;
                if(l > r) continue;
                ulint hashvalue1 = askHash(l, r);
                ulint hashvalue2 = askHash2(l, r);
                set<pair<ulint, ulint> > :: iterator it = S.find(make_pair(hashvalue1, hashvalue2));
                if(it == S.end())
                {
                    S.insert(make_pair(hashvalue1, hashvalue2));
                    pal.push_back(make_pair(l, r));
                }
            }
            mx = i + R[i], p = i;
        }
    }
    return;
}

map<pair<ulint, ulint> , int> Ma, Mb;
int ss[maxn], sa[maxn];

int main()
{

	    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);
    xp[0] = 1uLL;
    xp2[0] = 1uLL;
    for(int i = 1; i < maxn; i++)
        xp[i] = xp[i - 1]*seed % mod, xp2[i] = xp2[i - 1]*seed2;
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++)
    {

        scanf("%s", A);
        scanf("%s", B);

//        	if(cas <= 4) continue;
        int la = strlen(A), lb = strlen(B);

        assert(la <= 200000);
        assert(lb <= 200000);

        initHash(A, la);
        initHash2(A, la);
        s[0] = '@';
        for(int i = 0; i < la; i++)
            s[2*i + 1] = A[i], s[2*i + 2] = '#', ss[i] = A[i] - 'a' + 1;
        s[2*la] = '$';
        ss[la] = 0;
        Manacher(s, R, 2*la);
        da(ss, sa, la + 1, 280);
        calheight(ss, sa, la);
        initRMQ(la);
        Ma.clear();
        for(unsigned int i = 0, sz = pal.size(); i < sz; i++)
            Ma[make_pair(askHash(pal[i].first, pal[i].second), askHash2(pal[i].first, pal[i].second))] = calCnt(pal[i].first, pal[i].second, la);

        initHash(B, lb);
        initHash2(B, lb);
        s[0] = '@';
        for(int i = 0; i < lb; i++)
            s[2*i + 1] = B[i], s[2*i + 2] = '#', ss[i] = B[i] -'a' + 1;
        s[2*lb] = '$';
        ss[lb] = 0;
        Manacher(s, R, 2*lb);
        da(ss, sa, lb + 1, 28);
        calheight(ss, sa, lb);
        initRMQ(lb);
        Mb.clear();
        for(unsigned int i = 0, sz = pal.size(); i < sz; i++)
            Mb[make_pair(askHash(pal[i].first, pal[i].second), askHash2(pal[i].first, pal[i].second))] = calCnt(pal[i].first, pal[i].second, lb);

        lint ans = 0;
        for(map<pair<ulint, ulint> , int> :: iterator it = Ma.begin(); it != Ma.end(); it++)
            if(Mb[(*it).first] != 0)
                ans += (lint)(*it).second*(lint)Mb[(*it).first];
        printf("Case #%d: %I64d\n", cas, ans);
    }
    return 0;
}

/*
————————————————
版权声明：本文为CSDN博主「Gatevin」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/u013738743/java/article/details/44783041

*/
