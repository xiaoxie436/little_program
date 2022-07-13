#include <iostream>
using namespace std;
typedef long long ll;
ll const maxn = 1e5 + 7;
ll t, n, p;
struct tree
{
    ll l, r, s, t, n;
} t[maxn << 1];
ll rt;
ll tot;
void push_up(ll x)
{
    t[x].s = t[t[x].l].s + t[t[x].r].s;
}
void addt(ll x, ll k)
{
    t[x].s += t[x].n * k;
    t[x].t += k;
}
void push_down(ll x)
{
    addt(t[x].l, t[x].t);
    addt(t[x].r, t[x].t);
    t[x].t = 0;
}
ll opt, l, r, k;
void add(ll &x, ll tl, ll tr)
{
    if (!x)
    {
        x = ++tot;
        t[x].n = tr - tl + 1;
        t[x].s = 0;
    }
    if (l <= tl and tr <= r)
    {
        addt(x, k);
        return;
    }
    if (t[x].t)
        push_down(x);
    ll mid = (tl + tr) >> 1;
    if (l <= mid)
        add(t[x].l, tl, mid);
    if (mid + 1 <= r)
        add(t[x].r, mid + 1, tr);
    push_up(x);
}
ll que(ll x, ll tl, ll tr)
{
    if (l <= tl and tr <= r)
        return t[x].s;
    push_down(x);
    ll mid = (tl + tr) >> 1, res = 0;
    if (l <= mid)
        res += que(t[x].l, tl, mid);
    if (mid + 1 <= r)
        res += que(t[x].r, mid + 1, tr);
    return res;
}
int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld", &n, &p);

        for (ll i = 1; i <= n; ++i)
        {
            scanf("%lld", &k);
            l = r = i;
            add(rt, 1, n);
        }
        while (m--)
        {
            scanf("%lld%lld%lld", &opt, &l, &r);
            if (opt == 1)
            {
                scanf("%lld", &k);
                add(rt, 1, n);
            }
            if (opt == 2)
                printf("%lld\n", que(1, 1, n));
        }
    }
    return 0;
}