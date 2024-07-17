#include <iostream>
#include <map>
#include <string>
using namespace std;

int n; // 存储操作次数
string operation, author, bookname; // 分别存储操作类型、作者名和书名
map<string, int> mymap; // 使用map存储作者与对应书籍数量的关系

int main()
{
    // 禁用stdio同步，提高输入输出效率
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 输入操作次数n
    cin >> n;

    // 遍历n次操作
    while (n--) {
        // 输入当前操作类型
        cin >> operation;

        // 根据操作类型进行处理
        if (operation == "find") {
            // 输入要查找的作者
            cin >> author;
            
            // 输出该作者对应的书籍数量（若不存在则为0）
            cout << mymap[author] << '\n';
        } else if (operation == "add") {
            // 输入书名和作者名
            cin >> bookname >> author;

            // 对应作者的书籍数量加1
            mymap[author]++;
        }
    }

    
    return 0;
}
