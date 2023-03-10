#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define nline "\n"
#define v32 vector<int>
#define forf(i, s, e) for (int i = s; i < e; i++)

template <typename T>
istream &operator>>(istream &is, vector<T> &v){  for (auto &i : v)    is >> i;  return is;}
template <typename T>
ostream &operator<<(ostream &os, vector<T> v){  for (auto &i : v)    os << i << ' ';  return os;}

class segmentTree
{
public:
  using pp = pair<set<int>, int>;
  vector<pp> t;
  int n;
  segmentTree(vector<int> &a)
  {
    this->n = a.size();
    t.resize(4 * n);
    build(a, 1, 0, n - 1);
  }
  pp operation(pp a, pp b, int tl, int tr)
  {
    pp res;
    res.first = a.first;
    for (auto &x : b.first)
      res.first.insert(x);
    res.second = tr - tl + 1 - res.first.size();
    return res;
  }
  pp make_data(int n)
  {
    pp res;
    if (n == -1)
    {
      res.first.clear();
      res.second = 0;
      return res;
    }
    res.first.insert(n);
    res.second = 0;
    return res;
  }
  template <class T>
  void build(vector<int> &a, T v, T tl, T tr)
  {
    if (tl == tr)
    {
      t[v] = make_data(a[tl]);
      return;
    }
    T tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);
    t[v] = operation(t[v * 2], t[v * 2 + 1], tl, tr);
  }
  pp get_query(int v, int tl, int tr, int l, int r)
  {
    if (l > tr || r < tl)
      return make_data(-1);
    if (tr <= r and tl >= l)
      return t[v];
    int tm = (tl + tr) / 2;
    pp res1 = get_query(v * 2, tl, tm, l, min(tm, r));
    pp res2 = get_query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    pp res = operation(res1, res2, l, r);
    return res;
  }
  template <class T>
  pp get_query(T l, T r)
  {
    return get_query(T(1), T(0), T(n - 1), l, r);
  }
};

// Read the problem carefully ****
void Solution()
{
  int n, l, r, q, x;
  cin >> n;
  vector<v32> v(n + 1);
  v32 arr(2 * n);
  cin >> arr;
  int i = 0;
  segmentTree st(arr);
  for (auto &x : arr)
  {
    v[x].push_back(i);
    i++;
  }
  forf(i, 1, n + 1)
  {
    l = v[i][0];
    r = v[i][1];
    cout << st.get_query(l, r).second - 1 << " \n"[i == n];
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // #ifndef ONLINE_JUDGE     //
  //     #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/config.h"
  // #endif

  int tt = 1;
  //   cin>>tt;
  while (tt--)
  {
    Solution();
  }

  return 0;
}