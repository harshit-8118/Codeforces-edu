#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define nline "\n"
#define v32 vector<int>
#define pb emplace_back
#define mpr make_pair
#define all(x) (x).begin(), (x).end()
#define forf(i, s, e) for (int i = s; i < e; i++)
#define forb(i, e, s) for (int i = e; i >= s; i--)

template<typename T>    istream& operator>>(istream& is, vector<T> &v){for (auto& i : v) is >> i;  return is;}
template<typename T>    ostream& operator<<(ostream& os, vector<T>  v){for (auto& i : v) os << i << ' ';   return os;}

// #ifndef ONLINE_JUDGE
// #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/debug.h"
// #else
// #define fix(x)
// #endif

class segmentTree
{
public:
  using pp = pair<int, int>;
  vector<pp> t;
  int n;
  segmentTree(vector<int> &a)
  {
    this->n = a.size();
    t.resize(4 * n);
    build(a, 1, 0, n - 1);
  }
  pp operation(pp a, pp b)
  {
    pp res;
    if (a.second % 2 != 0)
    {
      res.second = a.second + b.second;
      res.first = a.first - b.first;
      return res;
    }
    else
    {
      res.second = a.second + b.second;
      res.first = a.first + b.first;
      return res;
    }
  }
  template <class T>
  void build(vector<int> &a, T v, T tl, T tr)
  {
    if (tl == tr)
    {
      t[v] = mpr(a[tl], 1);
      return;
    }
    T tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);
    t[v] = operation(t[v * 2], t[v * 2 + 1]);
  }
  template <class T>
  void update(T v, T tl, T tr, T p, T val)
  {
    if (tl == tr)
    {
      t[v] = mpr(val, 1);
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
  pp get_query(T v, T tl, T tr, T l, T r)
  {
    if (tl > r || tr < l)
      return mpr(0, 0);
    if (tr <= r and tl >= l)
      return t[v];
    T tm = (tl + tr) / 2;
    return operation(get_query(v * 2, tl, tm, l, r), get_query(v * 2 + 1, tm + 1, tr, l, r));
  }
  template <class T>
  void update(T p, T val)
  {
    update(T(1), T(0), T(n - 1), p, val);
  }
  template <class T>
  pp get_query(T l, T r)
  {
    return get_query(T(1), T(0), T(n - 1), l, r);
  }
};

int32_t main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // #ifndef ONLINE_JUDGE     //
  //   #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/config.h"
  // #endif

  int n;
  cin >> n;
  v32 arr(n);
  cin >> arr;
  segmentTree st(arr);
  int q, l, r, i, j, t;
  cin >> q;
  // fix(st.t);
  while (q--)
  {
    cin >> t;
    if (t)
    {
      cin >> l >> r;
      l--;
      r--;
      auto val = st.get_query(l, r);
      cout << val.first << nline;
    }
    else
    {
      cin >> i >> j;
      i--;
      st.update(i, j);
      // fix(st.t)
    }
  }

  return 0;
}