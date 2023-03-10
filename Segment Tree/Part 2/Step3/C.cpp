//     ॐ  भगवन् सब आपको समर्पित  ॐ     //
#include <bits/stdc++.h>
using namespace std;

class segmentTree
{
public:
    vector<int> t, lazy;
    int n;
    segmentTree(int n)
    {
        this->n = n;
        t.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }
    template <class T>
    T operation(T a, T b) { return max(a, b); }
    void push(int v, int tl, int tr)
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
                lazy[v * 2] += val;
                lazy[v * 2 + 1] += val;
            }
            return;
        }
        T tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, r, val);
        update(v * 2 + 1, tm + 1, tr, l, r, val);
        t[v] = operation(t[v * 2], t[v * 2 + 1]);
    }
    template <class T>
    T get_query(T v, T tl, T tr, T x, T l)
    {
        push(v, tl, tr);
        if (t[v] < x)
            return -1;
        if (tr == tl)
            return tl;
        T tm = (tl + tr) / 2;
        if (tm >= l)
        {
            int s1 = get_query(v * 2, tl, tm, x, l);
            if (s1 == -1)
            {
                int s2 = get_query(v * 2 + 1, tm + 1, tr, x, l);
                return s2;
            }
            return s1;
        }
        else
        {
            return get_query(v * 2 + 1, tm + 1, tr, x, l);
        }
    }
    template <class T>
    void update(T l, T r, T val)
    {
        update(T(1), T(0), T(n - 1), l, r, val);
    }
    template <class T>
    T get_query(T x, T l)
    {
        return get_query(T(1), T(0), T(n - 1), x, l);
    }
};

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE //     #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/config.h"
    // #include "Algo/config.h"
    // #endif

    int n, m, l, r, x, tp, v;
    cin >> n >> m;
    segmentTree st(n);
    while (m--)
    {
        cin >> tp;
        if (tp == 1)
        {
            cin >> l >> r >> v;
            st.update(l, r - 1, v);
        }
        else
        {
            cin >> x >> l;
            int ans = st.get_query(x, l);
            cout << ans << "\n";
        }
    }

    return 0;
}