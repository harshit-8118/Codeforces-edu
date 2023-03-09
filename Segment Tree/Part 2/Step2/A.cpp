//     ॐ  भगवन् सब आपको समर्पित  ॐ     //
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define nline "\n"

class segmentTree
{
public:
    vector<ll> t, lazy;
    int n;
    segmentTree(ll n)
    {
        this->n = n;
        t.assign(4 * n, 0ll);
        lazy.assign(4 * n, 0ll);
    }
    template <class T>
    T operation(T a, T b) { return min(a, b); }
    void push(ll v, ll tl, ll tr)
    {
        if (lazy[v] != 0)
        {
            t[v] += lazy[v];
            if (tl != tr)
            {
                lazy[v * 2] += lazy[v];
                lazy[v * 2 + 1] += lazy[v];
            }
            lazy[v] = 0;
        }
    }
    template <class T>
    void update(T v, T tl, T tr, T l, T r, T val)
    {
        push(v, tl, tr);
        if (tl > r || tr < l)
            return;
        if (tl >= l and tr <= r)
        {
            t[v] += val;
            if (tl != tr)
            {
                lazy[2 * v] += val;
                lazy[2 * v + 1] += val;
            }
            return;
        }
        T tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, r, val);
        update(v * 2 + 1, tm + 1, tr, l, r, val);
        t[v] = operation(t[v * 2], t[v * 2 + 1]);
    }
    template <class T>
    T get_query(T v, T tl, T tr, T l, T r)
    {
        push(v, tl, tr);
        if (tl > r || tr < l)
            return INT_MAX;
        if (tr <= r and tl >= l)
            return t[v];
        T tm = (tl + tr) / 2;
        ll m1 = get_query(v * 2, tl, tm, l, r);
        ll m2 = get_query(v * 2 + 1, tm + 1, tr, l, r);
        return min(m1, m2);
    }
    template <class T>
    void update(T l, T r, T val)
    {
        update(T(1), T(0), T(n - 1), l, r, val);
    }
    template <class T>
    T get_query(T l, T r)
    {
        return get_query(T(1), T(0), T(n - 1), l, r);
    }
};

void Solution()
{
    ll n, m, l, r, x, val;
    cin >> n >> m;
    segmentTree st(n);
    while (m--)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> l >> r >> val;
            st.update(l, r - 1, val);
        }
        else
        {
            cin >> l >> r;
            ll ans = st.get_query(l, r - 1);
            cout << ans << nline;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE    
        #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/config.h"
    #endif

    int tt = 1;
    while (tt--)
    {
        Solution();
    }

    return 0;
}