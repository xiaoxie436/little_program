#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
ll const maxn = 1e5 + 5;
ll T, n, p;
bool l[maxn];
ll o[maxn]; // operation
ll a[maxn]; // num
struct tree
{
    ll s; // 总乘积 % p
    ll l, r;
    ll ls, rs;
    set<ll> v;      // 2操作
    vector<bool> b; // 1操作有效数
} t[maxn << 2];
void push_up(ll x)
{
    for (ll i = 0; i < t[t[x].rs].v.size(); ++i)
    {
        if (t[x].l <= t[x].rs.v[i])
        {
            t[x].b[t[x].rs.v[i]] = 1;
        }
    }
}
void build(ll x, ll l, ll r)
{
    t[x].s = 1;
    t[x].l = l;
    t[x].r = r;
    t[x].nv = t[x].nb = 0;
    t[x].v.clear();
    t[x].b.clear();
    for (int i = 0; i < r - l + 1; ++i)
        t[x].b.push_back(0);
    t[x].ls = x << 1;
    t[x].rs = x << 1 | 1;
    if (l == r)
    {
        t[x].ls = t[x].rs = 0;
        if (o[l] == 1)
        {
            t[x].s = a[l];
            t[x].b.push_back(l);
        }
        if (o[l] == 2)
            t[x].v.insert(a[l]);
        return;
    }
    ll mid = (l + r) >> 1;
    build(t[x].ls, l, mid);
    build(t[x].rs, mid + 1, r);
    push_up(x);
}
int main()
{
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld%lld", &n, &p);
        for (ll i = 1; i <= n; ++i)
        {
            l[i] = 0;
            scanf("%lld%lld", &o[i], &a[i]);
            if (o[i] == 1)
                a[i] %= p;
        }
        build(1, 1, n);
    }
    return 0;
}