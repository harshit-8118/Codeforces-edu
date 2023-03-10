#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define nline "\n"

// #ifndef ONLINE_JUDGE     //
// #include "C://Users//hhars//OneDrive//Documents//CPP_Practice//Algo//debug.h"
// #else
// #define fix(x)
// #endif

vector<ll> arr, pref, suff, ans, sum;
void build(int i, int tl, int tr)
{
    if (tl == tr)
    {
        suff[i] = ans[i] = pref[i] = max(0ll, arr[tl]);
        sum[i] = arr[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(i * 2, tl, tm);
        build(i * 2 + 1, tm + 1, tr);
        ans[i] = max(ans[i * 2], max(ans[i * 2 + 1], suff[i * 2] + pref[i * 2 + 1]));
        pref[i] = max(pref[i * 2], sum[i * 2] + pref[i * 2 + 1]);
        suff[i] = max(suff[i * 2 + 1], sum[i * 2 + 1] + suff[i * 2]);
        sum[i] = sum[i * 2] + sum[i * 2 + 1];
    }
}

void update(int i, int tl, int tr, int p)
{
    if (tl == tr)
    {
        suff[i] = ans[i] = pref[i] = max(0ll, arr[tl]);
        sum[i] = arr[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (tm >= p)
            update(i * 2, tl, tm, p);
        else
            update(i * 2 + 1, tm + 1, tr, p);
        ans[i] = max(ans[i * 2], max(ans[i * 2 + 1], suff[i * 2] + pref[i * 2 + 1]));
        pref[i] = max(pref[i * 2], sum[i * 2] + pref[i * 2 + 1]);
        suff[i] = max(suff[i * 2 + 1], sum[i * 2 + 1] + suff[i * 2]);
        sum[i] = sum[i * 2] + sum[i * 2 + 1];
    }
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    arr = vector<ll>(n);
    pref = sum = ans = suff = vector<ll>(n * 4);
    for (auto &x : arr)
        cin >> x;
    build(1ll, 0ll, n - 1);
    cout << ans[1] << nline;
    ll x;
    ll y;
    while (m--)
    {
        cin >> x >> y;
        arr[x] = y;
        update(1ll, 0ll, n - 1, x);
        cout << ans[1] << nline;
    }
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // #include "C:/Users/hhars/OneDrive/Documents/CPP_Practice/Algo/config.h"
    // #endif

    int tt = 1;
    solve();
    return 0;
}