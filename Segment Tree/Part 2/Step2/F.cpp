//     ॐ  भगवन् सब आपको समर्पित  ॐ     //
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class segmentTree
{
public:
  vector<ll> t, lazy;
  int n;
  segmentTree(int n)
  {
    this->n = n;
    t.assign(4 * n, 0ll);
    lazy.assign(4 * n, -1ll);
  }
  template <class T>
  T operation(T a, T b) { return a + b; }
  void push(int v, int tl, int tr)
  {
    if (lazy[v] != -1)
    {
      t[v] = (tr - tl + 1) * lazy[v];
      if (tl != tr)
      {
        lazy[v * 2] = lazy[v];
        lazy[v * 2 + 1] = lazy[v];
      }
      lazy[v] = -1;
    }
  }
  template <class T>
  void update(T v, T tl, T tr, T l, T r, T val)
  {
    push(v, tl, tr);
    if (tr < l || tl > r)
      return;
    if (tl >= l and tr <= r)
    {
      t[v] = (tr - tl + 1) * 1ll * val;
      if (tl != tr)
      {
        lazy[v * 2] = 1ll * val;
        lazy[v * 2 + 1] = 1ll * val;
      }
      return;
    }
    T tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, r, val);
    update(v * 2 + 1, tm + 1, tr, l, r, val);
    t[v] = operation(t[v * 2], t[v * 2 + 1]);
  }
  template <class T>
  ll get_query(T v, T tl, T tr, T l, T r)
  {
    push(v, tl, tr);
    if (tr < l || tl > r)
      return 0ll;
    if (tl >= l and tr <= r)
    {
      return t[v];
    }
    T tm = (tl + tr) / 2;
    return operation(get_query(v * 2, tl, tm, l, r), get_query(v * 2 + 1, tm + 1, tr, l, r));
  }
  template <class T>
  void update(T l, T r, T val)
  {
    update(T(1), T(0), T(n - 1), l, r, val);
  }
  template <class T>
  ll get_query(T l, T r)
  {
    return get_query(T(1), T(0), T(n - 1), l, r);
  }
};

void Solution()
{
  int n, m, l, r, tp, v;
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
      cin >> l >> r;
      r--;
      auto ans = st.get_query(l, r);
      cout << ans << "\n";
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