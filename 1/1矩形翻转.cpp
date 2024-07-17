#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int a[N][N];
int main() {
    int n; // 矩阵的大小
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    // 按对角线反转
    for (int i = 1; i <= n - 1; ++i) {
        for (int j = 1; j <= n - i; ++j) {
            swap(a[i][j], a[n - j + 1][n - i + 1]);
        }
    }
    // 按中心水平线反转
    for (int i = 1; i <= n / 2; ++i) {
        for (int j = 1; j <= n; ++j) {
            swap(a[i][j], a[n - i + 1][j]);
        }
    }
    // 输出翻转后的矩阵
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}