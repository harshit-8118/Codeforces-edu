#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define nline "\n"

vector<ll> arr, minn, freq;
void build(int i, int tl, int tr)
{
    if (tl == tr)
    {
        minn[i] = arr[tl];
        freq[i] = 1;
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(i * 2, tl, tm);
        build(i * 2 + 1, tm + 1, tr);
        minn[i] = min(minn[i * 2 + 1], minn[i * 2]);
        if (minn[i * 2] == minn[i * 2 + 1])
        {
            freq[i] = freq[i * 2] + freq[i * 2 + 1];
        }
        else if (minn[i * 2] < minn[i * 2 + 1])
        {
            freq[i] = freq[i * 2];
        }
        else
            freq[i] = freq[i * 2 + 1];
    }
}

void update(int i, int tl, int tr, int p)
{
    if (tl == tr)
    {
        minn[i] = arr[tl];
        freq[i] = 1;
    }
    else
    {
        int tm = (tl + tr) / 2;
        if (tm >= p)
            update(i * 2, tl, tm, p);
        else
            update(i * 2 + 1, tm + 1, tr, p);
        minn[i] = min(minn[i * 2 + 1], minn[i * 2]);
        if (minn[i * 2] == minn[i * 2 + 1])
        {
            freq[i] = freq[i * 2] + freq[i * 2 + 1];
        }
        else if (minn[i * 2] < minn[i * 2 + 1])
        {
            freq[i] = freq[i * 2];
        }
        else
            freq[i] = freq[i * 2 + 1];
    }
}

pair<int, int> getq(int i, int tl, int tr, int l, int r)
{
    if (l > r)
        return make_pair(1e9, 0);
    if (tl >= l and tr <= r)
    {
        return make_pair(minn[i], freq[i]);
    }
    int tm = (tl + tr) / 2;
    auto x = getq(i * 2, tl, tm, l, min(r, tm));
    auto y = getq(i * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    if (x.first == y.first)
    {
        return make_pair(x.first, x.second + y.second);
    }
    else if (x.first < y.first)
    {
        return x;
    }
    else
        return y;
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    arr = vector<ll>(n);
    minn = freq = vector<ll>(n * 4);
    for (auto &x : arr)
        cin >> x;
    build(1ll, 0ll, n - 1);
    ll t, i, v, l, r;
    while (m--)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> i >> v;
            arr[i] = v;
            update(1ll, 0ll, n - 1, i);
        }
        else
        {
            cin >> l >> r;
            r--;
            auto val = getq(1ll, 0ll, n - 1, l, r);
            cout << val.first << " " << val.second << endl;
        }
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