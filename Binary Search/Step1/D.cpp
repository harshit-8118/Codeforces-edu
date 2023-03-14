//     ॐ  भगवन् सब आपको समर्पित  ॐ     //
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, l, r;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;

    sort(all(arr));
    cin >> m;
    while (m--)
    {
        cin >> l >> r;
        auto it = lower_bound(all(arr), l);
        if (it != arr.end())
        {
            auto itr = upper_bound(all(arr), r);
            cout << itr - it << " ";
        }
        else
            cout << 0 << endl;
    }

    return 0;
}