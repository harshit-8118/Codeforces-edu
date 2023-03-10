//     ॐ  भगवन् सब आपको समर्पित  ॐ     //
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define nline "\n"

struct node
{
    ll sum, ans, pref, suff;
};

vector<node> t;
vector<int> lazy;
node makenode(int v, int tr, int tl, int val)
{
    node res;
    ll value = (tr - tl + 1) * 1ll * val;
    res.sum = value;
    if (val >= 0)
    {
        res.ans = res.pref = res.suff = value;
    }
    else
        res.ans = res.pref = res.suff = 0;
    return res;
}
void push(int v, int tl, int tr)
{
    if (lazy[v] != INT_MAX)
    {
        t[v] = makenode(v, tr, tl, lazy[v]);
        if (tl != tr)
        {
            lazy[v * 2] = lazy[v];
            lazy[v * 2 + 1] = lazy[v];
        }
        lazy[v] = INT_MAX;
    }
}
node combine(node l, node r)
{
    node res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
}
void update(int v, int tl, int tr, int l, int r, int val)
{
    push(v, tl, tr);
    if (tl > r || tr < l)
        return;
    if (tl >= l and tr <= r)
    {
        t[v] = makenode(v, tr, tl, val);
        if (tl != tr)
        {
            lazy[v * 2] = val;
            lazy[v * 2 + 1] = val;
        }
        return;
    }
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, r, val);
    update(v * 2 + 1, tm + 1, tr, l, r, val);
    t[v] = combine(t[v * 2], t[v * 2 + 1]);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/config.h"
    // #endif

    int n, m, l, r, v, tp;
    cin >> n >> m;
    t.resize(4 * n);
    lazy.resize(4 * n, INT_MAX);
    while (m--)
    {
        cin >> l >> r >> v;
        r--;
        update(1, 0, n - 1, l, r, v);
        cout << t[1].ans << nline;
    }

    return 0;
}