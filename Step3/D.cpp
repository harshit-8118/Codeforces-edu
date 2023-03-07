#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define nline "\n"
#define v32 vector<int>
#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define forf(i, s, e) for(int i = s; i < e; i++)
#define forb(i, e, s) for(int i = e; i >= s; i--)

// #ifndef ONLINE_JUDGE     //    
//  #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/debug.h"
// #else
// #define fix(x)
// #endif

class segmentTree{
  public: 
  vector<int> t; int n;
  segmentTree(int nn){
    this->n = nn;
    t.resize(4*nn, 0);
  }
  template<class T> T operation(T a, T b){ return a + b; } 
  template<class T>  void update(T v, T tl, T tr, T p, T val){
    if(tl == tr){
      t[v] = val; return;
    }T tm = (tl + tr)/2;
    if(tm >= p)    update(v*2, tl, tm, p, val);
    else    update(v*2+1, tm+1, tr, p, val);
    t[v] = operation(t[v*2], t[v*2+1]);
  }
  template<class T>  T get_query(T v, T tl, T tr, T l, T r){
    if(l > r)      return 0;
    if(tr <= r and tl >= l)      return t[v];
    T tm = (tl + tr)/2;
    return operation(get_query(v*2, tl, tm, l, min(tm, r)), get_query(v*2+1, tm+1, tr, max(l, tm+1), r));
  }
  template<class T> void update(T p, T val = 1){
    update(T(1), T(0), T(n-1), p, val);
  }
  template<class T> T get_query(T l, T r){
    return get_query(T(1), T(0), T(n-1), l, r);
  }
};

template<typename T>    istream& operator>>(istream& is, vector<T> &v){for (auto& i : v) is >> i;  return is;}
template<typename T>    ostream& operator<<(ostream& os, vector<T>  v){for (auto& i : v) os << i << ' ';   return os;}

int main(){

ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

// #ifndef ONLINE_JUDGE        
//   #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/config.h"
// #endif

int n, x; cin>>n;
v32 vis(n+1, -1), res(n+1);
segmentTree st(2*n);
forf(i, 0, 2*n){
    cin>>x;
    if(vis[x] == -1){
        vis[x] = i;
    }else{
        // fix(vis[x]); fix(i);
        int val = st.get_query(vis[x], i);
        st.update(vis[x]);
        // fix(st.t);
        res[x] = i - vis[x] + 1 - 2 - val* 2;
    }
}
forf(i, 1, n+1){
    cout<<res[i]<<" ";
}

return 0;
}