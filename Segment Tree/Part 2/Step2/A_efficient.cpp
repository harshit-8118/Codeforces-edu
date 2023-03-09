//     ॐ  भगवन् सब आपको समर्पित  ॐ     //
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define nline "\n"

const int N = 3e5;
ll t[N], lazy[N];

void update(ll v, ll tl, ll tr, ll l, ll r, ll val)
{
  if (tl > r || tr < l)
    return;
  if (tl >= l and tr <= r)
  {
    lazy[v] += val;
    t[v] += val;
    return;
  }
  ll tm = (tl + tr) / 2;
  update(v * 2, tl, tm, l, r, val);
  update(v * 2 + 1, tm + 1, tr, l, r, val);
  t[v] = min(t[v * 2], t[v * 2 + 1]) + lazy[v];
}

ll get_query(ll v, ll tl, ll tr, ll l, ll r)
{
  if (tl > r || tr < l)
    return INT_MAX;
  if (tl >= l and tr <= r)
    return t[v];
  ll tm = (tl + tr) / 2;
  ll s1 = get_query(v * 2, tl, tm, l, r);
  ll s2 = get_query(v * 2 + 1, tm + 1, tr, l, r);
  return min(s1, s2) + lazy[v];
}

int32_t main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

// #ifndef ONLINE_JUDGE
// #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/config.h"
// #endif

  ll n, m, l, r, v;
  cin >> n >> m;
  while (m--)
  {
    ll x;
    cin >> x;
    if (x == 1)
    {
      cin >> l >> r >> v;
      r--;
      update(1, 0, n - 1, l, r, v);
    }
    else
    {
      cin >> l >> r;
      r--;
      cout << get_query(1, 0, n - 1, l, r) << nline;
    }
  }

  return 0;
}