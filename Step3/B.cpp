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


template<typename T>    vector<T>& operator++(vector<T> &v){for (auto& i : v) ++i;  return  v;} // prefix incrementor
template<typename T>    vector<T>& operator--(vector<T> &v){for (auto& i : v) --i;  return  v;} // prefix decrementor
template<typename T>    istream& operator>>(istream& is, vector<T> &v){for (auto& i : v) is >> i;  return is;}
template<typename T>    ostream& operator<<(ostream& os, vector<T>  v){for (auto& i : v) os << i << ' ';   return os;}

class segmentTree{
  public: 
  vector<int> t; int n;
  segmentTree(vector<int> &a){
    this->n = a.size(); t.resize(4*n);
    build(a, 1, 0, n-1);
  }
  template<class T> T operation(T a, T b){ return a + b; } 
  template<class T>  void build(vector<int> &arr, T v, T tl, T tr){
    if(tl == tr){
      t[v] = 1;
      return;
    }T tm = (tl + tr)/2;
    build(arr, v*2, tl, tm);     build(arr, v*2+1, tm+1, tr);
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
  template<class T>  T get_query(T v, T tl, T tr, T k){
    if(t[v] < k)      return -1;
    if(tl == tr)      return tl;
    int tm = (tl + tr)/2;
    if(t[v*2] >= k){
      return get_query(v*2, tl, tm, k);
    }else{
      return get_query(v*2+1, tm + 1, tr, k - t[v*2]);
    }
  }
  template<class T> void update(T p, T val){
    update(T(1), T(0), T(n-1), p, val);
  }
  template<class T> T get_query(T k){
    return get_query(T(1), T(0), T(n-1), k);
  }
};

int main(){

ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

// #ifndef ONLINE_JUDGE        
//  #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/config.h"
// #endif

int n; cin>>n;
vector<int> arr(n);
cin>>arr;
segmentTree st(arr);
v32 v(n);
fix(st.t);int cnt = n;
forb(i, n-1, 0){
  fix(cnt - arr[i]);
  int ind = st.get_query(cnt - arr[i]);
  fix(ind);
  st.update(ind, 0);
  fix(st.t);
  v[i] = ind+1;
  cnt--;
}
cout<<v<<endl;

return 0;
}