#include <bits/stdc++.h> 
using namespace std;

#define ll long long int
#define nline "\n"
#define v32 vector<int>
#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define forf(i, s, e) for(int i = s; i < e; i++)
#define forb(i, e, s) for(int i = e; i >= s; i--)

class segmentTree{
  public: 
  vector<int> t; int n;
  segmentTree(int n){
    this->n = n; t.resize(4*n, INT_MAX);
  }
  template<class T> T operation(T a, T b){ return min(a, b); } 
  template<class T>  void update(T v, T tl, T tr, T p, T val){
    if(tl > tr) return;
    if(tl == tr){
      t[v] = val; return;
    }T tm = (tl + tr)/2;
    if(tm >= p)    update(v*2, tl, tm, p, val);
    else    update(v*2+1, tm+1, tr, p, val);
    t[v] = min(t[v*2], t[v*2+1]);
  }
  template<class T>  T get_query(T v, T tl, T tr, T l, T r, int p){
    if(tl > r || tr < l)      return 0;
    if(t[v] > p)      return 0; 
    if(tl == tr) { t[v] = INT_MAX;     return 1;}
    T tm = (tl + tr)/2;
    int s1 = get_query(v*2, tl, tm, l, r, p);
    int s2 = get_query(v*2+1, tm+1, tr, l, r, p);
    t[v] = min(t[v*2], t[v*2 + 1]);
    return s1 + s2;
  }
  template<class T> void update(T p, T val){
    update(T(1), T(0), T(n-1), p, val);
  }
  template<class T> T get_query(T l, T r, int p){
    return get_query(T(1), T(0), T(n-1), l, r, p);
  }
};

void Solution(){
  int n, m, a, b, c, k;
  cin>>n>>m;
  segmentTree st(n);
  int l, r, p, i, h;
  while(m--){
    int tp; cin>>tp;
    if(tp == 1){
      cin>>i>>h;
      st.update(i, h);
    }else{
      cin>>l>>r>>p; r--;
      auto ans = st.get_query(l, r, p);
      cout<<ans<<endl;
    }
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);

  // #ifndef ONLINE_JUDGE        
  //   #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/config.h"
  // #endif

  int tt = 1;
  while(tt--){
    Solution();
  }

  return 0;
}