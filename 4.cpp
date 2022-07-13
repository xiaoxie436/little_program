/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: xiezhao2
TASK:dualpal
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
int const maxn = 303;
int n, s;
int ans = 0;
string e = {"0123456789ABCDEFGHIJK"};
bool change(int x, int b)
{
    int k = 0;
    string p;
    while (x)
    {
        p[k++] = e[x % b];
        x /= b;
    }
    for (int i = 0; i < k; ++i)
    {
        if (p[i] != p[k - 1 - i])
            return false;
    }
    return true;
}
int main()
{
    freopen("dualpal.out", "w", stdout);
    freopen("dualpal.in", "r", stdin);
    scanf("%d%d", &n, &s);
    int ans = 0;
    for (int i = s + 1; ans < n; ++i)
    {
        int res = 0;
        for (int j = 2; j <= 10; ++j)
            res += change(i, j);
        if (res >= 2)
        {
            printf("%d\n", i);
            ans++;
        }
    }
    return 0;
}