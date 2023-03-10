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
    T operation(T a, T b) { return a + b; }
    void push(int v, int tl, int tr)
    {
        if (lazy[v])
        {
            t[v] = tr - tl + 1 - t[v];
            if (tl != tr)
            {
                lazy[v * 2] = !lazy[v * 2];
                lazy[v * 2 + 1] = !lazy[v * 2 + 1];
            }
            lazy[v] = 0;
        }
    }
    template <class T>
    void update(T v, T tl, T tr, T l, T r)
    {
        push(v, tl, tr);
        if (tl > r || tr < l)
            return;
        if (tl >= l and tr <= r)
        {
            t[v] = tr - tl + 1 - t[v];
            if (tl != tr)
            {
                lazy[v * 2] = !lazy[v * 2];
                lazy[v * 2 + 1] = !lazy[v * 2 + 1];
            }
            return;
        }
        T tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, r);
        update(v * 2 + 1, tm + 1, tr, l, r);
        t[v] = operation(t[v * 2], t[v * 2 + 1]);
    }
    template <class T>
    T get_query(T v, T tl, T tr, T k)
    {
        push(v, tl, tr);
        if (tr == tl)
            return tl;
        T tm = (tl + tr) / 2;
        push(v * 2, tl, tm);
        push(v * 2 + 1, tm + 1, tr);
        if (t[v * 2] >= k)
        {
            return get_query(v * 2, tl, tm, k);
        }
        else
        {
            return get_query(v * 2 + 1, tm + 1, tr, k - t[v * 2]);
        }
    }
    template <class T>
    void update(T l, T r)
    {
        update(T(1), T(0), T(n - 1), l, r);
    }
    template <class T>
    T get_query(T k)
    {
        return get_query(T(1), T(0), T(n - 1), k);
    }
};

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/config.h"
    // #endif

    int n, m, l, r, tp, k;
    cin >> n >> m;
    segmentTree st(n);
    while (m--)
    {
        cin >> tp;
        if (tp == 1)
        {
            cin >> l >> r;
            r--;
            st.update(l, r);
        }
        else
        {
            cin >> k;
            k++;
            auto ans = st.get_query(k);
            cout << ans << "\n";
        }
    }

    return 0;
}