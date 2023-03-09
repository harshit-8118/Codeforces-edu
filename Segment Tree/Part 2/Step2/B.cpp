//     ॐ  भगवन् सब आपको समर्पित  ॐ     //
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define nline "\n"
#define v32 vector<int>

const int M = 1000000007;

int mod(long long int x) { return ((x % M + M) % M); }
int add(int a, int b) { return mod(mod(a) + mod(b)); }
int mul(int a, int b) { return mod(mod(a) * 1ll * mod(b)); }

class segmentTree
{
public:
  vector<ll> t, lazy;
  int n;
  segmentTree(v32 &a)
  {
    this->n = a.size();
    t.assign(4 * n, 0ll);
    lazy.assign(4 * n, 1ll);
    build(a, 1, 0, this->n - 1);
  }
  template <class T>
  T operation(T a, T b) { return add(a, b); }
  template <class T>
  void build(v32 &a, T v, T tl, T tr)
  {
    if (tl == tr)
    {
      t[v] = a[tl];
      return;
    }
    T tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);
    t[v] = operation(t[v * 2], t[v * 2 + 1]);
  }
  void push(int v, int tl, int tr)
  {
    if (lazy[v] != 1)
    {
      t[v] = mul(t[v], lazy[v]);
      if (tl != tr)
      {
        lazy[v * 2] = mul(lazy[v * 2], lazy[v]);
        lazy[v * 2 + 1] = mul(lazy[v * 2 + 1], lazy[v]);
      }
      lazy[v] = 1;
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
      t[v] = mul(t[v], val);
      if (tl != tr)
      {
        lazy[v * 2] = mul(lazy[v * 2], val);
        lazy[v * 2 + 1] = mul(lazy[v * 2 + 1], val);
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
      return 0;
    if (tr <= r and tl >= l)
      return t[v];
    T tm = (tl + tr) / 2;
    ll s1 = get_query(v * 2, tl, tm, l, r);
    ll s2 = get_query(v * 2 + 1, tm + 1, tr, l, r);
    return add(s1, s2);
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
  int n, m, tp, l, r, v;
  cin >> n >> m;
  v32 a(n, 1);
  segmentTree st(a);
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
      cin >> l >> r;
      auto ans = st.get_query(l, r - 1);
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