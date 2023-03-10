#include <bits/stdc++.h>
using namespace std;

#define forf(i, s, e) for (int i = s; i < e; i++)
#define forb(i, e, s) for (int i = e; i >= s; i--)

// #ifndef ONLINE_JUDGE
// #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/debug.h"
// #else
// #define fix(x)
// #endif

struct matrix
{
  int a, b, c, d;
};
class segmentTree
{
public:
  vector<matrix> t;
  int n, r;
  matrix mat;
  segmentTree(vector<matrix> &a, int r)
  {
    this->n = a.size();
    t.resize(4 * n);
    this->r = r;
    build(a, 1, 0, n - 1);
  }
  matrix mult(matrix a, matrix b, int m)
  {
    return {((a.a * b.a) % this->r + (a.b * b.c) % this->r) % this->r,
            ((a.a * b.b) % this->r + (a.b * b.d) % this->r) % this->r,
            ((a.c * b.a) % this->r + (a.d * b.c) % this->r) % this->r,
            ((a.c * b.b) % this->r + (a.d * b.d) % this->r) % this->r};
  }
  template <class T>
  void build(vector<matrix> &a, T v, T tl, T tr)
  {
    if (tl == tr)
    {
      t[v] = a[tl];
      return;
    }
    T tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);
    t[v] = mult(t[v * 2], t[v * 2 + 1], this->r);
  }
  template <class T>
  matrix get_query(T v, T tl, T tr, T l, T r)
  {
    if (tl > r || tr < l)
      return {1, 0, 0, 1};
    if (tr <= r and tl >= l)
      return t[v];
    T tm = (tl + tr) / 2;
    return mult(get_query(v * 2, tl, tm, l, r), get_query(v * 2 + 1, tm + 1, tr, l, r), this->r);
  }
  template <class T>
  matrix get_query(T l, T r)
  {
    return get_query(T(1), T(0), T(n - 1), l, r);
  }
};

int r, n, m;
void solve()
{
  cin >> r >> n >> m;
  vector<matrix> mats(n);
  int a, b, c, d, x, y;
  forf(i, 1, n + 1)
  {
    cin >> mats[i - 1].a;
    cin >> mats[i - 1].b;
    cin >> mats[i - 1].c;
    cin >> mats[i - 1].d;
  }
  segmentTree st(mats, r);
  // fix(st.t);
  // fix(mats);
  while (m--)
  {
    cin >> x >> y;
    --x;
    --y;
    // fix(x);
    // fix(y);
    auto ans = st.get_query(x, y);
    printf("%d %d\n%d %d\n\n", ans.a, ans.b, ans.c, ans.d);
  }
}

int32_t main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // #ifndef ONLINE_JUDGE
  //   #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/config.h"
  // #endif

  int tt = 1;
  // cin>>tt;
  while (tt--)
  {
    solve();
  }

  return 0;
}