#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define nline "\n"
#define v64 vector<ll>
#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define forf(i, s, e) for(int i = s; i < e; i++)
#define forb(i, e, s) for(int i = e; i >= s; i--)

template<typename T>    istream& operator>>(istream& is, vector<T> &v){for (auto& i : v) is >> i;  return is;}
template<typename T>    ostream& operator<<(ostream& os, vector<T>  v){for (auto& i : v) os << i << ' ';   return os;}

struct item{
  vector<ll> v;
  ll cnt;
  item(){
    v.assign(41, 0);
  }
  item(int n):item(){
    v[n]++; cnt = 1;
  }
};

class segmentTree{
  public: 
  vector<item> t; ll n;
  segmentTree(vector<ll> &a){
    this->n = a.size(); t.resize(4*n);
    build(a, 1ll, 0ll, n-1);
  }
  template<class T> item operation(T a, T b){ 
    item res; res.cnt = 0;
    forf(i, 1, 41){
      res.v[i] = a.v[i] + b.v[i];
      if(res.v[i] != 0){
        res.cnt++;
      }
    }
    return res;
  } 
  template<class T>  void build(vector<ll> &a, T v, T tl, T tr){
    if(tl == tr){
      t[v] = item(a[tl]);
      return;
    }T tm = (tl + tr)/2;
    build(a, v*2, tl, tm);     build(a, v*2+1, tm+1, tr);
    t[v] = operation(t[v*2], t[v*2+1]);
  }
  template<class T>  void update(T v, T tl, T tr, T p, T val){
    if(tl == tr){
      t[v] = item(val); return;
    }T tm = (tl + tr)/2;
    if(tm >= p)    update(v*2, tl, tm, p, val);
    else    update(v*2+1, tm+1, tr, p, val);
    t[v] = operation(t[v*2], t[v*2+1]);
  }
  template<class T>  item get_query(T v, T tl, T tr, T l, T r){
    if(tl > r || tr < l)      return item(0);
    if(tr <= r and tl >= l)      return t[v];
    T tm = (tl + tr)/2;
    return operation(get_query(v*2, tl, tm, l, r), get_query(v*2+1, tm+1, tr, l, r));
  }
  template<class T> void update(T p, T val){
    update(T(1), T(0), T(n-1), p, val);
  }
  template<class T> item get_query(T l, T r){
    return get_query(T(1), T(0), T(n-1), l, r);
  }
};

int32_t main(){

ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

// #ifndef ONLINE_JUDGE         
//  #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/config.h"
// #endif

ll n, q; cin>>n>>q;
v64 v(n);
cin>>v;

segmentTree st(v);

ll x, y, tp, l, r;
while(q--){
  cin>>tp;
  if(tp == 1){
    cin>>x>>y; x--; y--;
    auto ans = st.get_query(x, y);
    cout<<ans.cnt<<nline;
  }else{ 
    cin>>x>>y; --x;
    st.update(x, y);
  }
}

return 0;
}