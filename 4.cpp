/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: xiezhao2
TASK: combo
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <algorithm>
using namespace std;
int const maxn = 4;
int n;
int s[3][4];
int ans;
int ab(int x, int y)
{
    if (x > y)
    {
        int t = x;
        x = y;
        y = t;
    }
    return min(y - x, n + x - y);
}
bool fc(int x, int y)
{
    for (int i = 0; i < 3; ++i)
    {
        if (ab(s[x][i], s[y][i]) > 2)
            return false;
    }
    return true;
}
bool check()
{
    if (fc(0, 2) or fc(1, 2))
        return true;
    return false;
}
void dfs(int t)
{
    if (t == 3)
    {
        if (check())
            ans++;
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        s[2][t] = i;
        dfs(t + 1);
    }
}
int main()
{
    freopen("combo.out", "w", stdout);
    freopen("combo.in", "r", stdin);
    scanf("%d", &n);
    scanf("%d%d%d%d%d%d", &s[0][0], &s[0][1], &s[0][2], &s[1][0], &s[1][1], &s[1][2]);
    dfs(0);
    printf("%d\n", ans);
    return 0;
}