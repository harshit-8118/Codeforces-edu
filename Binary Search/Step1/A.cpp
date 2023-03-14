//     ॐ  भगवन् सब आपको समर्पित  ॐ     //
#include <bits/stdc++.h>
using namespace std;

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;

    while (k--)
    {
        int target;
        cin >> target;
        int s = 0, e = n - 1;
        int flag = 0;
        while (s <= e)
        {
            int m = (s + e) / 2;
            if (arr[m] == target)
            {
                cout << "YES" << endl;
                flag = 1;
                break;
            }
            if (arr[m] > target)
            {
                e = m - 1;
            }
            else
                s = m + 1;
        }
        if (!flag)
            cout << "NO" << endl;
    }
    return 0;
}