#include <iostream>
using namespace std;
typedef long long ll;
ll const maxn = 100010;
ll n, m, p;
ll opt, k;
ll tot, rt;
struct tree
{
    ll l, r, s, t, z, n; // l代表左儿子不是左边界
} t[maxn << 1];
void push_up(ll x)
{
    t[x].s = t[t[x].l].s + t[t[x].r].s;
    t[x].s %= p;
}
void addt(ll x, ll i)
{
    t[x].s += t[x].n * i;
    t[x].s %= p;
    t[x].t += i;
    t[x].t %= p;
}
void addz(ll x, ll j)
{
    ll i = t[x].t;
    addt(x, -i);
    t[x].s *= j;
    t[x].s %= p;
    t[x].z *= j;
    t[x].z %= p;
    addt(x, i * j);
}
void addb(ll x, ll i, ll j)
{
    addz(x, j);
    addt(x, i);
}
void push_down(ll x)
{
    addb(t[x].l, t[x].t, t[x].z);
    addb(t[x].r, t[x].t, t[x].z);
    t[x].t = 0;
    t[x].z = 1;
}
ll l, r;
void mul(ll x, ll tl, ll tr)
{
    if (l <= tl and tr <= r)
    {
        addb(x, 0, k);
        return;
    }
    push_down(x);
    ll mid = (tl + tr) >> 1;
    if (l <= mid)
        mul(t[x].l, tl, mid);
    if (mid < r)
        mul(t[x].r, mid + 1, tr);
    push_up(x);
}
void add(ll &x, ll tl, ll tr)
{
    if (!x)
        x = ++tot;
    if (tl == tr)
    {
        t[x].s = k;
    }
    if (l <= tl and tr <= r)
    {
        addb(x, k, 1);
        return;
    }
    push_down(x);
    ll mid = (tl + tr) >> 1;
    if (l <= mid)
        add(t[x].l, tl, mid);
    if (mid < r)
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
    res %= p;
    if (mid < r)
        res += que(t[x].r, mid + 1, tr);
    res %= p;
    return res;
}
int main()
{
    scanf("%lld%lld%lld", &n, &m, &p);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &k);
        add(rt, 1, n);
    }
    while (m--)
    {
        scanf("%lld%lld%lld", &opt, &l, &r);
        if (opt == 1)
        {

            scanf("%lld", &k);
            mul(rt, 1, n);
        }
        else if (opt == 2)
        {
            scanf("%lld", &k);
            add(rt, 1, n);
        }
        else
            printf("%lld\n", que(rt, 1, n));
    }
    return 0;
}