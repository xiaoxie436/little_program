/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: xiezhao2
TASK: wormhole
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int const maxn = 13;
int n, ans, res;
struct wormhole
{
    int x, y;
} hole[maxn];
int lex, ley, ory[maxn], orx[maxn];
int par[maxn];
bool vis[maxn];
int farm[maxn][maxn], pas[maxn][maxn];
void discrete()
{
    sort(orx, orx + n);
    sort(ory, ory + n);
    lex = unique(orx, orx + n) - orx;
    ley = unique(ory, ory + n) - ory;
    for (int i = 0; i < n; ++i)
    {
        hole[i].x = lower_bound(orx, orx + lex, hole[i].x) - orx;
        hole[i].y = lower_bound(ory, ory + ley, hole[i].y) - ory;
        farm[hole[i].x][hole[i].y] = i + 1;
    }
}
void cle()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pas[i][j] = false;
        }
    }
}
void dfs(int step)
{
    if (step >= n)
    {
        res++;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cle();
                for (int x = i, y = j; x < n; ++x)
                {
                    if (pas[x][y] > n)
                    {
                        ans++;
                        return;
                    }
                    pas[x][y]++;
                    if (farm[x][y])
                    {
                        int t = farm[x][y] - 1;
                        x = hole[par[t]].x;
                        y = hole[par[t]].y;
                        pas[x][y] = true;
                    }
                }
            }
        }
    }
    int i, j;
    for (i = 0; i < n; ++i)
        if (!vis[i])
            break;
    vis[i] = true;
    for (j = 0; j < n; ++j)
    {
        if (vis[j])
            continue;
        vis[i] = vis[j] = true;
        par[i] = j;
        par[j] = i;
        dfs(step + 2);
        par[i] = par[j] = 0;
        vis[i] = vis[j] = false;
    }
}
int main()
{
    freopen("wormhole.out", "w", stdout);
    freopen("wormhole.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &hole[i].x, &hole[i].y);
        orx[i] = hole[i].x;
        ory[i] = hole[i].y;
    }
    discrete();
    dfs(0);
    printf("%d\n", ans);
    return 0;
}