#include <bits/stdc++.h>
#define space ' '
#define endl '\n'
#define int long long
#define unmap unordered_map
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
const int mxsz = 50 + 5;
int pw[mxsz];
unmap<int, unmap<int, int>> dis = {
    {0, {{0, 0}, {1, 5}, {2, 6}}},
    {1, {{0, 1}, {1, 4}, {2, 7}}},
    {2, {{0, 2}, {1, 3}, {2, 8}}}
};
int getdis(int x, int y) {
    int res = 0, k = 1;
    pw[0] = 1;
    rep (i, 1, 39) pw[i] = pw[i - 1] * 3;
    while (pw[k] - 1 < x or pw[k] - 1 < y) k++;
    for (int i = k - 1; i >= 0; i--) {
        int pow3 = pw[i]; 
        int px = x / pow3, py = y / pow3;
        res += dis[px][py] * pow3 * pow3;
        x %= pow3, y %= pow3;
        if(py == 1) x = pow3 - 1 - x;
        if(px == 1) y = pow3 - 1 - y;
    }
    return res;
}
signed main() {
    int k, x1, y1, x2, y2;
    cin >> k >> x1 >> y1 >> x2 >> y2;
    cout << abs(getdis(y2, x2) - getdis(y1, x1)) << endl;    
    return 0;
}
