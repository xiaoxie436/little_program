/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: xiezhao2
TASK: crypt1
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
int const maxn = 22;
int n;
int s[maxn];
int l[maxn];
int main()
{
    freopen("crypt1.out", "w", stdout);
    freopen("crypt1.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &s[i]);
        l[s[i]] = true;
    }
    int a, b, c, d, e, f, g, h, ans = 0;
    for (int i1 = 1; i1 <= n; ++i1)
    {
        a = s[i1];
        if (a == 0)
            continue;
        for (int i2 = 1; i2 <= n; ++i2)
        {
            b = s[i2];
            for (int i3 = 1; i3 <= n; ++i3)
            {
                c = s[i3];
                for (int i4 = 1; i4 <= n; ++i4)
                {
                    d = s[i4];
                    if (d == 0)
                        continue;
                    int g = d * c + d * b * 10 + d * a * 100;
                    if (g > 999)
                        continue;
                    for (int i5 = 1; i5 <= n; ++i5)
                    {
                        e = s[i5];
                        int f = e * c + e * b * 10 + e * a * 100;
                        if (f > 999)
                            continue;
                        h = f + g * 10;
                        int o;
                        if (h > 9999)
                            continue;
                        bool flag = false;
                        o = f;
                        while (o)
                        {
                            if (!l[o % 10])
                            {
                                flag = true;
                                break;
                            }
                            o /= 10;
                        }
                        if (flag)
                            continue;
                        o = g;
                        while (o)
                        {
                            if (!l[o % 10])
                            {
                                flag = true;
                                break;
                            }
                            o /= 10;
                        }
                        if (flag)
                            continue;
                        o = h;
                        while (o)
                        {
                            if (!l[o % 10])
                            {
                                flag = true;
                                break;
                            }
                            o /= 10;
                        }
                        if (flag)
                            continue;
                        ans++;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}