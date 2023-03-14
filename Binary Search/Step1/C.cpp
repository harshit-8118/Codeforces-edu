//     ॐ  भगवन् सब आपको समर्पित  ॐ     //
#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;

    int s, q, e, ans;
    while (m--)
    {
        s = 0; e = n - 1;
        cin >> q;
        ans = n;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (arr[mid] >= q)
            {
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        cout << ans + 1 << endl;
    }

    return 0;
}