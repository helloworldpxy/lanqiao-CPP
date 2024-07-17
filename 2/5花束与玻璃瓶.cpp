#include <iostream>
using namespace std;
int main() {
    int T; // 组数
    cin >> T;

    while (T--) {
        int X, Y; // 花束数量和已有玻璃瓶数量
        cin >> X >> Y;

        // 计算至少需要购买的新玻璃瓶数
        int newBottles = max(0, X - Y);
        cout << newBottles << endl;
    }

    return 0;
}
