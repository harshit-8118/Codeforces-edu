#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define nline "\n"

vector<ll> arr;
class segmentTree
{
public:
  vector<ll> t;
  segmentTree(ll n)
  {
    t.resize(4 * n);
    build(1ll, 0ll, n - 1);
  }
  template <class T>
  T operation(T a, T b) { return a + b; }
  template <class T>
  void build(T v, T tl, T tr)
  {
    if (tl == tr)
    {
      t[v] = arr[tl];
      return;
    }
    ll tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = operation(t[v * 2], t[v * 2 + 1]);
  }

  template <class T>
  void update(T v, T tl, T tr, T p, T val)
  {
    if (tl == tr)
    {
      t[v] = val;
      return;
    }
    T tm = (tl + tr) / 2;
    if (tm >= p)
      update(v * 2, tl, tm, p, val);
    else
      update(v * 2 + 1, tm + 1, tr, p, val);
    t[v] = operation(t[v * 2], t[v * 2 + 1]);
  }
  template <class T>
  long long int get_query(T v, T tl, T tr, T l, T r)
  {
    if (l > r)
      return 0;
    if (tr == r and tl == l)
      return t[v];
    T tm = (tl + tr) / 2;
    return operation(get_query(v * 2, tl, tm, l, min(tm, r)), get_query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
};

signed main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // #ifndef ONLINE_JUDGE
  // #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/config.h"
  // #endif

  ll n, q, l, r, ty, x;
  cin >> n >> q;
  arr = vector<ll>(n);
  for (auto &x : arr)
    cin >> x;
  segmentTree st(n);
  while (q--)
  {
    cin >> ty;
    if (ty == 1)
    {
      cin >> l >> x;
      st.update(1ll, 0ll, n - 1, l, x);
    }
    else
    {
      cin >> l >> r;
      r--;
      cout << st.get_query(1ll, 0ll, n - 1, l, r) << endl;
    }
  }

  return 0;
}