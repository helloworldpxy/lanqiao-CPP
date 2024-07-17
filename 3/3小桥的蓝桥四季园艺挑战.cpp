#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T; cin >> T;
    int a[5], s[11], temp;
    while (T--) {
        int ans = 0; temp = 0; memset(s, 0, sizeof s);
        for (int i = 1; i <= 4; ++i) {
            cin >> a[i]; s[a[i]]++;
            temp = max(temp, s[a[i]]);
        }
        if (temp == 1 || temp == 2) ans = 2;
        else if (temp == 3) ans = 1;
        else ans = 0;
        cout << ans << '\n';
    }
    return 0;
}
