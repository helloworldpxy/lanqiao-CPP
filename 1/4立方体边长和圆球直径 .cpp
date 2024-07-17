#include <iostream>
#include <cmath> // 包含数学库，用于计算立方根
#include <iomanip> // 用于控制输出格式
//可用#include <bits/stdc++.h>
using namespace std;
int main() {
    double V;
    cin >> V;
    // 计算正方体的边长
    double a = cbrt(V);
    // 计算圆球的直径
    double d = 2 * cbrt(3 * V / (4 * M_PI));
    // 输出结果，保留小数点后3位
    cout << fixed << setprecision(3) << a << " " << d << endl;
    return 0;
}