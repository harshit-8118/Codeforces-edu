#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define nline "\n"
#define v32 vector<int>
#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define forf(i, s, e) for(int i = s; i < e; i++)
#define forb(i, e, s) for(int i = e; i >= s; i--)

// #ifndef ONLINE_JUDGE         
//     #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/debug.h"
// #else
//     #define fix(x)
// #endif


v32 arr;
class segmentTree{
  public: 
  vector<v32> t;
  segmentTree(int n){
    t.resize(4*n);
  }
  template<class T> T operation(T a, T b){ return a + b; } 
  template<class T>  void build(T v, T tl, T tr){
    if(tl == tr){
      t[v] = vector<int> (1, arr[tl]);
      return;
    }T tm = (tl + tr)/2;
    build(v*2, tl, tm);     build(v*2+1, tm+1, tr);
    merge(t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(), back_inserter(t[v]));
  }
  template<class T>  T get_query(T v, T tl, T tr, T l, T r, int val){
    if(tr < l || tl > r) return 0;
    if(tr <= r and tl >= l) {
        auto it = upper_bound(t[v].begin(), t[v].end(), val);
        return t[v].end() - it;
    };
    T tm = (tl + tr)/2;
    return operation(get_query(v*2, tl, tm, l, r, val), get_query(v*2+1, tm+1, tr, l, r, val));
  }
};

int main(){
ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

// #ifndef ONLINE_JUDGE        
//     #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/config.h"
// #endif

int n, m, l, r, i, v, tp, q; 
cin>>n;
arr = v32(n);
segmentTree st(n);
for(auto &x: arr) cin>>x;
st.build(1, 0, n-1);
// fix(st.t);
cout<<0<<" ";
forf(i, 1, n){
    cout<<st.get_query(1, 0, n-1, 0, i, arr[i])<<" ";
}

return 0;
}