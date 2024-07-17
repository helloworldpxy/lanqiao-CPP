#include <bits/stdc++.h>
using namespace std;
int cnt;
void func(int n) {
    for (int i = 1; i <= n / 2; i++) {
        cnt++;
        func(i);
    }
}
int main() {
    int n;
    if (!(cin >> n) || n <= 0) {
        cerr << "输入错误，请输入一个正整数。" << endl;
        return 1;
    }
    cnt = 1;
    func(n);
    cout << cnt << endl;
    return 0;
}
