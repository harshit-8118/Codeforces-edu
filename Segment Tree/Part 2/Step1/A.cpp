//     ॐ  भगवन् सब आपको समर्पित  ॐ     //
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define nline "\n"
#define v32 vector<int>
#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define forf(i, s, e) for (int i = s; i < e; i++)
#define forb(i, e, s) for (int i = e; i >= s; i--)

class segmentTree
{
public:
    vector<ll> t, lazy;
    ll n;
    segmentTree(ll n)
    {
        this->n = n;
        t.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }
    void push(int v, int tl, int tr)
    {
        if (lazy[v] != 0)
        {
            t[v] += (tr - tl + 1) * lazy[v];
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
        if (tr < l || tl > r)
        {
            return;
        }
        push(v, tl, tr);
        if (tl >= l and tr <= r)
        {
            t[v] += (tr - tl + 1) * val;
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
    }
    template <class T>
    T get_query(T v, T tl, T tr, T i)
    {
        if (tl > tr)
            return 0;
        push(v, tl, tr);
        if (tl == tr)
            return t[v];
        T tm = (tl + tr) / 2;
        if (i <= tm)
        {
            return get_query(v * 2, tl, tm, i);
        }
        else
            return get_query(v * 2 + 1, tm + 1, tr, i);
    }
    template <class T>
    void update(T l, T r, T val)
    {
        update(T(1), T(0), T(n - 1), l, r, val);
    }
    template <class T>
    T get_query(T i)
    {
        return get_query(T(1), T(0), T(n - 1), i);
    }
};

void Solution()
{
    ll n, m, tp, l, r, v;
    cin >> n >> m;
    segmentTree st(n);
    while (m--)
    {
        cin >> tp;
        if (tp == 1)
        {
            cin >> l >> r >> v;
            r--;
            st.update(l, r, v);
        }
        else
        {
            cin >> r;
            ll ans = st.get_query(r);
            cout << ans << nline;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/config.h"
    // #endif

    int tt = 1;
    while (tt--)
    {
        Solution();
    }

    return 0;
}