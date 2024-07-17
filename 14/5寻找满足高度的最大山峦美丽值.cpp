#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> hight;
    vector<int> bueaty;     
    for (int i = 0; i < n; ++i) {
        int h;  cin >> h;
        hight.push_back(h);
    }
    for (int i = 0; i < n; ++i) {
        int b;  cin >> b;
        bueaty.push_back(b);
    }
    vector<int> all_hight = hight;
    sort(all_hight.begin(), all_hight.end());
    all_hight.erase(unique(all_hight.begin(), all_hight.end()), all_hight.end());
    map<int, int> hight_to_idx;
    for (int i = 0; i < all_hight.size(); ++i)
        hight_to_idx[all_hight[i]] = i;
    for (int i = 0; i < n; ++i)
        hight[i] = hight_to_idx[hight[i]];
    vector<int> dp(all_hight.size() + 1);
    for (int i = 0; i < n; ++i)
        dp[hight[i]] = max(dp[hight[i]], bueaty[i]);
    for (int i = all_hight.size() - 1; i >= 0; --i)
        dp[i] = max(dp[i], dp[i + 1]);
    for (int i = 1; i <= q; ++i) {
        int k;  cin >> k;
        auto it = lower_bound(all_hight.begin(), all_hight.end(), k);
        if (it == all_hight.end())
            cout << -1 << endl;
        else
            cout << dp[distance(all_hight.begin(), it)] << endl;
    }
    return 0;

}
