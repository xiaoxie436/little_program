#include <iostream>
using namespace std;
typedef long long ll;
ll const maxn = 1e5 + 7;
ll rt, tot, sz[maxn], f[maxn], c[maxn][2], cnt[maxn], val[maxn];
ll n, opt, k;
void mt(ll x)
{
    sz[x] = sz[c[x][0]] + sz[c[x][1]] + cnt[x];
}
bool get(ll x)
{
    return x == c[f[x]][1];
}
void clear(ll x)
{
    sz[x] = f[x] = c[x][0] = c[x][1] = cnt[x] = 0;
}
void rot(ll x)
{
    ll y = f[x], k = get(x);
    if (c[x][k ^ 1])
    {
        c[y][k] = c[x][k ^ 1];
        f[c[x][k ^ 1]] = y;
    }
    if (f[y])
    {
        c[f[y]][get(y)] = x;
        f[x] = f[y];
    }
    c[x][k ^ 1] = y;
    f[y] = x;
    mt(y);
    mt(x);
}
void splay(ll x)
{
    for (ll y = f[x]; y = f[x], y; rot(x))
        if (f[y])
            if (get(x) == get(y))
                rot(y);
            else
                rot(x);
    rt = x;
}
void insert(ll k)
{
    ll x;
    if (!rt)
    {
        x = ++tot;
        val[x] = k;
        cnt[x]++;
        rt = x;
        mt(x);
        return;
    }
    ll y = 0;
    x = rt;
    while (true)
    {
        if (val[x] == k)
        {
            cnt[x]++;
            mt(x);
            mt(y);
            splay(x);
            break;
        }
        y = x;

        x = c[x][val[x] < k];
        if (!x)
        {
            x = ++tot;
            cnt[x]++;
            val[x] = k;
            f[x] = y;
            c[y][val[y] < k] = x;
            mt(x);
            mt(y);
            splay(x);
            break;
        }
    }
}
ll rk(ll k)
{
    ll x = rt, res = 0;
    while (true)
    {
        if (k < val[x])
        {
            x = c[x][0];
            continue;
        }
        res += sz[c[x][0]];
        if (k == val[x])
        {
            splay(x);
            return res + 1;
        }
        res += cnt[x];
        x = c[x][1];
    }
}
ll kth(ll res)
{
    ll x = rt;
    while (true)
    {
        if (c[x][0] and res < sz[c[x][0]])
        {
            x = c[x][0];
            continue;
        }
        res -= sz[c[x][0]] + cnt[x];
        if (res <= 0)
        {
            splay(x);
            return val[x];
        }
        x = c[x][1];
    }
}
ll pre()
{
    ll x = c[rt][0];
    if (!x)
        return x;
    while (c[x][1])
        x = c[x][1];
    splay(x);
    return x;
}
ll nxt()
{
    ll x = c[rt][1];
    if (!x)
        return x;
    while (c[x][0])
        x = c[x][0];
    splay(x);
    return x;
}
void del(ll k)
{
    rk(k);
    if (cnt[rt] > 1)
    {
        cnt[rt]--;
        mt(rt);
        return;
    }
    if (!c[rt][0] and !c[rt][1])
    {
        clear(rt);
        rt = 0;
        return;
    }
    ll x = rt;
    if (!c[rt][0])
    {
        rt = c[rt][1];
        f[rt] = 0;
        clear(x);
        return;
    }
    if (!c[rt][1])
    {
        rt = c[rt][0];
        f[rt] = 0;
        clear(x);
        return;
    }
    ll y = pre();
    f[c[x][1]] = y;
    c[y][1] = c[x][1];
    clear(x);
    mt(rt);
}
int main()
{
    scanf("%lld", &n);
    while (n--)
    {
        scanf("%lld%lld", &opt, &k);
        if (opt == 1)
        {
            insert(k);
        }
        else if (opt == 2)
        {
            del(k);
        }
        else if (opt == 3)
        {
            rk(k);
        }
        else if (opt == 4)
        {
            kth(k);
        }
        else if (opt == 5)
        {
            insert(k);
            printf("%lld", pre());
            del(k);
        }
        else if (opt == 6)
        {
            insert(k);
            printf("%lld", nxt());
            del(k);
        }
    }
    return 0;
}