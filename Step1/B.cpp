#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define nline "\n"
#define v32 vector<int>
#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define forf(i, s, e) for(int i = s; i < e; i++)
#define forb(i, e, s) for(int i = e; i >= s; i--)

v32 arr;
class segmentTree{
  public: 
  vector<int> t;
  segmentTree(int n){
    t.resize(4*n);
  }
  template<class T> T operation(T a, T b){ return min(a, b); } 
  template<class T>  void build(T v, T tl, T tr){
    if(tl == tr){
      t[v] = arr[tl];
      return;
    }T tm = (tl + tr)/2;
    build(v*2, tl, tm);     build(v*2+1, tm+1, tr);
    t[v] = operation(t[v*2], t[v*2+1]);
  }
  template<class T>  void update(T v, T tl, T tr, T p, T val){
    if(tl == tr){
      t[v] = val; return;
    }T tm = (tl + tr)/2;
    if(tm >= p)    update(v*2, tl, tm, p, val);
    else    update(v*2+1, tm+1, tr, p, val);
    t[v] = operation(t[v*2], t[v*2+1]);
  }
  template<class T>  T get_query(T v, T tl, T tr, T l, T r){
    if(l > r)      return INT_MAX;
    if(tr == r and tl == l)      return t[v];
    T tm = (tl + tr)/2;
    return operation(get_query(v*2, tl, tm, l, min(tm, r)), get_query(v*2+1, tm+1, tr, max(l, tm+1), r));
  }
};

int main(){
ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

// #ifndef ONLINE_JUDGE          
// #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/config.h"
// #endif

int n, m, l, r, i, v, tp, q; cin>>n>>m;
arr = v32(n);
segmentTree st(n);
for(auto &x: arr) cin>>x;
st.build(1, 0, n-1);
fix(st.t);
while(m--){
    cin>>tp;
    if(tp == 1){
        cin>>i>>v;
        st.update(1, 0, n-1, i, v);
        fix(st.t);
    }else{
        cin>>l>>r;
        r--;
        cout<<st.get_query(1, 0, n-1, l, r)<<nline;
    }
}

return 0;
}