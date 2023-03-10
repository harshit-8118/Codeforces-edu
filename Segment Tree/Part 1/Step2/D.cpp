// Harshit-8118
#include <bits/stdc++.h>
using namespace std;

// #ifndef ONLINE_JUDGE     //
// #include "C://Users//hhars//OneDrive//Documents//CPP_Practice//Algo/debug.h"
// #else
// #define fix(x)
// #endif

vector<int> arr, t;
void build(int i, int tl, int tr)
{
  if (tl == tr)
  {
    t[i] = arr[tl];
  }
  else
  {
    int tm = (tl + tr) / 2;
    build(i * 2, tl, tm);
    build(i * 2 + 1, tm + 1, tr);
    t[i] = max(t[i * 2], t[i * 2 + 1]);
  }
}

void update(int i, int tl, int tr, int p, int val)
{
  if (tl == tr)
  {
    t[i] = val;
    return;
  }
  int tm = (tr + tl) / 2;
  if (tm >= p)
  {
    update(i * 2, tl, tm, p, val);
  }
  else
    update(i * 2 + 1, tm + 1, tr, p, val);
  t[i] = max(t[i * 2], t[i * 2 + 1]);
}

int query(int i, int tl, int tr, int l, int x)
{
  if (t[i] < x)
  {
    return -1e9;
  }
  if (tl == tr)
  {
    return tl;
  }
  int tm = (tl + tr) / 2;
  if (t[i * 2] >= x and tm >= l)
  {
    int ans = query(i * 2, tl, tm, l, x);
    if (ans == -1e9)
    {
      return query(i * 2 + 1, tm + 1, tr, l, x);
    }
    return ans;
  }
  else
  {
    return query(i * 2 + 1, tm + 1, tr, l, x);
  }
}

// Read the problem carefully ****
void Solution()
{
  int n, m;
  cin >> n >> m;
  arr = vector<int>(n);
  t = vector<int>(4 * n);
  for (auto &x : arr)
  {
    cin >> x;
  }
  build(1, 0, n - 1);
  // fix(t);
  while (m--)
  {
    int type;
    cin >> type;
    if (type == 1)
    {
      int pos, nval;
      cin >> pos >> nval;
      update(1, 0, n - 1, pos, nval);
    }
    else
    {
      int x, l;
      cin >> x >> l;
      int ans = query(1, 0, n - 1, l, x);
      if (ans == -1e9)
      {
        cout << -1 << endl;
      }
      else
        cout << ans << endl;
    }
  }
}

int main()
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
    Solution();
  }

  return 0;
}