#include <bits/stdc++.h>
using namespace std;
int main() {
    string ch;
    int a[200005], b[333005],n, k1 = 0, k2 = 0;
    long long ans = 0;
    cin >> n;
    cin.ignore();
    getline(cin, ch);
    size_t pos = 0;
    while((pos = ch.find("Alice", pos)) != string::npos){
        a[++k1] = pos;
        pos += 5;
    }
    pos = 0;
    while((pos = ch.find("Bob", pos)) != string::npos){
        b[++k2] = pos;
        pos += 3;
    }
    for(int i = 1, l = 1, r = 1; i <= k1; i++){
        while(l <= k2 && b[l] < a[i] - n - 3) l++;
        while(r <= k2 && b[r] <= a[i] + n + 5) r++;
        ans += r - l;
    }
    cout << ans;
    return 0;
}
